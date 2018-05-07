/*********************************
Date: Tue Sep 19 17:27:23 CST 2017
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
char s[maxn];
int Next[maxn];
int n;
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
void solve(char *s)
{
	int t=0;
	getNext(s);
	for (int i=0;i<n;++i){
		if (Next[i]!=-1 && (i+1)%(i-Next[i])==0)
			printf("%d %d\n",i+1,(i+1)/(i-Next[i]));
	}
}
int main()
{
	int t=0;
	while (scanf("%d",&n)!=EOF && n!=0){
		scanf("%s",s);
		printf("Test case #%d\n",++t);
		solve(s);
		printf("\n");
	}
	return 0;
}
