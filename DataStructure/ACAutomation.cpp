/*********************************
Date: Fri Sep  1 10:03:51 CST 2017
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
char s[maxn];
char str[maxn];

struct Node
{
	Node *next[26];
	Node *fail;
	int count;
	Node ()
	{
		CL(next);
		fail=NULL;
		count=0;
	}
}*q[maxn];

void insert(char *s,Node *root)
{
	Node *p=root;
	for (int i=0;s[i];++i){
		int id=s[i]-'a';
		if (p->next[id]==NULL)
			p->next[id]=new Node();
		p=p->next[id];
	}
	p->count++;
}
void build(Node *root)
{
	int head=0;
	int tail=0;
	q[tail++]=root;
	while (head<tail){
		Node *p=q[head++];
		for (int i=0;i<26;++i){
			if (p->next[i]){
				if (p==root)
					p->next[i]->fail=root;
				else{
					Node *t=p->fail;
					while (t){
						if (t->next[i]){
							p->next[i]->fail=t->next[i];
							break;
						}
						t=t->fail;
					}
					if (!t)p->next[i]->fail=root;
				}
				q[tail++]=p->next[i];
			}
		}
	}
}
int query(char *str,Node *root)
{
	Node *p=root;
	int ans=0;
	for (int i=0;str[i];++i){
		int id=str[i]-'a';
		while (p->next[id]==NULL && p!=root)p=p->fail;
		p=p->next[id];
		if (!p)p=root;
		Node *t=p;
		while (t !=root && t->count!=-1){
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
		scanf("%d",&n);
		Node *root=new Node();
		while (n--){
			scanf("%s",s);
			insert(s,root);
		}
		scanf("%s",str);
		build(root);
		int ans=query(str,root);
		printf("%d\n",ans);
	}


	return 0;
}
