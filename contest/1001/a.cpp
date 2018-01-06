/*********************************
Date: Sun Oct  1 14:44:05 CST 2017
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
struct Node
{
	int l;
	int r;
}a[maxn],b[maxn];
int main()
{
	int n;
	while (scanf("%d",&n) != EOF){
		for (int i=1;i<=n;++i)
			scanf("%d%d",&a[i].l,&a[i].r);
		int cnt=0;
		for (int i=1;i<=n;++i){
			if (a[i].l==0){
				int t=i;
				while (a[t].r)
					t=a[t].r;
				b[++cnt].l=i;
				b[cnt].r=t;
			}
		}
		for (int i=2;i<=cnt;++i){
			a[b[i-1].r].r=b[i].l;
			a[b[i].l].l=b[i-1].r;
		}
		for (int i=1;i<=n;++i)
			printf("%d %d\n",a[i].l,a[i].r);
	}
	return 0;
}
