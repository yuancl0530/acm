/*********************************
Date: Wed Jan 31 21:09:14 CST 2018
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
LL m[maxn];
int cnt=0;
int check(LL n)
{
	int res=0;
	while (n){
		res+=n%10;
		n/=10;
	}
	return res;
}
void dfs(LL a=0)
{
	LL t = check(a);
	if (t==10){
		m[cnt++] = a;
		while (a<1e10){
			a*=10;
			m[cnt++]=a;
		}
		return;
	}
	if (t>10 || a==0 || a>1e11) return ;
	for (int i=0;i<10;++i){
		dfs(a*10+i);
	}
}
int main()
{
	for (int i=1;i<=9;++i)
		dfs(i);
	sort(m,m+cnt);
	cout<<cnt<<endl;
/*	int k;
	scanf("%d",&k);
	printf("%lld\n",m[k-1]);*/
	return 0;
}
