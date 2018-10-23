/*********************************
Date: Sat Sep  8 12:19:20 CST 2018
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
	a[0] = 0;
	a[1] = 2;
	for (int i = 2;i <= 100;++i){
		a[i] = (3*a[i-1] - a[i-2])/2 + i + 1;
		cout <<i<<" "<< a[i] << endl;
	}
	
	return 0;
}
