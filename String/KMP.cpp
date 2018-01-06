/*********************************
Date: Wed Sep 13 21:02:46 CST 2017
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
const int maxn = 1e6 + 100;
char s[maxn],str[maxn];
int next[maxn];
void getNext(char *s)
{
	int k=-1;
	int len=strlen(s);
	next[0]=-1;
	for (int i=1;i<len;++i){
		while (k>=0 && s[i]!=s[k+1])
			k=next[k];
		if (s[i]==s[k+1])
			++k;
		next[i]=k;
	}
}
int kmpmatch(char *s,char *str)
{
	int ans=0;
	getNext(s);
	int lens=strlen(s);
	int k=-1;
	for (int i=0;str[i];++i){
		while (k>=0 && str[i]!=s[k+1])
			k=next[k];
		if (str[i]==s[k+1])
			++k;
		if (k==lens-1){
			++ans;
			k=next[k];
		}
	}
	return ans;
}
int main()
{
	int T;
	scanf("%d",&T);
	while (T--){
		scanf("%s%s",s,str);
		int ans=kmpmatch(s,str);
		printf("%d\n",ans);
	}
	return 0;
}
