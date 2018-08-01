/*********************************
Date: Tue Jul 31 14:58:03 CST 2018
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
	int v;
	Node *father;
	Node *son[2];
	Node (int v=0,Node *f=NULL):v(v),father(f)
	{
		son[0] = son[1] = NULL;
	}
};
inline bool son(Node *f,Node *s)
{
	return f->son[1] == s;
}
void rotate(Node *t)
{
	Node *f = t->father;
	Node *g = f->father;
	bool a = son(f,t);
	bool b = !a;
	f->son[a] = t->son[b];
	if (t->son[b] != NULL)
		t->son[b]->father = f;
	t->son[b] = f;
	f->father = t;
	t->father = g;
	if (g != NULL)
		g->son[son(g,f)] = t;
	else
		root = t;
}
void splay(Node *t,Node *p)
{
	while (t->father != p){
		Node *f = t->father;
		Node *g = f->father;
		if (g == p)
			rotate(t);
		else{
			if (son(f,t) ^ son(g,f)){
				rotate(t);
				rotate(t);
			}
			else{
				
			}
		}
	}
}
bool insert(int v)
{
	if (root == NULL)
		root = new Node(v);
	for (Node *t = root;t;t = t->son[v >= t->v]){
		if (t->v == v){splay(t,NULL); return ;}
		if (t->son[v>=t->v] == NULL)
			r->son[v>=t->v] = new Node(v);
	}
}
void erase(int v)
{
	Node *t = root;
	while (t){
		if (t->v == v) break;
		t = t->son(v>t->v);
	}
	if (!t) return ;
	splay(t,NULL);
	if (t->som[0]==NULL){
		root = t->son[1];
		if (!root) root->father = NULL;
	}
	else{
		Node *p = root->son[0];
		while (p->son[1]) p = p->son[1];
		splay(p,t);
		root = p;
		roo->father = NULL;
		root->son[1] = t->son[1];
		if (root->son[1]) root->son[1]->father = root;
	}
}
int main()
{

	return 0;
}
