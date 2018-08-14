/*********************************
Date: Mon Aug 13 09:24:44 CST 2018
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
	int s;
	Node *next[2];
	Node (const Node &a)
	{
		s = a.s;
		next[0] = s.next[0];
		next[1] = s.next[1];
	}
}node[maxn],*root[maxn];
int id;
void init()
{
	id = 0;
	root[0] = node[id++];
	t->s = 0;
	t->next[0] = t->next[1] = root[0];
}
Node *insert(int v,Node *x)
{
	Node *root = &node[id++];
	*root = *x;
	Node *t = root;
	for (int i = 31;i >= 0;--i){
		int k = v>>i & 1;
		t->next[k] = &node[id++];
		*t->next[k] = *x->next[k];
		t = t->next[k];
		x = x->next[k];
		t->s ^= k;
	}
	return root;
}
int main()
{

	return 0;
}
