/*********************************
Date: Wed Apr 25 19:04:04 CST 2018
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
	int T,m,cur,op;
	int kase = 0;
	ll size;
	ll ans = 0;
	scanf("%d",&T);
	while (T--){
		cur = size = 0;
		ans = 0;
		scanf("%d",&m);
		bool f=1;
		while (m--){
			scanf("%d",&op);
			ll t = -1;
			if (op>0){
				a[cur++] = op;
				++size;
				t = size;
			}
			else if (op<0){
				if (cur>0){
					--cur;
					--size;
					t = a[cur];
				}
			}
			else {
				if (f && size<=100000){
					for (int i=0;i<size;++i){
						a[size+i] = a[i];
					}
					size*=2;
					cur = size;
				}
				else{
					f = 0;
					size *=2;;
				}
				t = size;
			}
			size%=mod;
			if (t!=-1)
				ans = (ans*2333%mod+t)%mod;
		}
		printf("CASE #%d: %lld\n",++kase,ans);
	}
	return 0;
}
