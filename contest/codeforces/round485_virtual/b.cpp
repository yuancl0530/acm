/*********************************
Date: Fri Jun  1 14:32:34 CST 2018
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

int main()
{
	double x,y;
	cin >> x >> y;
	if (x == y)
		cout<<"="<<endl;
	else if (y*log(x) > x*log(y))
		cout<<">"<<endl;
	else
		cout<<"<"<<endl;
	return 0;
}
