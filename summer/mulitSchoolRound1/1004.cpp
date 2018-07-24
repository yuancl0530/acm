/*********************************
Date: Mon Jul 23 12:58:20 CST 2018
Author: ycl
*********************************/
#include <bits/stdc++.h>
using namespace std;
#define CL(a) memset(a,0,sizeof(a))
#define Cl(a,b) memset(a,(b),sizeof(a))
#define MP(a,b) make_pair(a,b)
#define ll long long
const int mod = 1e9 + 7;
const int maxn = 1e6 + 100;
struct Node
{
	int l,r;
	friend bool operator < (Node a,Node b)
	{
		if (a.l != b.l) return a.l < b.l;
		return a.r > b.r;
	}
}q[maxn];
int a[maxn];
priority_queue<int, vector<int>, greater<int> >Q;
int main()
{
	int n,m,T;
	scanf("%d",&T);
	while (T--){
		scanf("%d%d",&n,&m);
		for (int i = 1;i <= n;++i) a[i] = 1;
		a[0] = n+1;
		while (!Q.empty()) Q.pop();
		for (int i = 1;i <= n;++i) Q.push(i);
		for (int i = 0;i < m;++i)
			scanf("%d%d",&q[i].l,&q[i].r);
		sort (q,q+m);
		int l=0;
		int r=0;
		for (int i = 0;i < m;++i){
			if (q[i].r <= r) continue;
			if (q[i].l == l) continue;
			if (q[i].l >= r){
				for (int j = l;j <= r;++j) Q.push(a[j]);
				l = q[i].l;
			}
			else{
				for (int j = l;j <q[i].l;++j) Q.push(a[j]);
				l = r+1;
			}
			r = q[i].r;
			for (int j = l;j <= r;++j){
				a[j] = Q.top();
				Q.pop();
			}
			l = q[i].l;
		}
		for (int i = 1;i <= n;++i)
			printf("%d ",a[i]);
		printf("\n");
	}
	return 0;
}
