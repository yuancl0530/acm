/*********************************
Date: Fri Mar 30 15:10:45 CST 2018
Author: ycl
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
#include <set>
#include <sstream>
using namespace std;
#define CL(a) memset(a,0,sizeof(a))
#define Cl(a,b) memset(a,b,sizeof(a))
#define MP(a,b) make_pair(a,b)
#define INF 0x7fffffff
#define LL long long
#define N 10
const int mod = 1e9 + 7;
const int maxn = 1e6 + 100;
struct Node 
{
	Node *next[N];
	int count;
	Node()
	{
		CL(next);
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
	p->count=1;
}
int f=0;
void dfs(Node *root,int pos=0,int t=0)
{
	if (t>=2 || f) return ;
	if (!s[pos]){
		if (root->count && t==1){
			f=1;
		}
		return ;
	}
	int id=s[pos]-'a';
	if (root->next[id]){
		dfs(root->next[id],pos+1,t);
	}
	for (int i=0;i<3;++i){
		if (i!=id && root->next[i]){
			dfs(root->next[i],pos+1,t+1);
		}
	}
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	Node * root=new Node();
	for (int i=0;i<n;++i){
		scanf("%s",s);
		insert(s,root);
	}
	for (int i=0;i<m;++i){
		scanf("%s",s);
		f=0;
		dfs(root);
		if (f){
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
	}
	return 0;
}
