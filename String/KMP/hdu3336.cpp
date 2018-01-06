
/*********************************
Date: Mon Nov 13 20:42:37 CST 2017
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
const int MOD = 1e4 + 7;
const int maxn = 1e6 + 100;
char s[maxn];
int Next[maxn];
LL getNext()
{
	int k=-1;
	Next[0]=k;
	LL ans=0;
	for (int i=1;s[i];++i){
		while (k>=0 && s[i]!=s[k+1]){
			k=Next[k];
		}
		if (s[i]==s[k+1]){
			++k;
		}
		Next[i]=k;
	}
	for (int i=0;s[i];++i){
		int k=i;
		while (k>=0){
			ans=(ans+1)%MOD;
			k=Next[k];
		}
	}
	return ans;
}
int main()
{
	int T;
	scanf("%d",&T);
	while (T--){
		scanf("%*d%s",s);
		cout<<getNext()<<endl;
	}

	return 0;
}
