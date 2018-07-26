/*********************************
Date: Wed Jul 25 20:39:24 CST 2018
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

int main()
{
	ifstream fin1("out");
	ifstream fin2("1007.out");
	int a,b;
	int i = 1;
	while  ( fin1 >> a){
		fin2 >> b;
		if (a == b)
			cout<<i<<": "<<a<<" "<<b<<endl;
		++i;
	}
	return 0;
}
