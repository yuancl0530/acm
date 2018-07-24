/*********************************
Date: Thu May 17 22:49:33 CST 2018
Author: ycl
*********************************/
#include <bits/stdc++.h>
using namespace std;
#define CL(a) memset(a,0,sizeof(a))
#define Cl(a,b) memset(a,b,sizeof(a))
#define MP(a,b) make_pair(a,b)
#define INF 0x7fffffff
#define ll long long
const int mod = 1e9 + 7;
const int maxn = 1e6 + 100;
int Next[maxn];
char s[maxn];
void getNext()
{
	Next[1] = 0;
	int k = 1;
	for (int i = 2;s[i];++i){
		while (k>0 && s[i] != s[k+1])
			k = Next[k];
		if (s[i] == s[k+1]) ++k;
		Next[i] = k;
	}
}
int f[maxn];
int main()
{
	int n;
	scanf("%d",&n);
	scanf("%s",s+1);
	getNext();
	for (int i = 0;i <= n;++i) f[i] = n+1;
	f[0] = 0;
	for (int i = 1;i<=n;++i){
		int k = i;
		while (i%2==0 && k>0 && Next[k] != i/2) k = Next[k];
		if (i%2 || Next[i] == 0 || Next[k]*2 != i) f[i] = f[i-1] + 1;
		else f[i] = min(f[i-1],f[i/2]) + 1;
	}
	printf("%d\n",f[n]);
	return 0;
}
