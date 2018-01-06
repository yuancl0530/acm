/*********************************
Date: Wed Sep 27 13:00:14 CST 2017
*********************************/
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>
#include <cctype>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <vector>
#include <list>
#include <set>
#include <sstream>
using namespace std;
#define CL(a) memset(a,0,sizeof(a))
#define Cl(a,b) memset(a,b,sizeof(a))
#define MP(a,b) make_pair(a,b)
#define INF 0x7fffffff
#define LL long long
const int MOD = 1e9 + 7;
const int maxn = 1e6 + 100;
int calf(int n)
{
	int ret=0;
	for (int i=0;i<n;++i){
		for (int j=i;j<n;++j)
			if (i*j%n)++ret;
	}
	return ret;
}
int f[maxn];
int calg(int m)
{
	int ret=0;
	for (int i=1;i<=m;i++){
		if (m%i==0)
			ret+=f[i];
	}
	return ret;
}
int g[maxn];
int main()
{
	for (int i=1;i<=100;i++){
		f[i]=calf(i);
		g[i]=calg(i);
	}
	for (int i=1;i<=100;++i)
		cout<<f[i]<<endl;
	return 0;
}
