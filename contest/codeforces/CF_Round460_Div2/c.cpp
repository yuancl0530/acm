/*********************************
Date: Wed Jan 31 21:32:06 CST 2018
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
char G[2010][2010];

int main()
{
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	for (int i=0;i<n;++i){
		scanf("%s",G[i]);
	}
	LL ans=0;
	int t;
	for (int i=0;i<n;++i){
		int j;
		for (j=0;j<m;){
			t=0;
			if (G[i][j] == '.'){
				t=1;
				++j;
				while (G[i][j] == '.'){
					++j;
					++t;
				}
				if (t>=k){
					ans+=t+1-k;
				}
			}
			else {
				++j;
			}
		}
	}
	if (k!=1)
	for (int i=0;i<m;++i){
		int j,t;
		for (j=0;j<n;){
			t=0;
			if (G[j][i] == '.'){
				t=1;
				++j;
				while (G[j][i] == '.'){
					++j;
					++t;
				}
				if (t>=k){
					ans+=t+1-k;
				}
			}
			else{
				++j;
			}
		
		}
	
	}
	printf("%lld\n",ans);

	return 0;
}
