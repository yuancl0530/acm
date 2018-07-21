/*********************************
Date: Thu Jun 14 09:09:27 CST 2018
Author: ycl
*********************************/
#include <bits/stdc++.h>
using namespace std;
#define CL(a) memset(a,0,sizeof(a))
#define Cl(a,b) memset(a,(b),sizeof(a))
#define MP(a,b) make_pair(a,b)
#define ll long long
const int mod = 1e9 + 7;
const int maxn = 1e5 + 100;
char s[maxn];
int main()
{
	scanf("%s",s);
	bool ans = false;
	int n =strlen(s);
	for (int i = 1;i+1 < n;++i){
		int t = 0;
		if (s[i]=='.') continue;
		t |= 1<<s[i-1]-'A';
		t |= 1<<s[i]-'A';
		t |= 1<<s[i+1]-'A';
		if (t== 7) {
			ans = true;
			break;
		}
	}
	if (ans) printf("Yes\n");
	else printf("No\n");
	return 0;
}
