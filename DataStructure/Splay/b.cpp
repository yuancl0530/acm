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
	int v,size;
	Node *son[2],*father;
}node[maxn],*stk[maxn];
int id,top;
Node *createNode(int v=0,Node *f=NULL){
	Node *t;
	if (top>=0) t = stk[top--];
	else t = &node[++id];
	t->v = v;
	t->father = f;
	t->size = 1;
	t->son[0] = t->son[1] = NULL;
	return t;
}
void freeNode(Node *t) { stk[++top] = t; } 

class Splay
{
private:
	Node *root;
	bool son(Node *f,Node *s);
	int size(Node *x);
	void update_size(Node *x);
	void rotate(Node *x);
	void splay(Node *x,Node *y);
public:
	Splay();
	void clear();
	bool empty();
	void insert(int v);
	void insert(int x,int v);
	void erase(int v);
	void join(Splay &s);
	void vis(Node *p);
	inline Node* Root();
	int find(int v);
	Node* min();
	Node* kth(int k,Node *p);
	Node* max();
	Node* next(Node *x);
	Node* pre(Node *x);
}splay;
int a[maxn],cnt;
int main()
{
	int n;
	int x,y;
	while (scanf("%d",&n) != EOF){
		splay.clear();
		splay.insert(1);
		cnt = 0;
		while (n--){
			scanf("%d%d",&x,&y);
			splay.insert(x+1,y);
		}
		splay.vis(splay.Root());
		for (int i = 1;i < cnt;++i)
			printf("%d ",a[i]);
		printf("\n");
	}
	return 0;
}	
bool Splay::son(Node *f,Node *s) { return f->son[1] == s;}
int Splay::size(Node *x){return x? x->size:0;}
void Splay::update_size(Node *x){x->size = 1+size(x->son[0])+size(x->son[1]);}
void Splay::rotate(Node *x)
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
void Splay::splay(Node *x,Node *y)
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
Splay::Splay(){ id=top=-1,root = NULL;}
void Splay::clear(){id=top=-1,root=NULL;}
bool Splay::empty() {return root == NULL;}
inline Node* Splay::Root(){return root;}
void Splay::insert(int v)
{
	if (root == NULL){ root = createNode(v); return ;}
	for (Node *t=root;t;t=t->son[v>=t->v]){
		if (t->v == v) { splay(t,NULL); return;}
		if (t->son[v>=t->v]==NULL)	t->son[v>=t->v] = createNode(v,t);
	}
}
void Splay::insert(int x,int v)
{
	insert(x,createNode(v));
}
void Splay::erase(int v)
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
Node* Splay::kth(int k,Node *p)
{
	if (k <= size(p->son[0])) return kth(k,p->son[0]);
	int t = size(p->son[0])+1;
	if (k > t) return kth(k-t,p->son[1]);
	splay(p,NULL);
	return p;
}
int Splay::find(int v)
{
	Node *p = root;
	while (p && p->v!=v) p=p->son[v>=p->v];
	if (!p) return -1;
	splay(p,NULL);
	return size(p->son[0])+1;
}
Node* Splay::min()
{
	Node *p = root;
	while (p && p->son[0]) p = p->son[0];
	if (p) splay(p,NULL);
	return p;
}
Node* Splay::max()
{
	Node *p = root;
	while (p && p->son[1]) p = p->son[1];
	if (p) splay(p,NULL);
	return p;
}
Node* Splay::next(Node *x)
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
Node* Splay::pre(Node *x)
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
void Splay::join(Splay &s)
{
	Node *root = max();
	root->son[1] = s.root;
	s.root->father = root;
	update_size(root);
}
void Splay::vis(Node *p)
{
	if (p->son[0]) vis(p->son[0]);
	a[cnt++] = p->v;
	if (p->son[1]) vis(p->son[1]);
}
