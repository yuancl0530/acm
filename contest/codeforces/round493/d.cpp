/*********************************
Date: Sun Jul  1 23:36:13 CST 2018
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

int main()
{
	int t = 0;
	for (int i = 0;i < 1000;++i){
		int tmp = i%10 + i/10%10 + i/100;
		if (tmp <= 10 )++t;
	}
	printf("%d\n",t);
	return 0;
}
