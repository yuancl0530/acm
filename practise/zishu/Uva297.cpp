/*********************************
Date: Wed Apr 11 17:15:12 CST 2018
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
const int mod = 1e9 + 7;
const int maxn = 1e6 + 100;
char s[maxn];
int node[maxn];
int id=0;
struct Node
{
	int v;
	Node *next[4];
	Node(int v=0):v(v)
	{
		CL(next);
	}
};
void build(Node *u,int v=1024)
{
	if (!s[id]) return ;
	if (s[id]=='p'){
		++id;
		for (int i=0;i<4;++i){
			if (!u->next[i]){
				u->next[i]=new Node();
			}
			build(u->next[i],v/4);
		}
	}
	else if (s[id]=='e'){
		++id;
		return;
	}
	else if (s[id]=='f'){
		++id;
		u->v=v;
	}
}
void clear(Node *u)
{
	for (int i=0;i<4;++i){
		if (u->next[i])
			clear(u->next[i]);
	}
	delete u;
}
int ans;
void dfs(Node *u)
{
	if (u->v){
		ans+=u->v;
		return ;
	}
	for (int i=0;i<4;++i){
		if (u->next[i]){
			dfs(u->next[i]);
		}
	}
}
int main()
{
	int T;
	scanf("%d",&T);
	Node * root=NULL;
	while (T--){
		ans=0;
		CL(node);
		root=new Node();
		scanf("%s",s);
		id=0;
		build(root);
		id=0;
		scanf("%s",s);
		build(root);
		dfs(root);
		printf("There are %d black pixels.\n",ans);
		clear(root);
	}
	return 0;
}
