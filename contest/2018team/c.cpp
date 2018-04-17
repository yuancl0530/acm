/*********************************
Date: Fri Apr 13 15:42:03 CST 2018
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
struct Node
{
	int a,b;
	friend bool operator < (Node a,Node b){
		return a.b<b.b;
	}
}a[maxn];
int tot[maxn];
int b[maxn];
map<int ,int >M;
inline int lowbit(int x){return -x&x;}
int sum(int pos)
{
	int ret=0;
	while (pos>0){
		ret+=tot[pos];
		pos-=lowbit(pos);
	}
	return ret;
}
void update(int pos)
{
	while (pos<maxn){
		tot[pos]+=1;
		pos+=lowbit(pos);
	}
}
vector<int >ans;
int main()
{
	int n;
	scanf("%d",&n);
	int cnt=0;
	for (int i=0;i<n;++i){
		scanf("%d%d",&a[i].a,&a[i].b);
		b[cnt++]=a[i].a;
		b[cnt++]=a[i].b;
	}
	sort(b,b+cnt);
	cnt=unique(b,b+cnt)-b;
	for (int i=0;i<cnt;++i){
		M[b[i]]=i+1;
	}
	sort(a,a+n);
	for (int i=0;i<n;++i){
		int l=M[a[i].a];
		int r=M[a[i].b];
		int t=sum(r)-sum(l-1);
		if (t==0){
			ans.push_back(a[i].b);
			update(r);
		}
	}
	printf("%d\n",(int)ans.size());
	for (int i=0;i<ans.size();++i){
		printf("%d ",ans[i]);
	}
	printf("\n");
	return 0;
}
