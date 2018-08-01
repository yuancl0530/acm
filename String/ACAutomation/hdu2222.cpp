/*********************************
Date: Sat Jul 28 15:39:03 CST 2018
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
#define N 26
struct Node
{
	int cnt;
	Node *fail;
	Node *next[N];
}node[maxn];
Node *q[maxn];
int Id = 0;
Node *createNode()
{
	node[Id].cnt = 0;
	node[Id].fail = NULL;
	CL(node[Id].next);
	return &node[Id++];
}
void insert(Node *root,char *s)
{
	Node * t= root;
	for (int i = 0;s[i];++i){
		int id = s[i] - 'a';
		if (!t->next[id])
			t->next[id] = createNode();
		t = t->next[id];
	}
	++t->cnt;
}
void buid(Node *root)
{
	int front = 0;
	int tail = 0;
	q[tail++] = root;
	Node *t,*p;
	while (front < tail){
		p = q[front++];
		for (int i = 0;i < N;++i){
			if (p->next[i] == NULL) continue;
			q[tail++] = p->next[i];
			t = p->fail;
			while (t && t->next[i] == NULL) t = t->fail;
			if (!t) p->next[i]->fail = root;
			else p->next[i]->fail = t->next[i];
		}
	}
}
int query(Node *root,char *s)
{
	
	Node *p,*t;
	p = root;
	int ret = 0;
	for (int i = 0;s[i];++i){
		int id = s[i] - 'a';
		while (p != root && p->next[id]==NULL) p = p->fail;
		p = p->next[id];
		if (!p) p = root;
		t = p;
		while (t != root && t->cnt != -1){
			ret += t->cnt;
			t->cnt = -1;
			t = t->fail;
		}
	}
	return ret;
}
char s[maxn];
int main()
{
	int T,n;
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n);
		Id = 0;
		Node *root = createNode();
		for (int i = 0;i < n;++i){
			scanf("%s",s);
			insert(root,s);
		}
		buid(root);
		scanf("%s",s);
		int ans = query(root,s);
		printf("%d\n",ans);
	}
	return 0;
}
