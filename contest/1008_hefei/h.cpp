/*********************************
Date: Sun Oct  8 10:19:11 CST 2017
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
const int maxn = 2050;
int a[maxn];
int b[maxn];
int main()
{
	int T;
	scanf("%d",&T);
	while (T--){
		int n,m;
		scanf("%d",&n);
		for (int i=0;i<n;++i)
			scanf("%d",&a[i]);
		Cl(b,-1);
		for (int i=0;i<n;++i){
			int t=0;
			for (int j=i;j<n;++j){
				t^=a[j];
				if (b[t]<j-i+1)
					b[t]=j-i+1;
			}
		}
		scanf("%d",&m);
		int x;
		int mi=INF,ans;
		while (m--){
			scanf("%d",&x);
			ans=0;
			mi=INF;
			for (int i=0;i<=2048;i++){
				if (b[i] !=-1 && mi>=abs(i-x)){
					if (mi>abs(i-x))
						ans=b[i];
					else
						ans=max(ans,b[i]);
					mi=abs(x-i);
				}
			}
			printf("%d\n",ans);
		}
		printf("\n");
	}
	return 0;
}
