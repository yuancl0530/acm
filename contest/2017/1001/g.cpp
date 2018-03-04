/*********************************
Date: Sun Oct  1 14:14:08 CST 2017
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
const int maxn = 1e3 + 100;
int a[maxn];
int main()
{
	int n;
	while (scanf("%d",&n)!=EOF){
		int t;
		int ans=0;
		CL(a);
		for (int i=1;i<=n;++i){
			for (int j=1;j<=7;++j){
				scanf("%1d",&t);
				a[j]+=t;
				ans=max(ans,a[j]);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
