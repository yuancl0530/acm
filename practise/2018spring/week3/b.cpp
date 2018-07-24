/*********************************
Date: Mon Mar 19 20:54:04 CST 2018
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
char s[maxn];
int num[maxn];
int node[maxn];
int cnt;
int ans;
vector<int>G[20];
void init(){CL(num);CL(node);cnt=0;ans=0;for (int i=1;i<=17;++i)G[i].clear();}
void build()
{	
	int id = 1;
	for (int i=0;s[i];++i){
		if (s[i]=='[') id<<=1;
		else if (s[i]==',')++id;
		else if (s[i]==']')id>>=1;
		else {
			int t=s[i]-'0';
			while (s[i+1] && isdigit(s[i+1])){
				t*=10;
				t+=s[i+1]-'0';
				++i;
			}
			node[id] = t;
			num[cnt++] = id;
			t=id/2;
			while (t>=1&& node[t]!=-1){
				node[t]=-1;
				t>>=1;
			}
		}
	}
	int t=1;
	for (int i=1;i<=17;++i){
		t = 1<<(i-1);
		for (int j=t;j<2*t;++j){
			if (node[j]>0)
				G[i].push_back(node[j]);
		}
	}
	for (int i=0;i<=17;++i)
		sort(G[i].begin(),G[i].end());
}
int cal(int u,LL tmp)
{
	if (!G[u].size()) return 0;
	int l=0;
	int r=G[u].size();
	int mid;
	while (l+1<r){
		mid = (l+r)/2;
		if (G[u][mid]<=tmp)
			l = mid;
		else 
			r=mid;
	}
	int cnt = 0;
	int j=l;
	while (j>=0 && G[u][j]==tmp){
		++cnt;
		--j;
	}
	return G[u].size()-cnt;
}
int check(LL tmp)
{
	int ret=0;
	for (int i=1;i<=17;++i){
		ret+=cal(i,tmp);
		//if (tmp%2==1 && G[i+1].size()) return INF;
		tmp>>=1;
	}
	return ret;
}
int solve()
{
	ans = cnt;
	for (int i=0;i<cnt;++i){
		LL tmp=node[num[i]];
		int t = num[i];
		while (t>1){
			tmp<<=1;
			t>>=1;
		}
		ans = min(ans,check(tmp));
	}
	return ans;
}
int main()
{
	int T;
	scanf("%d",&T);
	while (T--){
		init();
		scanf("%s",s);
		build();
		printf("%d\n",solve());
	}
	return 0;
}
