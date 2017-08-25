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
const int MOD = 998244353;
const int maxn = 1e6 + 100;
LL f[maxn],num[maxn];
int prime[maxn];
int cnt = 0;
void oula()
{
	bool isprime[maxn];
	Cl(isprime,1);
	for (int i = 2;i < maxn;i++){
		if (isprime[i])
			prime[++cnt] = i;
		for (int j = 1;j <= cnt;j++){
			if (i*prime[j] > maxn)
				break;
			isprime[i*prime[j]] = 0;
			if (i%prime[j] == 0)
				break;
		}
	}

}
LL l,r,k;
LL solve()
{
	LL ans = 0;
	LL w;
	for (int i = 1;i <= cnt;i++){
		LL s = l/prime[i] * prime[i];
		if (s < l) s+=prime[i];
		for (LL j = s;j <= r;j+=prime[i]){
			w = 0;
			while (f[j-l]%prime[i] == 0){
				w++;
				f[j-l]/=prime[i];
			}
			num[j-l] = num[j-l]*(w*k+1)%MOD;
		}
	}
	for (int i = 0;i <= r-l;i++){
		if (f[i] > 1)
			num[i] = num[i]*(k+1)%MOD;
		ans = (ans+num[i])%MOD;
	}
	return ans;
}
int main()
{
	oula();
	int t;
	cin >> t;
	while (t--){
		cin>>l>>r>>k;
		for (int i = 0;i <= r-l;i++){
			f[i] = l+i;
			num[i] = 1;
		}
		LL ans = solve();
		cout << ans << endl;
	}


	return 0;
}
