/*********************************
Date: Mon Oct 16 19:13:34 CST 2017
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
#define INFLL 0x7fffffffffffffff
#define LL long long
const int MOD = 1e9 + 7;
const int maxn = 1e6 + 100;

int main()
{
	int n,a,b,c;
	scanf("%d%d%d%d",&n,&a,&b,&c);
	--n;
	int ans=0;
	if (a>c&&b>c){
		if (n){
			ans+=min(a,b);
			--n;
		}
		ans+=c*n;
	}
	else{
		ans+=min(a,b)*n;
	}
	cout<<ans<<endl;
	return 0;
}
