/*********************************
Date: Sun Apr 29 10:05:50 CST 2018
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
#include <set>
#include <sstream>
using namespace std;
#define CL(a) memset(a,0,sizeof(a))
#define Cl(a,b) memset(a,b,sizeof(a))
#define MP(a,b) make_pair(a,b)
#define INF 0x7fffffff
#define ll long long
#define ull unsigned long long
const int mod = 1e9 + 7;
const int maxn = 1e6 + 100;
int a[maxn];
vector<int>V[100010];
int main()
{	
	int n,k;
	scanf("%d%d",&n,&k);
	for (int i=0;i<n;++i){
		scanf("%d",&a[i]);
		int t = k==0? 0:i%k;
		V[t].push_back(a[i]);
	}
	for (int i=0;i<k;++i){
		sort(V[i].begin(),V[i].end());
	}
	sort(a,a+n);
	int ans=-1;
	for (int i=0;i<n;++i){
		int t = k==0? i:i/k;
		int u = k==0? 0:i%k;
		if (t>=V[u].size()) continue;
		if (a[i] != V[u][t]){
			ans = i+1;
			break;
		}
	}
	printf("%d\n",ans);
	return 0;
}
