/*********************************
Date: Wed Aug 15 20:34:17 CST 2018
Author: ycl
*********************************/
#include <bits/stdc++.h>
using namespace std;
#define CL(a) memset(a,0,sizeof(a))
#define Cl(a,b) memset(a,(b),sizeof(a))
#define MP(a,b) make_pair(a,b)
#define INF 0x3f3f3f3f
#define ll long long
const int mod = 1e9 + 7;
const int maxn = 1e6 + 100;
int a[maxn];
int s1[maxn],s2[maxn];
int main()
{
	int n;
	scanf("%d",&n);
	for (int i = 1;i <= n;++i) scanf("%d",&a[i]);
	int ans = a[1];
	int top1 = -1;
	int top2 = -1;
	s1[++top1] = 1;
	s2[++top2] = 1;
	for (int i = 2;i <= n;++i){
		int t1 = INF;
		int t2 = INF;
		while (top1 >= 0 && a[i] < a[s1[top1]]) --top1;
		if (top1 >= 0) t1 = a[i] - a[s1[top1]];
		s1[++top1] = i;

		while (top2 >=0 && a[i] > a[s2[top2]]) --top2;
		if (top2 >= 0) t2 = a[s2[top2]] - a[i];
		s2[++top2] = i;

		ans += min(t1,t2);
		cout<<ans<<" "<<i<<" "<<t1<<" "<<t2<<endl;
	}
	printf("%d\n",ans);
	return 0;
}
