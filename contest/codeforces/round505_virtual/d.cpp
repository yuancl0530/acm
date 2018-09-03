/*********************************
Date: Fri Aug 24 17:14:31 CST 2018
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
const int maxn = 1e3 + 100;
bool f[maxn][maxn];
int a[maxn];
int gcd(int a,int b)
{
	if (b == 0) return a;
	return gcd(b,a%b);
}
int main()
{
	int n;
	cin >> n;
	for (int i = 1;i <= n;++i){
		cin >> a[i];
		f[i][1] = true;
	}
	for (int j = 2;j <= n;++j){
		for (int i = 1;i+j-1 <= n;++i){
			int l = i;
			int r = i+j-1;

		}
	}
	printf("%s\n",f[1][n]? "Yes":"No");
	return 0;
}
