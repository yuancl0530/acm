/*********************************
Date: Fri Aug 25 19:34:42 CST 2017
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
const int maxn = 1e5 + 100;
const int maxm = 15;
LL dp[maxn][maxm];
int a[maxn];
int lowbit(int x){return x&(-x);}
int n,k;
LL sum(int p,int len)
{
	LL sum=0;
	while (p>0){
		sum+=dp[p][len];
		p-=lowbit(p);
	}
	return sum;
}
LL update(int pos,int len,LL value)
{
	while (pos<=n){
		dp[pos][len]+=value;
		pos+=lowbit(pos);
	}
}
int main()
{
	while (scanf("%d%d",&n,&k) != EOF){
		CL(dp);
		for (int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		for (int i=1;i<=n;i++){
			for (int j=1;j<=min(i,k+1);j++){
				if (j==1)
					update(a[i],1,1);
				else{
					LL temp=sum(a[i]-1,j-1);
					update(a[i],j,temp);
				}
			}
		}
		printf("%lld\n",sum(n,k+1));
	}
	return 0;
}
