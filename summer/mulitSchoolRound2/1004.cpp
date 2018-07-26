#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <vector>
#include <list>
#include <set>
using namespace std;
#define CL(a) memset(a,0,sizeof(a));
#define INF 0x7fffffff
#define LL  long long
const int maxn = 1e5+10;
int n;
int L[maxn];
int R[maxn];
int a[maxn];
LL m;
void _merge(int *a,int l,int t,int r)
{
	int n1 = t - l;
	int n2 = r - t;
	for (int i = 0;i < n1;i++)
		L[i] = a[l+i];
	for (int i = 0;i < n2;i++)
		R[i] = a[t+i];
	L[n1] = INF;
	R[n2] = INF;
	int k = l,i = 0,j = 0;
	while (k < r){
		if (L[i]>R[j]){
			a[k++] = R[j++];
			m += n1-i;
		}
		else{ 
			a[k++] = L[i++];
		}
	}
}
void merge(int *a,int l,int r)
{
	if (l+1 < r){
		merge(a,l,(l+r)/2);
		merge(a,(l+r)/2,r);
		_merge(a,l,(l+r)/2,r);
	}
}
int main()
{
	LL x,y;
	while (scanf("%d%lld%lld",&n,&x,&y) != EOF){
		for (int i = 0;i < n;i++)
			scanf("%d",&a[i]);
		m = 0;
		merge(a,0,n);
		LL ans = m*min(x,y);
		printf("%lld\n",ans);
	}
	return 0;
}

