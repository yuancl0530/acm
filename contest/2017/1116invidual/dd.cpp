/*********************************
Date: Sat Nov 18 16:00:21 CST 2017
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
#define INFLL 0x7fffffffffffffff
#define LL long long
const int MOD = 1e9 + 7;
const int maxn = 1e6 + 100;
int a[maxn],b[maxn],ma[maxn][30],mb[maxn][30];
int lg[maxn],n;
void Init()
{
	lg[1]=0;
	for (int i=2;i<maxn;++i)
		lg[i]=lg[i/2]+1;
}
void ST()
{
	for (int i=1;i<=n;++i){
		ma[i][0]=a[i];
		mb[i][0]=b[i];
	}
	for (int i=1;i<=20;++i){
		for (int j=1;j<=n;++j){
			ma[j][i]=max(ma[j][i-1],ma[j+(1<<(i-1))][i-1]);
			mb[j][i]=min(mb[j][i-1],mb[j+(1<<(i-1))][i-1]);
		}
	}
}
int f_a(int l,int r)
{
	int len=lg[r-l+1];
	return max(ma[l][len],ma[r-(1<<len)+1][len]);
}
int f_b(int l,int r)
{
	int len=lg[r-l+1];
	return min(mb[l][len],mb[r-(1<<len)+1][len]);
}
int b_l(int s)
{
	int l=s-1;
	int r=n;
	int mid;
	while (l+1<r){
		mid=(l+r)/2;
		if (f_a(s,mid) >= f_b(s,mid))
			r=mid;
		else
			l=mid;
	}
	if (f_b(s,r) == f_a(s,r))
		return r;
	return 0;
}
int b_r(int s)
{
	int l=s;
	int r=n+1;
	int mid;
	while (l+1<r){
		mid=(l+r)/2;
		if (f_b(s,mid) >= f_a(s,mid))
			l=mid;
		else
			r=mid;
	}
	if (f_b(s,l) == f_a(s,l))
		return l;
	return 0;
}

int main()
{
	Init();
	scanf("%d",&n);
	for (int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	for (int i=1;i<=n;++i)
		scanf("%d",&b[i]);
	ST();
	LL ans=0;
	for (int i=1;i<=n;++i){
		int l=b_l(i);
		int r=b_r(i);
		if (l && r)
			ans+=r-l+1;
	}
	cout<<ans<<endl;
	return 0;
}
