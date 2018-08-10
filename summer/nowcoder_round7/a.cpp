/*********************************
Date: Thu Aug  9 12:20:37 CST 2018
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
void fun(int v)
{
	for (int i = 10;i >= 0;--i){
		printf("%d",(v>>i)&1);
	}
	printf("\n");
}
int main()
{
	int n = 20;
	for (int i = 0;i < n;++i)
		fun(i);
	for (int i = 0;i < n;++i){
		cout<<i<<":";
		for (int j = 0;j < n;++j)
			if ((i&j)==0) cout<<j<<" ";
		cout<<endl;
	}
	return 0;
}
