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
char s[maxn];
int Next[maxn];
void getNext()
{
	int k=-1;
	int len=strlen(s);
	Next[0]=-1;
	for (int i=1;i<len;++i){
		while (k>=0 && s[i]!=s[k+1])
			k=Next[k];
		if (s[i]==s[k+1])
			++k;
		Next[i]=k;
	}
}
int main()
{
	int T;
	scanf("%s",s);
	getNext();
	int n = strlen(s);
	int k = n-1-Next[n-1];
	if (n % k) k = n;
	printf("%d\n",k);
	for (int i = 0;i < k;++i){
		printf("%d",n/k);
		for (int j = 0;j < n/k;++j)
			printf(" %d",j*k+i);
		printf("\n");
	}
	return 0;
}
