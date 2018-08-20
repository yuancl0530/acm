/*********************************
Date: Fri Aug 17 15:44:12 CST 2018
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
bool vs[maxn];
int n;
int solve(int x)
{
	for (int i = 1;i <= n;++i) vs[i] = false;
	while (!vs[x]){
		vs[x] = true;
		x = a[x];
	}
	return x;
}
int main()
{
	scanf("%d",&n);
	for (int i = 1;i <= n;++i){
		scanf("%d",&a[i]);
	}
	for (int i = 1;i <= n;++i)
		printf("%d ",solve(i));
	printf("\n");
	return 0;
}
