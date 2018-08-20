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
const int maxn = 1e6 + 100;
struct Node
{
	int v,size,k;
	Node *son[2],*father;
}node[maxn],*stk[maxn];
int id,top;
Node *createNode(int v=0,int k=0,Node *f=NULL){
	Node *t;
	if (top>=0) t = stk[top--];
	else t = &node[++id];
	t->v = v;
	t->father = f;
	t->k = k;
	t->size = 1;
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
	void update_size(Node *x){x->size = 1+size(x->son[0])+size(x->son[1]);}
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
	void splay(Node *x,Node *y)
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
public:
	Splay(){ id=top=-1,root = NULL;}
	//void clear(){id=top=-1,root=NULL;}
	bool empty() {return root == NULL;}
	inline Node *Root(){return root;}
	void insert(int v,int k)
	{
		if (root == NULL){ root = createNode(v,k); return ;}
		for (Node *t=root;t;t=t->son[v>=t->v]){
			if (t->v == v) { splay(t,NULL); return;}
			if (t->son[v>=t->v]==NULL)	t->son[v>=t->v] = createNode(v,k,t);
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
	}
	Node* kth(int k,Node *p=NULL)
	{
		if (k <= size(p->son[0])) return kth(k,p->son[0]);
		int t = size(p->son[0])+1;
		if (k > t) return kth(k-t,p->son[1]);
		splay(p,NULL);
		return p;
	}
	int find(int v)
	{
		Node *p = root;
		while (p && p->v!=v) p=p->son[v>=p->v];
		if (!p) return -1;
		splay(p,NULL);
		return size(p->son[0])+1;
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
		Node *p = root;
		while (p && p->son[1]) p = p->son[1];
		if (p) splay(p,NULL);
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
			while (x->son[1]) x = x->son[0];
			return x;
		}
		Node *y = x->father;
		while (y && !son(y,x)){
			x = y;
			y = x->father;
		}
		return y;
	}
	void join(Splay &s)
	{
		Node *root = max();
		root->son[1] = s.root;
		s.root->father = root;
		update_size(root);
	}
	void vis(Node *p)
	{
		if (p->son[0]) {
			cout<<"\t"<<p->v<<"->"<<p->son[0]->v<<endl;
			vis(p->son[0]);
		}
		cout << p->v <<"[label="<<p->v<<"."<<p->size<<"];"<<endl;
		if (p->son[1]) {
			cout<<"\t"<<p->v<<"->"<<p->son[1]->v<<endl;
			vis(p->son[1]);
		}
	}
	int hi()
	{
		Node *x = max();
		int ret = 0;
		if (x){
			ret = x->k;
			erase(x->v);
		}
		return ret;
	}
	int lo()
	{
		Node *x = min();
		int ret = 0;
		if (x){
			ret = x->k;
			erase(x->v);
		}
		return ret;
	}
}splay;

int main()
{
	int op;
	int k,p;
	while (scanf("%d",&op)!=EOF && op){
		if (op == 1){
			scanf("%d%d",&k,&p);
			splay.insert(p,k);
		}
		else if (op==2)
			printf("%d\n",splay.hi());
		else
			printf("%d\n",splay.lo());
	}
	return 0;
}
