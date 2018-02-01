/*********************************
Date: Wed Jan 31 22:12:36 CST 2018
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
const int maxn = 3e5 + 100;
vector<int>Edge[maxn];
int deg[maxn];
char s[maxn];
int cnt[30];
int res;
int vs[maxn];
int flag=0;
int visit[maxn];
void dfs(int t)
{
	if (flag){
		return ;
	}
	if (vs[t]){
		flag=1;
		return ;
	}
	int id = s[t-1]-'a';
	++cnt[id];
	if (cnt[id] > res) res = cnt[id];
	vs[t]=1;
	for (int i=0;i<Edge[t].size();++i){
		dfs(Edge[t][i]);
	}
	vs[t]=0;
	cnt[id]--;
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	scanf("%s",s);
	for (int i=0;i<m;++i){
		int u,v;
		scanf("%d%d",&u,&v);
		Edge[u].push_back(v);
		deg[v]++;
	}
	int ans = -1;
	for (int i=1;i<=n;++i){
		if (!deg[i] && Edge[i].size()){
			res=0;
			dfs(i);
			ans=max(ans,res);
			if (flag){
				cout<<-1<<endl;
				return 0;
			}
		}	
	}
	printf("%d\n",ans);
	return 0;
}
