/*********************************
Date: Fri Apr 13 13:27:27 CST 2018
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
#define INF 0x7ffffff
#define LL long long
const int mod = 1e9 + 7;
const int maxn = 1e6 + 100;
char s[maxn],t[maxn];
int main()
{
	scanf("%s%s",s,t);
	int l=0;
	while (s[l] && s[l]==t[l]){
		++l;
	}
	int r=strlen(s)-1;
	while (r>=0 && s[r]==t[r]){
		--r;
	}
	int ans=1;
	if (l>=r){
		ans=1;
	}
	else{
		for (int i=0;i+l<=r;++i){
			//cout<<s[i+l]<<" "<<t[r-i]<<endl;
			if (s[i+l] != t[r-i]){
				ans=0;
				break;
			}
		}
	}
	if (ans){
		printf("YES\n");
	}
	else{
		printf("NO\n");
	}
	return 0;
}
