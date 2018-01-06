#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <vector>
#include <list>
#include <set>
using namespace std;
#define CL(a) memset(a,0,sizeof(a))
#define Cl(a,b) memset(a,b,sizeof(b))
#define INF 0x7fffffff
#define LL long long
const int maxn = 5e4 + 100;
struct Node
{
	int w;
	int p;
}a[maxn];
int dp[maxn];
int main()
{
	int n,m;
	ios::sync_with_stdio(false);
	while (cin >> n >> m){
		int w,p,c;
		int cnt = 0;
		for (int i = 1;i <= n;i++){
			cin >> w >> p >> c;
			int t = 1;
			while (c - t > 0){
				a[++cnt].w = w * t;
				a[cnt].p = p * t;
				c -= t;
				t *= 2;
			}
			a[++cnt].w = w * c;
			a[cnt].p = p * c;
		}
		CL(dp);
		for (int i = 1;i <= cnt;i++){
			for (int j = m;j >= a[i].w;j--){
				dp[j] = max(dp[j],dp[j-a[i].w] + a[i].p);
			}
		}
		cout << dp[m] << endl;
	}
	return 0;
}
