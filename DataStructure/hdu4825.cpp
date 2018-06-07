/*********************************
Date: Thu May 17 11:07:15 CST 2018
Author: ycl
*********************************/
#include <bits/stdc++.h>
using namespace std;
#define CL(a) memset(a,0,sizeof(a))
#define Cl(a,b) memset(a,b,sizeof(a))
#define MP(a,b) make_pair(a,b)
#define INF 0x7fffffff
#define ll long long
const int mod = 1e9 + 7;
const int maxn = 1e5 + 100;
struct Node
{
	Node *next[2];
}node[maxn*32];
int cnt;
Node *init()
{
	memset(node,0,sizeof(node));
	cnt = 0;
	return &node[cnt++];
}
void insert(Node *p,ll v)
{
	for (int i = 32;i >= 0;--i){
		int t = (bool)(v & (1ll<<i));
		if (!p->next[t]) p->next[t] = &node[cnt++];
		p = p->next[t];
	}
}
int query(Node *p,ll m)
{
	int ans = 0;
	for (int i = 32;i >= 0;--i){
		int t = (bool)(m&(1ll<<i));
		t ^= 1;
		if (p->next[t]){
			ans = (ans<<1) + t;
			p = p->next[t];
		}
		else{
			ans = (ans<<1) + (t^1);
			p = p->next[t^1];
		}
	}
	return ans;
}
int main()
{
	int T,n,m,t;
	int kase = 0;
	scanf("%d",&T);
	while (T--){
		scanf("%d%d",&n,&m);
		Node *root = init();
		for (int i = 1;i <= n;++i){
			scanf("%d",&t);
			insert(root,t);
		}
		printf("Case #%d:\n",++kase);
		int s;
		while (m--){
			scanf("%d",&s);
			printf("%d\n",query(root,s));
		}
	}
	return 0;
}
