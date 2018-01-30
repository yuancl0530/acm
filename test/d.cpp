/*********************************
Date: Tue Jan 30 21:22:55 CST 2018
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
priority_queue<int, vector<int>, greater<int> > Q;
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	LL ans = 0;
	int t;
	for (int i=0;i<n;++i){
		scanf("%d",&t);
		Q.push(t);
	}
	for (int i=0;i<k;++i){
		t = Q.top();
		Q.pop();
		Q.push(-t);
	}
	while (!Q.empty()){
		ans+=Q.top();
		Q.pop();
	}
	printf("%lld\n",ans);
	return 0;
}
