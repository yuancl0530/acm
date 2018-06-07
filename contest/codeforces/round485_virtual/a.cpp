/*********************************
Date: Fri Jun  1 14:21:26 CST 2018
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
char s[6][10] = {
	"purple",
	"green",
	"blue",
	"orange",
	"red",
	"yellow"
};
char t[6][10] = {
	"Power",
	"Time",
	"Space",
	"Soul",
	"Reality",
	"Mind"
};
bool vs[6];
char ss[10];
int main()
{
	int n;
	cin >>  n;
	int cnt = 0;
	for (int i = 0;i < n;++i){
		cin >> ss;
		for (int j = 0;j < 6;++j){
			if (strcmp(s[j],ss) == 0){
				if (!vs[j]) ++cnt;
				vs[j] = true;
				break;
			}
		}
	}
	cout<<6-cnt<<endl;
	for (int i = 0;i < 6;++i){
		if (!vs[i])
			cout <<t[i]<<endl;
	}
	return 0;
}
