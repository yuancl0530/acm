/*********************************
Date: Mon Oct  2 12:35:15 CST 2017
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
LL find(LL k)
{
	for (LL i=1;;++i){
		if (i*(i+1)>2*k)
			return i-1;
	}
}
int main()
{
	int T;
	scanf("%d",&T);
	for (int t=1;t<=T;++t){
		LL k;
		scanf("%lld",&k);
		k<<=1;
		LL ans=sqrt(k);
		if (ans*(ans+1)>k)
			--ans;
		LL tt=find(k);
		cout<<"Case #"<<t<<": "<<ans*(ans+1)/2<<endl;
	}
	return 0;
}
