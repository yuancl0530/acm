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
using namespace std;
#define CL(a) memset(a,0,sizeof(a))
#define Cl(a,b) memset(a,b,sizeof(a))
#define INF 0x7fffffff
#define LL long long
const int MOD = 1e9 + 7;
const int maxn = 1e3 + 10;
int a[maxn];
int k,n;
LL ans;
bool vs[100][100];
int mid;
void dfs(int value,int l,int r,int t  = 1)
{
	if (t > k || l < 1 || r > n)
		return ;
		if (vs[mid-l][r-mid]) return ;

	if (t == k){
	//	cout << l <<","<< r <<endl;
		ans += value;
		int cntl = 0;
		int cntr = 0;
		int i = l - 1;
		while (i > 0 && a[i] < k){cntl++;i--;};
		i = r+1;
		while (i <= n && a[i] < k){cntr++;i++;};
		ans += value*cntl*cntr;
		return ;
	}
	vs[mid-l][r-mid] = 1;
	if (a[l-1] >= value)
		dfs(value,l-1,r,t+1);
	else
		dfs(value,l-1,r,t);
	if (a[r+1] >= value)
		dfs(value,l,r+1,t+1);
	else
		dfs(value,l,r+1,t);
}
int main()
{
	int t ;
	scanf("%d",&t);
	while (t--){
		scanf("%d%d",&n,&k);
		ans = 0;
		for (int i = 1;i <= n;i++){
			scanf("%d",&a[i]);
		}
		for (int i = 1;i <= n;i++){
			CL(vs);
			mid = i;
			dfs(a[i],i,i,1);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
