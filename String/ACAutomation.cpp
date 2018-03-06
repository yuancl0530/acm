/*********************************
Date: Wed Sep  6 13:26:23 CST 2017
*********************************/
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>
#include <cctype>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <vector>
#include <list>
#include <set>
#include <sstream>
using namespace std;
#define CL(a) memset(a,0,sizeof(a))
#define Cl(a,b) memset(a,b,sizeof(a))
#define MP(a,b) make_pair(a,b)
#define INF 0x7fffffff
#define LL long long
const int MOD = 1e9 + 7;
const int maxn = 1e6 + 100;
const int N=26;
struct Node 
{
	Node *next[N];
	Node *fail;
	int count;
	Node()
	{
		CL(next);
		fail=NULL;
		count =0;
	}
}*q[maxn];
char s[maxn];
void insert(char *s,Node *root)
{
	Node *p=root;
	for (int i=0;s[i];++i){
		int id=s[i]-'a';
		if (p->next[id]==NULL){
			p->next[id]=new Node();
		}
		p=p->next[id];
	}
	p->count++;
}
void build(Node *root)
{
	int head=0;
	int tail=0;
	root->fail=NULL;
	q[tail++]=root;
	Node *p,*t;
	while (head<tail){
		p=q[head++];
		for (int i=0;i<N;++i){
			if (p->next[i]){
				q[tail++]=p->next[i];
				if (p==root)
					p->next[i]->fail=root;
				else{
					t=p->fail;
					while (t){
						if (t->next[i]){
							p->next[i]->fail=t->next[i];
							break;
						}
						t=t->fail;
					}
					if (!t)
						p->next[i]->fail=root;
				}
			
			}
			
		}
	
	}
}
int query(char *s,Node *root)
{
	Node *p=root;
	Node *t;
	int ans=0;
	for (int i=0;s[i];++i){
		int id=s[i]-'a';
		while (p!=root && p->next[id]==NULL)
			p=p->fail;
		p=p->next[id];
		if (!p)p=root;
		t=p;
		while (t!=root && t->count!=-1){
			ans+=t->count;
			t->count=-1;
			t=t->fail;
		}
	}
	return ans;
}
int main()
{
	int T;
	scanf("%d",&T);
	while (T--){
		int n;
		Node *root=new Node();
		scanf("%d",&n);
		while (n--){
			scanf("%s",s);
			insert(s,root);
		}
		build(root);
		scanf("%s",s);
		int ans=query(s,root);
		printf("%d\n",ans);
	}


	return 0;
}