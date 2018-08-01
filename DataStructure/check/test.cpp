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
	bool reverse;
	Node *son[2],*father;
}node[maxn],*stk[maxn];
class Splay
{
private:
	Node *root;
	int id,top;
	bool _son(Node *f,Node *s) { return f->son[1] == s;}
	Node *createNode(int v=0,Node *f=NULL){
		Node *t;
		//if (top>=0) t = stk[--top];
		t = &node[++id];
		t->v = v;
		t->father = f;
		t->size = 1;
		t->reverse = false;
		t->son[0] = t->son[1] = NULL;
		return t;
	}
	void freeNode(Node *t) { stk[++top] = t; } 
	int _size(Node *x){return x? x->size:0;}
	void update_size(Node *x){x->size = 1+_size(x->son[0])+_size(x->son[1]);}
	void rotate(Node *x)
	{
		Node *f = x->father;
		Node *g = f->father;
//		cout<<f->son[0]<<" "<<f->son[1]<<endl;
		int a = _son(f,x);
		int b = !a;
		f->son[a] = x->son[b];
		if (x->son[b]) x->son[b]->father = f;
		x->son[b] = f;
		f->father = x;
		x->father = g;
		if (g) g->son[_son(g,f)] = x;
		else root = x;
		update_size(f);/*
		cout<<"g:"<<g<<endl;
		cout<<"x->father"<<x->father<<"x->son[0]"<<x->son[0]<<"x->son[1]"<<x->son[1]<<endl;
		cout<<"f->father"<<f->father<<"f->son[0]"<<f->son[0]<<"f->son[1]"<<f->son[1]<<endl;*/
	}
	void splay(Node *x,Node *y)
	{
		while (x->father != y){
			Node *f = x->father;
			Node *g = f->father;
			if (g == y) {rotate(x);}
			else {
				if (_son(f,x) ^ _son(g,f)) rotate(x),rotate(x);
				else rotate(f),rotate(x);
			}
		}
		update_size(x);
	}
public:
	Splay(){ id=top=-1,root = NULL;}
	Node *Root(){return root;}
	void insert(int v)
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
		while (t){
			if (t->v == v) break;
			t = t->son[v>=t->v];
		}
		if (!t) return ;
		splay(t,NULL);
		if (root->son[0]==NULL){
			root = root->son[1];
			if (root) root->father = NULL;
		}
		else {
			Node *p = root->son[0];
			while (p->son[1]) p = p->son[0];
			splay(p,root);
			root = p;
			root->father = NULL;
			root->son[1] = t->son[1];
			if (root->son[1]) root->son[1] = root;
		}
		freeNode(t);
	}
	int kth(int k,Node *p=NULL)
	{
		if (k<=_size(p->son[0])) return kth(k,p->son[0]);
		int t = _size(p->son[0])+1;
		if (k > t) return kth(k-t,p->son[1]);
		splay(p,NULL);
		return p->v;
	}
	void vis(Node *p)
	{
		if (p->son[0]) {
			cout<<p->v<<"->"<<p->son[0]->v<<endl;
			vis(p->son[0]);
		}
		cout << p->v <<"("<<p->size<<")"<<endl;
		if (p->son[1]) {
			cout<<p->v<<"->"<<p->son[1]->v<<endl;
			vis(p->son[1]);
		}
	}
}splay;
int main()
{
	int n,t;
	scanf("%d",&n);
	for (int i = 1;i <= n;++i){
		scanf("%d",&t);
		splay.insert(t);
	}
	cout << splay.kth(n/2,splay.Root()) <<endl;
	return 0;
}
