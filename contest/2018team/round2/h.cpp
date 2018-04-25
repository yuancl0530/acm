/*********************************
Date: Fri Apr 20 14:11:13 CST 2018
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
int main()
{
	int n;
	while (scanf("%d",&n) != EOF){
		for (int i=1;i<=n;++i){
			scanf("%d",&a[i]);
		}
		int ans = 0;
		for (int i=1;i <= n;){
			if (a[i] == i) {
				++i;
			}
			else {
				++ans;
				swap(a[i],a[a[i]]);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
