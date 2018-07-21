/*********************************
Date: Thu Jun 21 15:48:07 CST 2018
Author: ycl
*********************************/
#include <bits/stdc++.h>
using namespace std;
#define CL(a) memset(a,0,sizeof(a))
#define Cl(a,b) memset(a,(b),sizeof(a))
#define MP(a,b) make_pair(a,b)
#define ll long long
const int mod = 1e9 + 7;
const int maxn = 2e3 + 100;
char s[maxn];
int main()
{
	int p,n;
	scanf("%d%d",&n,&p);
	scanf("%s",s);
	for (int i = 0;i < n;++i){
		if (i+p >= n){
			if (s[i] == '.')
				s[i] = '1';
		}
		else if (s[i] == '.') {
			if (s[i+p] == '1')
				s[i] = '0';
			else if (s[i+p] == '0')
				s[i] = '1';
			else {
				s[i] = '1';
				s[i+p] = '0';
			}
		}
		else if (s[i+p] == '.'){
			if (s[i] == '1')
				s[i+p] = '0';
			else 
				s[i+p] = '1';
		}
	}
	bool f = 0;
	for (int i = 0;i+p < n;++i){
		if (s[i] != s[i+p]){
			f = 1;
			break;
		}
	}
	if (f)
		printf("%s\n",s);
	else 
		printf("No\n");
	return 0;
}
