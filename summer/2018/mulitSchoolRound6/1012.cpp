/*********************************
Date: Wed Aug  8 13:52:20 CST 2018
Author: ycl
*********************************/
#include <bits/stdc++.h>
using namespace std;
#define CL(a) memset(a,0,sizeof(a))
#define Cl(a,b) memset(a,(b),sizeof(a))
#define MP(a,b) make_pair(a,b)
#define INF 0x3f3f3f3f
#define ll long long
const int mod = 1e9 + 7;
const int maxn = 1e6 + 100;

int main()
{
	int a,b,x,y;
	cin >> a >> b >> x >> y;
	x = - x;
	double c = sqrt(a*a+b*b);
	double h = (double)x*b/a;
	cout<<h<<endl;
	double d = 8*h*b/c;
	cout<<c<<" "<<d<<endl;
	int ans = c/d;
	cout<<ans<<endl;
	return 0;
}
