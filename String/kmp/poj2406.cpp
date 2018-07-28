/*********************************
Date: Thu Sep 14 13:40:24 CST 2017
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
int next[maxn];
int getNext(char *s)
{
	int k=-1;
	int t=1;
	next[0]=-1;
	for (int i=1;s[i];++i){
		while (k>=0 && s[i] !=s[k+1])
			k=next[k];
		if (s[i]==s[k+1])
			++k;
		next[i]=k;
		if (k==-1)
			t=i+1;
	}
	int len= strlen(s);
	if (len%t==0) return len/t;
	return 1;
}
int main()
{
	while (scanf("%s",s)!=EOF && s[0]!='.'){
		cout<<getNext(s)<<endl;
	}


	return 0;
}
