/*********************************
Date: Tue Sep 19 16:55:27 CST 2017
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
char str[maxn];
char s[maxn];
int Next[maxn];
void getNext(char *s)
{
	int k=-1;
	Next[0]=-1;
	for (int i=1;s[i];++i){
		while (k>=0 && s[i]!=s[k+1])
			k=Next[k];
		if (s[i]==s[k+1])
			++k;
		Next[i]=k;
	}
}
int solve(char *str,char *s)
{
	int len=strlen(s);
	int k=-1;
	getNext(s);
	int ans=0;
	for (int i=0;str[i];++i){
		while (k>=0&&str[i]!=s[k+1])
			k=Next[k];
		if (s[k+1]==str[i])
			++k;
		if (k+1==len){
			++ans;
			k=-1;
		}
	}
	return ans;
}
int main()
{
	while (scanf("%s",str)!= EOF && str[0]!='#'){
		scanf("%s",s);
		printf("%d\n",solve(str,s));
	}


	return 0;
}
