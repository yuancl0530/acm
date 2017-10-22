/*********************************
Date: Mon Oct  2 15:59:34 CST 2017
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
int a[maxn];
int main()
{
	int n,k;
	while (scanf("%d%d",&n,&k) != EOF){
		for (int i=0;i<n;++i)
			scanf("%d",&a[i]);
		sort(a,a+n);
		int ans=0;
		for (int i=0;i<k;++i)
			ans+=a[i];
		cout<<ans<<endl;
	}
	return 0;
}
