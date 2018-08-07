/*********************************
Date: Tue Aug  7 10:10:48 CST 2018
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
	Node *left,*right;
	int sum;
	void init(Node *l = NULL,Node *r = NULL,int s = 0)
	{
		left = l;
		right = r;
		s = s;
	}
}node[20*maxn],*cur[maxn],*root[maxn];
int a[maxn],b[maxn],num[maxn];
struct Q
{
	char c;
	int l,r,v;
}q[maxn];
int main()
{
	int T,n,m;
	scanf("%d",&T);
	while (T--){
		scanf("%d%d",&n,&m);
		int cnt = 0;
		for (int i = 1;i <= n;++i){
			scanf("%d",&a[i]);
			b[cn++] = a[i];
		}
		char op[2];
		for (int i = 0;i < m;++i){
			scanf("%s%d%d",op,q[i].l,q[i].r);
			if ((q[i].c=op[0]) == 'Q'){
				scanf("%d",&q[i].v);
				b[cnt++] = q[i].v;
			}
		}
		sort(b+1,b+1+cnt);
		cnt = unique(b+1,b+1+cnt) - b;
		for (int i = 1;i <= n;++i) 
			num[i] = lower_bound(b+1,b+cnt,a[i]) - b;

	}
	return 0;
}
