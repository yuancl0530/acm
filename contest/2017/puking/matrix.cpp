/*********************************
Date: Tue Sep 26 16:59:09 CST 2017
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
#define INF 0x7f3f3f3f
#define LL long long
const int MOD = 1e9 + 7;
const int maxn = 3e2 + 10;
int ma[maxn][maxn];//
int dp[maxn][2];//0没有改，1改过了
int c[maxn];//第i行到第j行，第k列的和
int minC[maxn];//        ，        最小值
int main()
{
	int n,m,p;
	while (scanf("%d%d%d",&n,&m,&p) != EOF){
		CL(ma);
		CL(minC);
		CL(c);
		CL(dp);
		for (int i=1;i<=n;++i){
			for (int j=1;j<=m;++j)
				scanf("%d",&ma[i][j]);
		}
		int ans=-INF;
		for (int i=1;i<=n;++i){
			for (int j=i;j<=n;++j){
				for (int k=1;k<=m;++k){
					if (i==j){
						c[k]=ma[j][k];
						minC[k]=ma[j][k];
					}
					else{
						c[k]+=ma[j][k];
						minC[k]=min(minC[k],ma[j][k]);
					}
				}
				if (i==1 && j==n){
					int sum=0;
					for (int ii=1;ii<=m;++ii){
						sum=0;
						int mi=INF;
						for (int jj=ii;jj<=m;++jj){
							sum+=c[jj];
							mi=min(mi,minC[jj]);
							ans=max(ans,sum-mi+p);
							if (!(ii==1&&jj==m)) ans=max(ans,sum);
						}
					}
				}
				else 
					for (int k=1;k<=m;++k){
						if (k==1){
							dp[k][0]=c[k];
							dp[k][1]=c[k]-minC[k]+p;
						}
						else{
							dp[k][0]=max(c[k],dp[k-1][0]+c[k]);
							dp[k][1]=max(c[k]-minC[k]+p,max(dp[k-1][0]+c[k]-minC[k]+p,dp[k-1][1]+c[k]));
						}
						ans=max(dp[k][1],ans);
						ans=max(ans,dp[k][0]);
					}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}

