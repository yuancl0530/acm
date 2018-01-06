/*********************************
Date: Tue Aug 22 08:47:35 CST 2017
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
#define INF 0x7fffffff
#define LL long long
const int MOD = 1e9 + 7;
const int maxn = 1e6 + 100;
LL sum[maxn];
int w[maxn];
int n;
LL dis(int a,int b)
{
	if (a==b) return 0;
	LL tot=sum[n];
	if (a<b) 
		return sum[b-1]-sum[a-1];
	return tot+sum[b-1]-sum[a-1];
}
int cnt(int a,int b)
{
	if (b>=a) 
		return b-a+1;
	return n+b-a+1;
}
LL solve()
{
	int mid=1;
	LL lsum=0,rsum=0;
	for (int i=1;i<=n;i++)rsum+=sum[n]-sum[i];
	LL ans=0;
	for (int i=1;i<=n;i++){
		while (dis(i,mid+1)<dis(mid+1,i)){
			if (mid==n)mid=1;
			else ++mid;
			lsum+=dis(i,mid);
			rsum-=dis(mid,i);
		}
		ans+=lsum+rsum;
		if (mid==i){
			if (mid==n)mid=1;
			else ++mid;
			lsum+=dis(i,mid);
			rsum-=dis(mid,i);
		}
		lsum-=w[i]*(cnt(i,mid)-1);
		rsum+=w[i]*(cnt(mid+1,i+1)-1);
	}
	return ans>>1;
}
int main()
{
	while (scanf("%d",&n) != EOF){
		CL(w);
		CL(sum);
		for (int i=1;i<=n;i++){
			scanf("%d",&w[i]);
			sum[i]=w[i]+sum[i-1];
		}
		LL ans=solve();
		printf("%lld\n",ans);
	}
	return 0;
}
