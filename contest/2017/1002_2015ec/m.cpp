/*********************************
Date: Mon Oct  2 12:10:21 CST 2017
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
const int maxn = 1e3 + 100;
bool a[maxn][maxn];
int n,m;
int ans_mi;
int ans_ma;
void solve()
{
	for (int i=0;i<n;++i){
		int j,t;
		j=0;
		while (j<m){
			while (j<m && !a[i][j]) ++j;
			if (j==m) break;
			t=j;
			while (t<m && a[i][t]) ++t;
			ans_ma+=(t-j)/2+1;
			if (t-j==1)
				ans_mi+=1;
			else
				ans_mi+=(t-j)/2;
			j=t;
		}
	}
}
int main()
{
	int T;
	scanf("%d",&T);
	int Case=0;
	while (T--){
		scanf("%d%d",&n,&m);
		int x,y,b;
		scanf("%d",&b);
		Cl(a,true);
		while (b--){
			scanf("%d%d",&x,&y);
			a[x][y]=false;
		}
		ans_ma=ans_mi=0;
		solve();
		cout<<"Case #"<<++Case<<": "<<ans_ma<<" "<<ans_mi<<endl;
	}
	return 0;
}
