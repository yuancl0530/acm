/*********************************
Date: Sat Aug 25 12:21:29 CST 2018
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
int a[maxn];
int main()
{
	int n = 5;
	for (int i = 0;i < n;++i) a[i] = i+1;
	int ans = 0;
	do {
		for (int i = 0;i < n-1;++i){
			ans += abs(a[i]-a[i+1]);
		}
	}while(next_permutation(a,a+n));
	cout << ans << endl;
	return 0;
}
