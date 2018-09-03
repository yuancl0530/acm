#include <bits/stdc++.h>
using namespace std;
#define CL(a) memset(a,0,sizeof(a))
#define Cl(a,b) memset(a,(b),sizeof(a))
#define MP(a,b) make_pair(a,b)
#define INF 0x3f3f3f3f
#define ll long long
const int mod = 1e9 + 7;
const int maxn = 5e6 + 100;
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
	void push_up(Node *x);
	void push_down(Node *x);
	void rotate(Node *x);
	void splay(Node *x,Node *y = NULL);
	Node *cur;
public:
	Splay();
	int size(Node *x);
	inline Node* Root();
	void clear();
	void init(int l,int r,int *a);
	void insert(int x,int v); //在第x个位置后面插入a
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
	void move(int k)
	{
		cur = kth(k,root);
	}
	void insert(int n,int *a)
	{
		int k = size(cur->son[0]) + 1;
		insert(k,a,n);
		splay(cur,NULL);
	}
	void del(int n)
	{
		int k = size(cur->son[0]) + 1;
		erase(k+1,k+n);
		splay(cur,NULL);
	}
	void rota(int n)
	{
		int k = size(cur->son[0]) + 1;
		reverse(k+1,k+n);
		splay(cur,NULL);
	}
	char get()
	{
		return next(cur)->v;
	}
	void pr()
	{
		cur = pre(cur);
		splay(cur,NULL);
	}
	void nex()
	{
		cur = next(cur);
		splay(cur,NULL);
	}
}splay;
int a[maxn];
char s[maxn];
int main()
{
	int n;
	//freopen("in","r",stdin);
	scanf("%d",&n);
	splay.init(0,1,a);
	char op[10];
	int k;
	while (n--){
		scanf("%s",op);
		if (op[0] == 'M'){
			scanf("%d",&k);
			splay.move(k+1);
		}
		else if (op[0] == 'I'){
			scanf("%d",&k);
			getchar();
			cin.getline(s,maxn);
			//cout<<s<<endl;
			for (int i = 0;i < k;++i) a[i] = s[i];
			splay.insert(k,a);
		}
		else if (op[0] == 'D'){
			scanf("%d",&k);
			splay.del(k);
		}
		else if (op[0] == 'R'){
			scanf("%d",&k);
			splay.rota(k);
		}
		else if (op[0] == 'G'){
			printf("%c\n",splay.get());
		}
		else if (op[0] == 'P') splay.pr();
		else splay.nex();
		/*splay.vis(splay.Root());
		printf("\n%d\n",splay.size(splay.Root()));*/
	}
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
void Splay::init(int l,int r,int *a) {root = build(l,r,a,NULL); cur = min();}
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
	insert(x,build(0,n-1,a));
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
	printf("%c ",p->v);
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
