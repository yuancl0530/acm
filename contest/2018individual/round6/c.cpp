/*********************************
Date: Wed Apr 11 19:31:15 CST 2018
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
#define LL long long
const int mod = 1e9 + 7;
const int maxn = 1e6 + 100;
int a[maxn],b[maxn],c[maxn];
int main()
{
	int n;
	scanf("%d",&n);
	map<int,int>M;
	for (int i=0;i<n;++i){
		scanf("%d",&a[i]);
		M[a[i]]=M[a[i]]+1;
	}
	int ans=0;
	int m;
	scanf("%d",&m);
	for (int i=0;i<m;++i){
		scanf("%d",&b[i]);	
	}
	for (int i=0;i<m;++i){
		scanf("%d",&c[i]);	
	}
	for (int i=0;i<m;++i){
		if (M[b[i]]>M[b[ans]]){
			ans=i;
		}
		else if (M[b[i]]==M[b[ans]] && M[c[i]]>M[c[ans]]){
			ans=i;
		}
	}
	printf("%d\n",ans+1);
	return 0;
}
