/*********************************
Date: Thu Jul 19 14:01:05 CST 2018
Author: ycl
*********************************/
#include <bits/stdc++.h>
using namespace std;
#define CL(a) memset(a,0,sizeof(a))
#define Cl(a,b) memset(a,(b),sizeof(a))
#define MP(a,b) make_pair(a,b)
#define ll long long
const int mod = 1e9 + 7;
const int maxn = 1e5 + 100;
int vs[maxn],a[maxn];
int cnt1[maxn],cnt2[maxn];
int n,q;
int solve(int i,int j)
{
	if (i >= j)
		return cnt1[n];
	int x = cnt2[1] - cnt2[i+1];
	int y = cnt1[n] - cnt1[j-1];
	int t = cnt1[j-1]+cnt2[i+1];
	cout<<x<<" "<<y<<" "<<t<<endl;
	return cnt1[n]-(t-x-y)/2;
}
int main()
{
	while (scanf("%d%d",&n,&q) != EOF){
		for (int i = 1;i <= n;++i){
			scanf("%d",&a[i]);
			vs[i] = 0;
		}
		cnt1[0] = 0;
		for (int i = 1;i <= n;++i){
			cnt1[i] = cnt1[i-1];
			if (!vs[a[i]])
				++cnt1[i];
			++vs[a[i]];
		}
		for (int i = 1;i <= n;++i)
			vs[i] = 0;
		cnt2[n+1] = 0;
		for (int i = n;i > 0;--i){
			cnt2[i] = cnt2[i+1];
			if (!vs[a[i]])
				++cnt2[i];
			++vs[a[i]];
		}
		while (q--){
			int l,r;
			scanf("%d%d",&l,&r);
			printf("%d\n",solve(l,r));
		}
	}
	return 0;
}
