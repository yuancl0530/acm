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

int mod = 1e9+7;
const int maxn = 1e4+50;
const int inf = 1e9;

ll a[maxn];
int cnt[maxn];
ll ans[10];

int main()
{
    for (int i = 1; i < (1<<10); ++i)
    {
        int tmp = i;
        int t = 0;
        while (tmp)
        {
            if (tmp & 1) t ++;
            tmp >>= 1;
        }
        if (!(t & 1))
            cnt[i] = t / 2;
    }
    int T;
    scanf("%d", &T);
    while (T--)
    {
        mst(a);
        mst(ans);
        a[0] = 1;
        int n, m;
        int u, v;
        char s[2];
        scanf("%d %d", &n, &m);
        while (m--)
        {
            scanf("%s %d %d", s, &u, &v);
            //if (u < v) swap(u, v);
            int dt = s[0] == '+' ? 1 : -1;
            for (int i = 0; i < (1<<n); ++i)
            {
                if ((i & (1<<(u-1))) && (i & (1<<(v-1))))
                {
                    int tmp = i - (1<<(u-1)) - (1<<(v-1));
                    if (dt > 0)
                    {
                        if (a[i] > 1e15 || a[tmp] > 1e15)
                            a[i] = (a[i] + a[tmp]) % mod;
                        else 
                            a[i] += a[tmp];
                    }
                    else
                    {
                        a[i] -= a[tmp];
                        if (a[i] < 0)
                        {
                            ll b = -a[i] / mod + 2;
                            a[i] = (a[i] + b * mod) % mod;
                        }
                    }
                    ans[cnt[i]] = (ans[cnt[i]] + a[tmp]*dt) % mod;
                }
            }
            for (int i = 1; i <= n/2; ++i)
            {
                printf("%lld%c", ans[i], i==n/2 ? '\n' : ' ');
            }
        }
    }
    return 0;
}
