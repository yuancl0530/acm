/*********************************
Date: Mon Mar 26 19:41:44 CST 2018
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
const int maxn = 1e5 + 100;
int tot[maxn],rank[maxn],p1[maxn],p2[maxn],cow[maxn],Next[maxn];
int n,m,s;
vector<int> ans;
int cnt=0;
int lowbit(int x){return -x&x;}
void update(int pos,int v)
{
	for (;pos<=s;pos+=lowbit(pos)){
		tot[pos]+=v;
	}
}
int sum(int pos)
{
	int ret=0;
	for (;pos>0;pos-=lowbit(pos)){
		ret+=tot[pos];
	}
	return ret;
}
void getNext()
{
	int k=-1;
	CL(tot);
	for (int i=0;i<m;++i){
		p1[i]=sum(rank[i]);
		p2[i]=sum(rank[i]-1);
		update(rank[i],1);
	}
	CL(tot);
	Next[0]=-1;
//	update(rank[0],1);
	for (int i=1;i<m;++i){
		while (k>=0 && (p1[k+1]!=sum(rank[i]) || p2[k+1]!=sum(rank[i]-1)) ){
			for (int j=i-1-k;j<i-1-Next[k];++j){
				update(rank[j],-1);
			}
			k=Next[k];
		}
		if ( p1[k+1]==sum(rank[i]) && p2[k+1]==sum(rank[i]-1)){
			++k;
		}
		Next[i]=k;
		update(rank[i],1);
	}
}
void solve()
{
	ans.clear();
	getNext();
	#ifdef DEBUG
	for (int i=0;i<m;++i){
		printf("%d ",Next[i]);
	}
	#endif
	printf("\n");
	CL(tot);
	int k=-1;
	for (int i=0;i<n;++i){
		while (k>=0 && (p1[k+1]!=sum(cow[i]) || p2[k+1]!=sum(cow[i]-1))){
			for (int j=i-1-k;j<i-1-Next[k];++j){
				update(cow[j],-1);
			}
			k=Next[k];
		}
		if ( p1[k+1]==sum(cow[i]) && p2[k+1]==sum(cow[i]-1)){
			++k;
		}
		if (k+1==m){
			ans.push_back(i-k+1);
			for (int j=i-k;j<i-Next[k];++j){
				update(cow[j],-1);
			}
			k=Next[k];
		}
		update(cow[i],1);
	}
}
int main()
{
	while (scanf("%d%d%d",&n,&m,&s)!=EOF){
		for (int i=0;i<n;++i){
			scanf("%d",&cow[i]);
		}
		for (int i=0;i<m;++i){
			scanf("%d",&rank[i]);
		}
		solve();
		printf("%d\n",(int)ans.size());
		for (int i=0;i<ans.size();++i){
			printf("%d\n",ans[i]);
		}
	}
	return 0;
}
