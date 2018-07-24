/*********************************
Date: Sun Jul  1 22:07:29 CST 2018
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
int a[maxn];
int main()
{
	int n;
	scanf("%d",&n);
	int sum = 0;
	for (int i =1;i <= n;++i){
		scanf("%d",&a[i]);
		sum += a[i];
	}
	int ans = -1;
	int k = 0;
	for (int i = 1;i <= n;++i){
		if (a[i] != sum - a[i]){
			ans = i;
			break;
		}
	}
	if (ans == -1 || n==1)
		printf("-1\n");
	else{
		printf("1\n%d\n",ans);
	}
	return 0;
}
