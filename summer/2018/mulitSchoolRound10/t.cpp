/*********************************
Date: Thu Aug 23 20:30:28 CST 2018
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
const int maxn = 1e5 + 100;

int cnt[maxn];
int main()
{
	int m = 0;
	for (int i = 1;i < maxn;++i){
		for (int j = 1;j*i < maxn;++j)
			m = max(m,++cnt[i*j]);
	}
	printf("%d\n",m);
	return 0;
}
