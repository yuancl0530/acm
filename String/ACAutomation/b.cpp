/*********************************
Date: Sat Jul 28 15:39:03 CST 2018
Author: ycl
*********************************/
#include <iostream>
#include <cstdio>
#include <cstring>
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
	int id;
	Node *fail;
	Node *next[N];
}node[maxn],*q[maxn];
int Id = 0;
int cnt[maxn];
int getid(char s)
{
	if ('A'<=s && s<= 'Z') return s-'A';
	return -1;
}
Node *createNode()
{
	node[Id].fail = NULL;
	node[Id].id = 0;
	CL(node[Id].next);
	return &node[Id++];
}
void insert(Node *root,char *s,int id)
{
	Node * t= root;
	for (int i = 0;s[i];++i){
		int id = getid(s[i]);
		if (!t->next[id])
			t->next[id] = createNode();
		t = t->next[id];
	}
	t->id = id;
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
void query(Node *root,char *s)
{
	
	Node *p,*t;
	p = root;
	for (int i = 0;s[i];++i){
		int id = getid(s[i]);
		if (id==-1) {p=root; continue;}
		while (p != root && p->next[id]==NULL) p = p->fail;
		p = p->next[id];
		if (!p) p = root;
		t = p;
		while (t != root ){
			++cnt[t->id];
			t = t->fail;
		}
	}
}
char s[1010][60],t[maxn];
int main()
{
	int n;
	while (scanf("%d",&n) != EOF){
		Id = 0;
		for (int i = 1;i <= n;++i) cnt[i] = 0;
		Node *root = createNode();
		for (int i = 1;i <= n;++i){
			scanf("%s",s[i]);
			insert(root,s[i],i);
		}
		buid(root);
		scanf("%s",t);
		query(root,t);
		for (int i = 1;i <= n;++i)
			if (cnt[i])
				printf("%s: %d\n",s[i],cnt[i]);
	}
	return 0;
}
