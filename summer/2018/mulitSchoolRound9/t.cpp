/*********************************
Date: Mon Aug 20 13:36:25 CST 2018
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
const int maxn = 1e2 + 100;
int a[maxn];
int b[maxn][maxn];
bool check(int n,int m)
{
	int cnt = 0;
	for (int i = 1;i <= n;++i){
		for (int j = 1;j <= m;++j){
			int p = 0;
			for (int k=1;k<=n;++k) if (b[k][j]>b[i][j]) ++p;
			for (int k=1;k<=m;++k) if (b[i][k]>b[i][j]) ++p;
			if (p==0) ++cnt;
		}
	}
	return cnt == 1;
}
int cal(int n,int m)
{
	for (int i = 0;i < n*m;++i) a[i] = i+1;
	int ans = 0;
	do {
		int  t = 0;
		for (int i = 1;i <= n;++i){
			for (int j = 1;j <= m;++j){
				b[i][j] = a[t++];
			}
		}
		if (check(n,m))	++ans;
	}while (next_permutation(a,a+n*m));
	return ans;
}
int main()
{
	for (int i = 2;i <= 2;++i){
		for (int j = 1;j <= 5;++j){
			printf("%d\n",cal(i,j));
		}
		printf("\n");
	}
	return 0;
}
