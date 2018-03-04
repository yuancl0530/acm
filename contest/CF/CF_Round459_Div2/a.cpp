/*********************************
Date: Mon Jan 29 22:31:44 CST 2018
Author: ycl
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
LL f[maxn];
int isf[maxn];
void init()
{
	f[1]=1;
	f[2]=1;
	isf[1]=1;
	for (int i=3;i<=1000;++i){
		f[i] = f[i-1]+f[i-2];
		isf[f[i]] = 1;
		if (f[i]>1000) break;
	}
}
int main()
{
	int n;
	init();
	cin>>n;
	for (int i=1;i<=n;++i){
		if (isf[i])
			cout<<"O";
		else
			cout<<'o';
	}
	cout<<endl;

	return 0;
}
