/*********************************
Date: Sat May 26 13:25:37 CST 2018
Author: ycl
*********************************/
#include <bits/stdc++.h>
using namespace std;
#define CL(a) memset(a,0,sizeof(a))
#define Cl(a,b) memset(a,(b),sizeof(a))
#define MP(a,b) make_pair(a,b)
#define ll long long
const int mod = 1e9 + 7;
const int maxn = 4e5 + 100;
struct Node
{
	int w;
	int i;
	friend bool operator < (Node a,Node b)
	{
		return a.w < b.w;
	}
}a[maxn];
char s[maxn];
priority_queue<Node >Q;
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;++i){
		scanf("%d",&a[i].w);
		a[i].i = i+1;
	}
	scanf("%s",s);
	sort(a,a+n);
	int l = 0;
	for (int i = 0;s[i];++i){
		if (s[i] == '0'){
			printf("%d ",a[l].i);
			Q.push(a[l]);
			++l;
		}
		else {
			printf("%d ",Q.top().i);
			Q.pop();
		}
	}
	printf("\n");
	return 0;
}
