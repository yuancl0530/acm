#include <cstdio>
#include <cstring>
#include <cmath>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
using namespace std;
#define ll long long
#define mst(a) memset(a, 0, sizeof a)

const int maxn = 1e7+50;
const int inf = 1e9;
int a[maxn];
int n, m,k,r,p,mod,q;
int Q[maxn];
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d %d %d %d %d %d %d", &n, &m, &k, &p, &q, &r, &mod);
        for (int i = 1; i <= k; ++i)
            scanf("%d", &a[i]);
        for (int i = k+1; i <= n; ++i)
            a[i] = ((ll)p*a[i-1] + (ll)q*i + r) % mod;
		int front  = 0;
		int tail = 0;
		ll ans1 = 0;
		ll ans2 = 0;
		int cnt = 0;
		for (int i = n;i > n-m+1;--i){
			while (front < tail && a[i] >= a[Q[tail-1]]) --tail;
			Q[tail++] = i;
		}
		for (int i = n-m+1;i > 0;--i){
			r = i+m-1;
			while (Q[front] > r) ++front;
			while (front < tail && a[i] >= a[Q[tail-1]]) --tail;
			Q[tail++] = i;
			ans1 += a[Q[front]]^i;
			ans2 += (tail-front)^i;
		}
		printf("%lld %lld\n",ans1,ans2);
    }
    return 0;
}
