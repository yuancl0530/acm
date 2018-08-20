/*********************************
Date: Tue Jul 31 15:46:19 CST 2018
Author: ycl
*********************************/
#include <bits/stdc++.h>
using namespace std;
#define CL(a) memset(a,0,sizeof(a))
#define Cl(a,b) memset(a,(b),sizeof(a))
#define MP(a,b) make_pair(a,b)
#define INF 0x3f3f3f3f
#define ll long long
const int mod = 1e9 + 7;
const int maxn = 1e6 + 100;
struct Node
{
	int v,size;
	int max;
	bool reverse;
	Node *son[2],*father;
}node[maxn],*stk[maxn];
int id,top;

int a[maxn],cnt;

Node *createNode(int v=0,Node *f=NULL){
	Node *t;
	if (top>=0) t = stk[top--];
	else t = &node[++id];
	t->v = v;
	t->father = f;
	t->size = 1;
	t->reverse = false;
	t->son[0] = t->son[1] = NULL;
	return t;
}
void freeNode(Node *t) { stk[++top] = t; } 

class Splay
{
private:
	Node *root;
	bool son(Node *f,Node *s) { return f->son[1] == s;}
	int size(Node *x){return x? x->size:0;}
	void update_size(Node *x){
		x->size = 1+size(x->son[0])+size(x->son[1]);
		x->max = x->v;
		if (x->son[0]) x->max = std::max(x->max,x->son[0]->max);
		if (x->son[1]) x->max = std::max(x->max,x->son[1]->max);
	}
	void rotate(Node *x)
	{
		Node *f = x->father;
		Node *g = f->father;
		int a = son(f,x);
		int b = !a;
		f->son[a] = x->son[b];
		if (x->son[b]) x->son[b]->father = f;
		x->son[b] = f;
		f->father = x;
		x->father = g;
		if (g) g->son[son(g,f)] = x;
		else root = x;
		update_size(f);
	}
	void splay(Node *x,Node *y = NULL)
	{
		while (x->father != y){
			Node *f = x->father;
			Node *g = f->father;
			if (g == y) {rotate(x);}
			else {
				if (son(f,x) ^ son(g,f)) rotate(x),rotate(x);
				else rotate(f),rotate(x);
			}
		}
		update_size(x);
	}
	void push(Node *x)
	{
		if (!x->reverse) return ;
		if (x->son[0]) x->son[0]->reverse ^= 1;
		if (x->son[1]) x->son[1]->reverse ^= 1;
		swap(x->son[0],x->son[1]);
		x->reverse = false;
	}
public:
	Splay(){ id=top=-1,root = NULL;}
	void clear(){id=top=-1,root=NULL;}
	bool empty() {return root == NULL;}
	inline Node *Root(){return root;}

	Node *build(int l,int r,int *a,Node *f=NULL)
	{
		if (l>r) return NULL;
		int mid = (l+r)>>1;
		Node *t = createNode(a[mid],f);
		t->son[0] = build(l,mid-1,a,t);
		t->son[1] = build(mid+1,r,a,t);
		update_size(t);
		return t;
	}
	void init(int l,int r,int *a) {root = build(l,r,a,NULL);}

	/*void insert(int v)
	{
		if (root == NULL){ root = createNode(v); return ;}
		for (Node *t=root;t;t=t->son[v>=t->v]){
			if (t->v == v) { splay(t,NULL); return;}
			if (t->son[v>=t->v]==NULL)	t->son[v>=t->v] = createNode(v,t);
		}
	}
	void erase(int v)
	{
		Node *t = root;
		while (t && t->v != v)t = t->son[v>=t->v];
		if (!t) return ;                       
		splay(t,NULL);
		if (root->son[0]==NULL){
			root = root->son[1];
			if (root) root->father = NULL;
		}
		else {
			Node *p = root->son[0];
			while (p->son[1]) p = p->son[1];
			splay(p,root);
			root = p;
			root->father = NULL;
			root->son[1] = t->son[1];
			if (root->son[1]) root->son[1]->father = root;
		}
		freeNode(t);
	}*/

	Node* kth(int k,Node *p=NULL)
	{
		if (k <= size(p->son[0])) return kth(k,p->son[0]);
		int t = size(p->son[0])+1;
		if (k > t) return kth(k-t,p->son[1]);
		splay(p,NULL);
		return p;
	}
	Node *min()
	{
		Node *p = root;
		while (p && p->son[0]) p = p->son[0];
		if (p) splay(p,NULL);
		return p;
	}
	Node *max()
	{
		Node* p = root;
		while (p && p->son[1]) p = p->son[1];
		if (p) splay(p,NULL);
		return p;
	}
	Node *min(Node *p)
	{
		while (p && p->son[0]) p = p->son[0];
		return p;
	}
	Node *max(Node *p)
	{
		while (p && p->son[1]) p = p->son[1];
		return p;
	}
	Node *next(Node *x)
	{
		if (x->son[1]){
			x = x->son[1];
			while (x->son[0]) x = x->son[0];
			return x;
		}
		Node *y = x->father;
		while (y && son(y,x)){
			x = y;
			y = x->father;
		}
		return y;
	}
	Node *pre(Node *x)
	{
		if (x->son[0]){
			x = x->son[0];
			while (x->son[1]) x = x->son[1];
			return x;
		}
		Node *y = x->father;
		while (y && !son(y,x)){
			x = y;
			y = x->father;
		}
		return y;
	}
	void update(int x,int y)
	{
		Node *t = kth(x+1,root);
		t->v = y;
		update_size(t);
	}
	Node *select(int l,int r)
	{
		Node *x = kth(l,root);
		Node *y = kth(r,root);
		Node *p = pre(x);
		splay(p,NULL);
		Node *t = next(y);
		splay(t,root);
		//cout<<x->v<<" "<<y->v<<" "<<p->v<<" "<<t->v<<endl;
		return t->son[0];
	}
	int query(int l,int r)
	{
		Node *x = select(l+1,r+1);
		return x->max;
	}
	void vis(Node *p)
	{
		if (p->son[0]) {
			vis(p->son[0]);
		}
		a[cnt++] = p->v;
		if (p->son[1]) {
			vis(p->son[1]);
		}
	}
}splay;
int main()
{
	int n,m;
	while (scanf("%d%d",&n,&m) != EOF){
		for (int i = 1;i <= n;++i)
			scanf("%d",&a[i]);
		a[0] = -1;
		a[n+1] = -1;
		splay.clear();
		splay.init(0,n+1,a);
		char op[5];
		int x,y;
		while (m--){
			scanf("%s%d%d",op,&x,&y);
			if (op[0] == 'Q')
				printf("%d\n",splay.query(x,y));
			else
				splay.update(x,y);
		}
	}
	return 0;
}
