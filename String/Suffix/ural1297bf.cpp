/*********************************
Date: Tue Jul 24 18:40:26 CST 2018
Author: ycl
*********************************/
#include <bits/stdc++.h>
using namespace std;
#define CL(a) memset(a,0,sizeof(a))
#define Cl(a,b) memset(a,(b),sizeof(a))
#define MP(a,b) make_pair(a,b)
#define ll long long
const int mod = 1e9 + 7;
const int maxn = 1e6 + 100;
char s[maxn];
int main()
{
	scanf("%s",s);
	int n = strlen(s);
	int len =1,t = 0;
	for (int i = 0;i < n;++i){
		int l = i;
		int r = i;
		while (l >=0 && r < n && s[l] == s[r]) --l,++r;
		if (r-l-1 >= len) {
			if (len == r-l-1) t = min(t,l+1);
			else t = l+1;
			len = r - l - 1;
		}
	}
	for (int i = 1;i < n;++i){
		int l = i-1;
		int r = i;
		while (l >=0 && r < n && s[l] == s[r]) --l,++r;
		if (r-l-1 >= len) {
			if (len == r-l-1) t = min(t,l+1);
			else t = l+1;
			len = r - l - 1;
		}
	}
	for (int i = 0;i < len;++i)
		printf("%c",s[t+i]);
	printf("\n");
	return 0;
}
