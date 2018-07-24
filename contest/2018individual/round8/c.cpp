/*********************************
Date: Fri May 25 16:02:22 CST 2018
Author: ycl
*********************************/
#include <bits/stdc++.h>
using namespace std;
#define CL(a) memset(a,0,sizeof(a))
#define Cl(a,b) memset(a,(b),sizeof(a))
#define MP(a,b) make_pair(a,b)
#define ll long long
const int mod = 1e9 + 7;
const int maxn = 1e3 + 100;
int a[maxn],b[maxn];
int p[maxn],last[maxn];
bool vs[maxn];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for (int i = 1;i <= n;++i)
		scanf("%d",&a[i]);
	for (int i = 1;i <= m;++i)
		scanf("%d",&b[i]);
	int ans = 0;
	for(int i = 1;i <= m;++i){
		p[i] = last[b[i]];
		last[b[i]] = i;
	}
	for(int i = 1;i <= m;++i){
		for(int j = p[i]+1;j < i;++j)
			if(!vs[b[j]]){
				vs[b[j]]=true;
				ans += a[b[j]];
			}
		CL(vs);
	}
	printf("%d\n",ans);
	return 0;
}
