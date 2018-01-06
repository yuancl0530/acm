/*********************************
Date: Tue Nov  7 20:51:26 CST 2017
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
char s[maxn];
int cnt;
int ans[maxn];
void getNext()
{
	Next[0]=-1;
	int k=-1;
	for (int i=1;s[i];++i){
		while (k>=0 && s[k+1]!=s[i])
			k=Next[k];
		if (s[i]==s[k+1])
			++k;
		Next[i]=k;
	}
	int t=strlen(s)-1;
	cnt=0;
	while (Next[t]>=0){
		ans[cnt++]=Next[t]+1;
		t=Next[t];
	}
	sort(ans,ans+cnt);
}
int main()
{
	while (scanf("%s",s)!=EOF){
		getNext();
		for (int i=0;i<cnt;++i)
			printf("%d ",ans[i]);
		printf("%d\n",(int)strlen(s));
	}
	return 0;
}
