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
	void insert(int v)
	{
		if (root == NULL){ root = createNode(v); return ;}
		Node *t = root;
		while (t->son[v>=t->v]) t=t->son[v>=t->v];
		t->son[v>=t->v] =  createNode(v,t);
		splay(t,NULL);
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
	int solve(int x)
	{
		Node *t = root;
		if (!t) return x;
		int ans = abs(t->v - x);
		while (t){
			ans = std::min(ans,abs(t->v-x));
			t = t->son[x>=t->v];
		}
		return ans;
	}
}splay;
int a[maxn];
int main()
{
	int n,t;
	scanf("%d",&n);
	ll ans = 0;
	for (int i = 0;i < n;++i){
		scanf("%d",&t);
		ans += splay.solve(t);
		splay.insert(t);
	}
	printf("%lld\n",ans);
	return 0;
}
