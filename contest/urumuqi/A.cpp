/*********************************
Date: Sat Sep  9 12:16:53 CST 2017
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
const int maxn =  100;
vector<int> M[maxn];
vector<int> B[maxn];
struct Node{
	int x;
	int y;
	bool operator <(Node a){
		if (x!=a.x)
			return x<a.x;
		else
			return y<a.y;
	}
}ans[maxn*100];
int main()
{
	int T;
	int n,m;
	scanf("%d",&T);
	while (T--){
		scanf("%d%d",&n,&m);
		for (int i=0;i<=50;i++){
			M[i].clear();
			B[i].clear();
		}
		int a,b;
		for (int i=0;i<n;i++){
			scanf("%d%d",&a,&b);
			M[a].push_back(b);
		}
		for (int i=0;i<m;i++){
			scanf("%d%d",&a,&b);
			B[a].push_back(b);
		}
		int cnt=0;
		for (int i=0;i<=50;++i){
			for (int j=0;j<M[i].size();++j){
				int t=M[i][j];
				for (int k=0;k<B[t].size();++k){
					ans[cnt].x=i;
					ans[cnt++].y=B[t][k];
				}
			}
		}
		sort(ans,ans+cnt);
		for (int i=0;i<cnt;++i){
			if (i && ans[i].x==ans[i-1].x&&ans[i].y==ans[i-1].y)continue;
			printf("%d %d\n",ans[i].x,ans[i].y);
		}
		printf("\n");
	}

	return 0;
}
