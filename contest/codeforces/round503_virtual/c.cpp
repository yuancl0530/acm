/*********************************
Date: Fri Aug 17 15:52:08 CST 2018
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
int cnt[maxn];
struct Node
{
	int p,int c;
	friend bool operator(Node a,Node b)
	{
		int c1 = a.c<<1;
		int c2 = b.c<<1;

	}
}a[maxn];
int main()
{
	int n,m;
	scanf("%d",&n,&m);
	for (int i = 1;i <= n;++i){
		scanf("%d%d",&a[i].p,&a[i].c);
		++cnt[a[i].p];
	}
	int c = c;
	for (int i = 2;i <= m;++i)
		c = cnt[c]>cnt[i]? c:i;
	if (cnt[1] >= c){
		printf("0\n");
		return ;
	}

	return 0;
}
