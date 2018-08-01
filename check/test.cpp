/*********************************
Date: Wed Aug  1 15:32:27 CST 2018
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
ll sum[100][100];
int a[100],s[100][100];
int n;
void init()
{
	int t = 0;
	for (int i =n;i < 2*n;++i)
		a[i] = a[i-n];
	if (n%2==0) n*=2;
	for (int i = 0;i <= 3*n;++i){
		for (int j=0;j <= i;++j){
			s[j][i-j] = a[t];
			t = (t+1) % n;
		}
	}

	/*for (int i = 0;i < n;++i){
		for (int j = 0;j < n;++j)
			cout<<s[i][j]<<" ";
		cout<<endl;
	}*/
	a[0] = 0;
	for (int i = 1;i <= n;++i){
		for (int j = 1;j <= n;++j){
			a[j] = s[i-1][j-1] + a[j-1];
			sum[i][j] = sum[i-1][j] + a[j];
		}
	}
}
ll solve(int x,int y)
{
	ll ans = 0;
	int t1 = x/n;
	int t2 = y/n;
	ans = sum[n][n]*t1*t2;
	ans += t2*sum[x-t1*n][n];
	ans += t1*sum[n][y-t2*n];
	ans += sum[x-t1*n][y-t2*n];
	//cout<<x<<" "<<y<<" "<<ans<<endl;
	return ans;
}
int main()
{
	int T,m;
	scanf("%d",&T);
	while (T--){
		int x1,x2,y1,y2;
		scanf("%d",&n);
		for (int i = 0;i < n;++i)
			scanf("%d",&a[i]);
		init();
		scanf("%d",&m);
		while (m--){
			scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
			++x1;
			++x2;
			++y1;
			++y2;
			ll ans = solve(x2,y2) -solve(x1-1,y2) - solve(x2,y1-1) + solve(x1-1,y1-1) ;
			printf("%lld\n",ans);
		}
	}
	return 0;
}
