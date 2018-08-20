/*********************************
Date: Fri Aug 17 15:28:10 CST 2018
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
	int n,h,a,b,q;
	cin >> n >> h >> a >> b >> q;
	int x,y,h1,h2;
	while (q--){
		cin >> x >> h1 >> y >> h2;
		int ans;
		if (x==y) ans = abs(h1-h2);
		else if (h1 >= a && h1 <= b || h2>=a && h2<=b) ans = abs(x-y) + abs(h1-h2);
		else ans = abs(x-y) + min(abs(a-h1)+abs(a-h2),abs(b-h1)+abs(b-h2));
		cout<<ans<<endl;
	}
	return 0;
}
