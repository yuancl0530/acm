/*********************************
Date: Sat Sep 23 16:42:50 CST 2017
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
#define INF 3000
#define LL long long
const int MOD = 1e9 + 7;
const int maxn = 1e6 + 100;
int p[maxn];
int main()
{
	int n,m,k,q;
	while (scanf("%d%d",&n,&m) != EOF){
		for (int i=0;i<n;i++){
			scanf("%d",&p[i]);
		}
		scanf("%d",&k);
		while (k--){
			scanf("%d",&q);
			p[q]=INF;
		}
		int ans_i=0;
		int ans_j=1;
		int cnt=0;
		for (int i=0;i<n;++i){
			cnt=0;
			if (p[i]==INF)
				++cnt;
			int t=i+1;
			for (int j=i+1;j<n;++j){
				if (p[j]==INF)
					++cnt;
				if (p[t]>p[j])
					t=j;
				if (j-i+1-cnt==m && p[i]+p[t]<p[ans_i]+p[ans_j]){
					ans_i=i;
					ans_j=t;
				}
			}
		}
		printf("%d %d\n",ans_i,ans_j);
	}
	return 0;
}
