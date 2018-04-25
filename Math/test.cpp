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
#define INF 0x7fffffff
#define LL long long
const int MOD = 1e9 + 7;
const int maxn = 1e6 + 100;
LL exgcd(LL a,LL b,LL &x,LL &y)
{
	if (b == 0){x = 1,y = 0;return a;}
	LL d = exgcd(b,a%b,x,y);
	LL t = x;
	x = y;
	y = t - a/b*y;
	return d;
}
int main()
{
	LL x,y,m,n,l;
	while (cin>>x>>y>>m>>n>>l){
		LL A = (m-n+l)%l;
		LL B = (y-x+l)%l;
		LL n = l;
		int d = exgcd(A,n,x,y);
		if (B%d==0){
			LL ans = x*(B/d);
			LL s = n/d;
			ans = (ans%s+s)%s;
			cout << ans << endl;
		}
		else{
			cout <<"Impossible"<<endl;
		}

	}
	return 0;
}
