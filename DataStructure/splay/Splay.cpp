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
	bool reverse;
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
	t->reverse = false;
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
	void push_up(Node *x);
	void push_down(Node *x);
	void rotate(Node *x);
	void splay(Node *x,Node *y = NULL);
public:
	Splay();
	inline Node* Root();
	void clear();
	void init(int l,int r,int *a);
	void insert(int x,int v);  
	void insert(int x,int *a,int n);
	void insert(int x,Node *y);
	void erase(int l,int r);
	void vis(Node *p);
	bool empty();
	Node* build(int l,int r,int *a,Node *f=NULL);
	Node* kth(int k,Node *p);
	Node* min(Node *p=NULL);
	Node* max(Node *p=NULL);
	Node* next(Node *x);
	Node* pre(Node *x);
	Node* select(int l,int r);
	Node* reverse(int l,int r);
}splay;
int main()
{
	return 0;
}

bool Splay::son(Node *f,Node *s) { return f->son[1] == s;}
int Splay::size(Node *x){return x? x->size:0;}
void Splay::push_up(Node *x)
{	
	x->size = 1+size(x->son[0])+size(x->son[1]);
}
void Splay::push_down(Node *x)
{
	if (x->reverse){
		if (x->son[0]) x->son[0]->reverse ^= 1;
		if (x->son[1]) x->son[1]->reverse ^= 1;
		swap(x->son[0],x->son[1]);
		x->reverse = false;
	}
}
void Splay::rotate(Node *x)
{
	Node *f = x->father;
	Node *g = f->father;
	push_down(f);
	push_down(x);
	int a = son(f,x);
	int b = !a;
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
	//push_up(x);
}
Splay::Splay(){ id=top=-1,root = NULL;}
void Splay::clear(){id=top=-1,root=NULL;}
bool Splay::empty() {return root == NULL;}
inline Node* Splay::Root(){return root;}
Node* Splay::build(int l,int r,int *a,Node *f)
{
	if (l>r) return NULL;
	int mid = (l+r)>>1;
	Node *t = createNode(a[mid],f);
	t->son[0] = build(l,mid-1,a,t);
	t->son[1] = build(mid+1,r,a,t);
	push_up(t);
	return t;
}
void Splay::init(int l,int r,int *a) {root = build(l,r,a,NULL);}
Node* Splay::kth(int k,Node *p)
{
	push_down(p);
	if (k <= size(p->son[0])) return kth(k,p->son[0]);
	int t = size(p->son[0])+1;
	if (k > t) return kth(k-t,p->son[1]);
	splay(p,NULL);
	return p;
}

void Splay::insert(int x,int v) //在第x个位置后面插入a
{
	Node *p = kth(x,root);
	push_down(p);
	if (!p->son[1]) {
		p->son[1] = createNode(v,p);
		p = p->son[1];
	}
	else{
		p = p->son[1];
		push_down(p);
		while (p->son[0]){
			p = p->son[0];
			push_down(p);
		}
		p->son[0] = createNode(v,p);
		p = p->son[0];
	}
	splay(p,NULL);
}
void Splay::insert(int x,int *a,int n)
{
	Node *p = kth(x,root);
	push_down(p);
	if (!p->son[1]) {
		p->son[1] = build(1,n,a);
		p->son[1]->father = p;
		p = p->son[1];
	}
	else{
		p = p->son[1];
		push_down(p);
		while (p->son[0]){
			p = p->son[0];
			push_down(p);
		}
		p->son[0] = build(1,n,a);
		p->son[0]->father = p;
		p = p->son[0];
	}
	splay(p,NULL);
}
void Splay::insert(int x,Node *y)
{
	Node* p = kth(x,root);
	push_down(p);
	if (!p->son[1]){
		p->son[1] = y;
		y->father = p;
		p = p->son[1];
	}
	else{
		p = p->son[1];
		push_down(p);
		while (p->son[0]){
			p = p->son[0];
			push_down(p);
		}
		p->son[0] = y;
		y->father = p;
		p = p->son[0];
	}
	splay(p,NULL);
}
Node* Splay::min(Node *p)
{
	if (!p) p = root;
	push_down(p);
	while (p && p->son[0]) {
		p = p->son[0];
		push_down(p);
	}
	return p;
}
Node* Splay::max(Node *p)
{
	if (!p) p = root;
	push_down(p);
	while (p && p->son[1]){
		p = p->son[1];
		push_down(p);
	}
	return p;
}
Node* Splay::next(Node *x)
{
	push_down(x);
	if (x->son[1]){
		x = x->son[1];
		push_down(x);
		while (x->son[0]){
			x = x->son[0];
			push_down(x);
		}
		return x;
	}
	Node *y = x->father;
	while (y && son(y,x)){ x = y;  y = x->father; }
	return y;
}
Node* Splay::pre(Node *x)
{
	push_down(x);
	if (x->son[0]){
		x = x->son[0];
		push_down(x);
		while (x->son[1]) {
			x = x->son[1];
			push_down(x);
		}
		return x;
	}
	Node *y = x->father;
	while (y && !son(y,x)){ x = y; y = x->father; }
	return y;
}
Node* Splay::select(int l,int r)
{
	Node *x = kth(l,root);
	Node *y = kth(r,root);
	Node *p = pre(x);
	splay(p,NULL);
	Node *t = next(y);
	splay(t,root);
	return t->son[0];
}
Node* Splay::reverse(int l,int r)
{
	Node *x = select(l,r);
	x->reverse ^= 1;
	return x;
}
void Splay::vis(Node *p)
{
	push_down(p);
	if (p->son[0]) {
		vis(p->son[0]);
	}
	printf("%d ",p->v);
	if (p->son[1]) {
		vis(p->son[1]);
	}
}
void Splay::erase(int l,int r)
{
	Node* x = select(l,r);
	Node* f = x->father;
	f->son[son(f,x)] = NULL;
	splay(f,NULL);
}
