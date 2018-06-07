/*********************************
Date: Fri Jun  1 14:50:04 CST 2018
Author: ycl
*********************************/
#include <bits/stdc++.h>
using namespace std;
#define CL(a) memset(a,0,sizeof(a))
#define Cl(a,b) memset(a,(b),sizeof(a))
#define MP(a,b) make_pair(a,b)
#define ll long long
const int mod = 1e9 + 7;
const int maxn = 3e3 + 100;
int s[maxn];
int c[maxn];
struct Node
{
	int w,c;
	friend bool operator < (Node a,Node b)
	{
		return a.w < b.w;
	}
}a[maxn];
int main()
{
	int n;
	scanf("%d",&n);
	for (int i = 0;i < n;++i)
		scanf("%d",&a[i].w);
	for (int i = 0;i < n;++i)
		scanf("%d",&a[i].c);
	int ans = -1;
	for (int i = 0;i < n;++i){
		int t = -1;
		for (int j = 0;j < i;++j)
			if (a[j].w < a[i].w &&(t==-1 || a[j].c < t))
				t = a[j].c;
		int t2 = -1;
		for (int j = i+1;j < n;++j)
			if (a[i].w < a[j].w &&(t2==-1 || a[j].c < t2))
				t2 = a[j].c;
		if (t==-1 || t2 == -1) continue;
		if (ans==-1 || ans > t+t2+a[i].c)
			ans = t+t2+a[i].c;
	}
	printf("%d\n",ans);
	return 0;
}
