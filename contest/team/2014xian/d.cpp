/*********************************
Date: Tue Apr  3 21:07:06 CST 2018
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
#include <set>
#include <sstream>
using namespace std;
#define CL(a) memset(a,0,sizeof(a))
#define Cl(a,b) memset(a,b,sizeof(a))
#define MP(a,b) make_pair(a,b)
#define INF 0x7fffffff
#define LL long long
const int mod = 1e9 + 7;
const int maxn = 1e6 + 100;
set<string> S;
char s[maxn];
char ss[10];
void dfs(int cnt=0)
{
	cout<<cnt<<endl;
	if (cnt>5000000) return ;
	int i;
	for (i=0;i<26;++i){
		if (cnt>=3){
			for (int j=0;j<=2;++j){
				ss[j]=s[cnt-3+j];
			}
			ss[3]='a'+i;
			ss[4]=0;
			if (S.count(ss)==0){
				break;
			}
		}
	}
	S.insert(ss);
	s[cnt++]='a'+i;
	dfs(cnt);
}
int main()
{
	dfs();

	return 0;
}
