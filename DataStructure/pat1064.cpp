/*********************************
Date: Thu Aug 24 10:36:33 CST 2017
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
#define INF 0x7fffffff
#define LL long long
const int MOD = 1e9 + 7;
const int maxn = 1e6 + 100;
struct Node
{
	int l;
	int r;
	int nu;
	int s;
	Node(){l=r=0;s=1;}
}node[maxn];
int n;
int build(int pos=1)
{
	if (pos>n){
		return node[pos].l=node[pos].r=0;
	}
	int l=build(2*pos);
	int r=build(2*pos+1);
	node[pos].l=l;
	node[pos].r=r;
	return l+r+1;
}
void mark(int pos=1)
{
	if (pos>n)return;
	node[pos].nu=node[pos].s+node[pos].l;
	node[2*pos].s=node[pos].s;
	node[2*pos+1].s=node[pos].nu+1;
	mark(2*pos);
	mark(2*pos+1);
}
int a[maxn];
int main()
{
	scanf("%d",&n);
	for (int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	build();
	mark();
	for (int i=1;i<=n;i++){
		if (i==1)cout<<a[node[i].nu-1];
		else cout<<" "<<a[node[i].nu-1];
	}
	cout<<endl;
	return 0;
}
