/*********************************
Date: Sat Mar  3 16:52:07 CST 2018
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
const int maxn = 1e6 + 100;
char s[maxn];
int Next[maxn];
int main()
{	
	while (scanf("%s",s+1) != EOF){
		int cur = 0;
		int last  =0;
		CL(Next);
		for (int i=1;s[i];++i){
			if (s[i] == '[') 
				cur = 0;
			else if (s[i] == ']')
				cur = last;
			else{
				Next[i] = Next[cur];
				Next[cur] = i;
				if (cur == last) last = i;
				cur=i;
			}

		}
		for (int i=Next[0];i;i=Next[i])
			printf("%c",s[i]);
		printf("\n");
	}
	return 0;
}
