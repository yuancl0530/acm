/*********************************
Date: Wed Aug 15 14:03:24 CST 2018
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
int a[50][50];
int n = 4;
int m = 6;
int mm = 0;
void solve(ll x)
{
	for (int i = 1;i <= n;++i){
		for (int j = 1;j <= m;++j){
			a[i][j] = x>>(n*m-1-(m*(i-1)+j-1)) & 1;
		}
	}
	int ans = 0;
	for (int i = 1;i <= n;++i){
		int cnt = 0;
		for (int j = 1;j <= m;++j){
			if (!a[i][j]) ++cnt;
			else{
				if (!cnt) {
					cnt=-1;
					break;
				}
				--cnt;
			}
		}
		if (cnt == 0) ++ans;
	}
	for (int i = 1;i <= m;++i){
		int cnt = 0;
		for (int j = 1;j <= n;++j){
			if (!a[j][i]) ++cnt;
			else{
				if (!cnt) {
					cnt=-1;
					break;
				}
				--cnt;
			}
		}
		if (cnt == 0) ++ans;
	}
	if (ans <= max(n,m)) return ;
	mm = max(ans,mm);
	cout<<ans<<" "<<mm<<endl;
	for (int i = 1;i <= n;++i){
		for (int j = 1;j <= m;++j)
			printf("%c",a[i][j]? ')':'(');
		printf("\n");
	}
	cout<<endl;
}
int main()
{
	ll s = 0;
	for (ll i = s;i < (1ll<<(n*m));++i){
		solve(i);
	}
	return 0;
}
