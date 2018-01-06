/*********************************
Date: Sun Oct  1 14:09:47 CST 2017
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
const int maxn = 3e5 + 100;
LL a[maxn];
int binsearch(LL *a,LL k,LL left,LL right)
{
	int l=left;
	int r=right+1;
	int mid;
	while (l+1<r){
		mid=(l+r)>>1;
		if (a[mid]<k)
			l=mid;
		else
			r=mid;		
	}
	return l;
}
int main()
{
	LL n,k;
	for (LL i=1;i<maxn;++i)
		a[i]=i*(i-1)/2;
	while (scanf("%lld%lld",&n,&k) != EOF){
		if (k > n*(n-1)/2){
			cout<<"Impossible"<<endl;
			continue;
		}
		else if (k==0){
			for (int i=1;i<=n;++i)
				printf("()");
			printf("\n");
			continue;
		}
		int s=binsearch(a,k,1,n);
		LL tt = k-a[s];
		for (int i=1;i<=n-s-1;++i)
			printf("()");
		for (int i=1;i<=s;++i){
			printf("(");
			if (i==tt)
				printf("()");
		}
		for (int i=1;i<=s;++i){
			printf(")");
		}
		printf("\n");
	}	
	return 0;
}
