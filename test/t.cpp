/*********************************
Date: Wed Feb 14 17:34:33 CST 2018
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
#define LL long long
const int MOD = 1e9 + 7;
const int maxn = 2e2 + 100;
int a[maxn];
int b[maxn];
int ans[maxn];
char s[maxn];
int len1=1;
int len2=1;
int len3;
void stoi(char *s,int *a,int &len)
{
	int j = strlen(s)-1;
	int i=0;
	int t = 0;
	while (t < j && s[t]=='0')
		++t;
	while (j>=t)
		a[i++] = s[j--]-'0';
	len = i;
}
void solve()
{
	len3 = max(len1,len2);
	int t=0;
	for (int i=0;i<len3;++i){
		ans[i] = a[i]+b[i]+t;
		t = ans[i]/10;
		ans[i] %= 10;
	}
	if (t)
		ans[len3++] = t;
	for (int i=len3-1;i>=0;--i)
		printf("%d",ans[i]);

}
int main()
{
	CL(a);
	CL(b);
	scanf("%s",s);
	stoi(s,a,len1);
	scanf("%s",s);
	stoi(s,b,len2);
	solve();
	return 0;
}
