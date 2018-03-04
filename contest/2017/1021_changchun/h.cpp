/*********************************
Date: Sat Oct 21 14:49:36 CST 2017
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
#define INFLL 0x7fffffffffffffff
#define LL long long
const int MOD = 1e9 + 7;
const int maxn = 1e6 + 100;
int Next[maxn];
int a[maxn];
int b[maxn];
int ans;
void getNext(int *a,int *Next,int n)
{
	int k=-1;
	Next[0]=-1;
	for (int i=1;i<n;++i){
		while (k>=0 && a[i]!=a[k+1])
			k=Next[k];
		if (a[k+1]==a[i])
			++k;
		Next[i]=k;
	}
}
void match(int t,int n,int m,int p)
{
	int k=-1;
	for (int i=t;i<n;i+=p){
		while (k>=0 && a[i]!=b[k+1])
			k=Next[k];
		if (a[i]==b[k+1])
			++k;
		if (k==m-1){
			++ans;
			k=Next[k];
		}
	}
}
int main()
{
	int T;
	scanf("%d",&T);
	for (int tt=1;tt<=T;++tt){
		int n,m,p;
		ans=0;
		scanf("%d%d%d",&n,&m,&p);
		int in;
		for (int i=0;i<n;++i){
			scanf("%d",&a[i]);
		}
		for (int i=0;i<m;++i)
			scanf("%d",&b[i]);
		getNext(b,Next,m);
		for (int i=0;i<p;++i)
			match(i,n,m,p);
		cout<<"Case #"<<tt<<": "<<ans<<endl;
	}


	return 0;
}
