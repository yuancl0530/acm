/*********************************
Date: Mon Nov 13 20:16:31 CST 2017
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
char s[maxn];
int Next[maxn];
int getNext()
{
	int k=-1;
	Next[0]=-1;
	for (int i=1;s[i];++i){
		while (k>=0 && s[k+1]!=s[i])
			k=Next[k];
		if (s[i]==s[k+1])
			++k;
		Next[i]=k;
	}
	int len=strlen(s);
	int t=len-1-Next[len-1];
	if (len%t) return 1;
	return len/t;
}
int main()
{
	while (scanf("%s",s)!=EOF && s[0]!='.')
		cout<<getNext()<<endl;


	return 0;
}
