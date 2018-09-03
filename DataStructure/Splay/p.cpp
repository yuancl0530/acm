/*********************************
Date: Tue Jul 31 15:46:19 CST 2018
Author: ycl
*********************************/
#include <iostream>
#include <cstdio>
using namespace std;
#define CL(a) memset(a,0,sizeof(a))
#define Cl(a,b) memset(a,(b),sizeof(a))
#define MP(a,b) make_pair(a,b)
#define INF 0x3f3f3f3f
#define ll long long
const int mod = 1e9 + 7;
const int maxn = 1e5 + 100;
struct Node
{
	int v,size;
	ll sum,lazy;
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
	t->sum = 0;
	t->lazy = 0;
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
	ll sum(Node *x)
	{
		if (!x) return 0;
		return x->sum + x->lazy*x->size + x->v;
	}
	void push_up(Node *x)
	{	
		x->size = 1+size(x->son[0])+size(x->son[1]);
		x->sum = sum(x->son[0]) + sum(x->son[1]);
	}
	void push_down(Node *x)
	{
		if (x->reverse){
			if (x->son[0]) x->son[0]->reverse ^= 1;
			if (x->son[1]) x->son[1]->reverse ^= 1;
			swap(x->son[0],x->son[1]);
			x->reverse = false;
		}
		if (x->lazy){
			if (x->son[0]) x->son[0]->lazy += x->lazy;
			if (x->son[1]) x->son[1]->lazy += x->lazy;
			x->v += x->lazy;
			x->lazy = 0;
		}
	}
	void rotate(Node *x)
	{
		Node *f = x->father;
		Node *g = f->father;
		int a = son(f,x);
		int b = !a;
		push_down(f);
		push_down(x);
		f->son[a] = x->son[b];
		if (x->son[b]) x->son[b]->father = f;
		x->son[b] = f;
		f->father = x;
		x->father = g;
		if (g) g->son[son(g,f)] = x;
		else root = x;
		push_up(f);
		push_up(x);
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
		push_up(x);
	}
public:
	Splay(){ id=top=-1,root = NULL;}
	//void clear(){id=top=-1,root=NULL;}
	bool empty() {return root == NULL;}
	inline Node *Root(){return root;}

	Node *build(int l,int r,int *a,Node *f=NULL)
	{
		if (l>r) return NULL;
		int mid = (l+r)>>1;
		Node *t = createNode(a[mid],f);
		t->son[0] = build(l,mid-1,a,t);
		t->son[1] = build(mid+1,r,a,t);
		push_up(t);
		return t;
	}
	void init(int l,int r,int *a) {root = build(l,r,a,NULL);}

	Node* kth(int k,Node *p=NULL)
	{
		if (k <= size(p->son[0])) return kth(k,p->son[0]);
		int t = size(p->son[0])+1;
		if (k > t) return kth(k-t,p->son[1]);
		splay(p,NULL);
		return p;
	}
	Node *min(Node *p=NULL)
	{
		if (!p) p = root;
		while (p && p->son[0]) p = p->son[0];
		return p;
	}
	Node *max(Node *p=NULL)
	{
		if (!p) p = root;
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
	Node *select(int l,int r)
	{
		Node *x = kth(l,root);
		Node *y = kth(r,root);
		Node *p = pre(x);
		splay(p,NULL);
		Node *t = next(y);
		splay(t,root);
		return t->son[0];
	}
	void update(int l,int r,int v)
	{
		Node *x = select(l+1,r+1);
		x->lazy += v;
		splay(x,NULL);
	}
	ll query(int l,int r)
	{
		Node *x = select(l+1,r+1);
		ll tmp = sum(x);
		splay(x,NULL);
		return tmp;
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
	int n,m,l,r,x;
	char op[2];
	scanf("%d%d",&n,&m);
	for (int i = 1;i <= n;++i)
		scanf("%d",&a[i]);
	splay.init(0,n+1,a);
	while (m--){
		scanf("%s%d%d",op,&l,&r);
		if (op[0]=='Q')
			printf("%lld\n",splay.query(l,r));
		else{
			scanf("%d",&x);
			splay.update(l,r,x);
		}
	}
	return 0;
}
