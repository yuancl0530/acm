/*********************************
Date: Sun Oct  8 11:05:33 CST 2017
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
const int maxn =  100;
int ta[maxn],tb[maxn];
int main()
{
	int T;
	scanf("%d",&T);
	while (T--){
		LL a,b;
		cin>>a>>b;
		int j=0;
		int ma=0;
		CL(ta);
		CL(tb);
		if (a<b) swap(a,b);
		LL t=a;
		while (t) {ta[ma]=t&1;++ma;t>>=1;};
		t=b;
		while (t){tb[j]=t&1;++j;t>>=1;};
		ma=max(ma,j);
		for (int i=ma-1;i>=0;--i){
			if (ta[i] != tb[i]){
				for (int j=i-1;j>=0;--j)
					ta[j]=1;
				break;
			}
		}
		LL ans=0,tt=1;
		for (int i=0;i<ma;++i,tt<<=1)
			ans+=ta[i]*tt;
		cout<<ans<<endl;
	}
	return 0;
}
