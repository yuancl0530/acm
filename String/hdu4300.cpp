/*********************************
Date: Thu May 24 11:16:51 CST 2018
Author: ycl
*********************************/
#include <bits/stdc++.h>
using namespace std;
#define CL(a) memset(a,0,sizeof(a))
#define Cl(a,b) memset(a,(b),sizeof(a))
#define MP(a,b) make_pair(a,b)
#define ll long long
const int mod = 1e9 + 7;
const int maxn = 1e5 + 100;
char d[30],t[30],s[maxn];
int Next[maxn];
void getNext()
{
	int k = -1;
	Next[0] = k;
	for (int i = 1;s[i];++i){
		while (k>=0 && d[s[k+1]-'a'] != s[i])
			k = Next[k];
		if (d[s[k+1]-'a'] == s[i]) ++k;
		Next[i] = k;
	}
}
void solve()
{
	getNext();
	int m = strlen(s);
	int k = Next[m-1];
	while (k+1 > m/2)k = Next[k];
	m -= k+1;
	for (int i = 0;i<m;++i) printf("%c",s[i]);
	for (int i = 0;i<m;++i) printf("%c",d[s[i]-'a']);
	printf("\n");
}
int main()
{
	int T;
	scanf("%d",&T);
	while (T--){
		scanf("%s%s",t,s);
		for (int i = 0;i<26;++i) d[t[i]-'a'] = 'a'+i;
		solve();
	}
	return 0;
}
