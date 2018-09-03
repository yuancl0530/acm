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

int mod;
const int maxn = 1e6+50;
const int inf = 1e9;
int prime_size = 0;

bool is_prime[maxn];
int prime[maxn/10];
int miu[maxn];
ll f[maxn];
int a[maxn];
int b[maxn];
int g[maxn];
int inv[maxn];

int get_inv(int x)
{
    if (inv[x]) return inv[x];
    if (x == 1) return inv[x] = 1;
    return inv[x] = (ll)get_inv(mod % x) * (mod - mod/x) % mod;
}

void euler(int n)
{
    for (int i = 2; i <= n; ++i)
        is_prime[i] = true;
    for (int i = 2; i <= n; ++i)
    {
        if (is_prime[i])
        {
            prime[prime_size++] = i;
            miu[i] = -1;
        }
        for (int j = 0; j < prime_size && i*prime[j] <= n; ++j)
        {
            is_prime[i*prime[j]] = false;
            
            if (i % prime[j] == 0)
            {
                miu[i*prime[j]] = 0;
                break;
            }
            miu[i*prime[j]] = -miu[i];
        }
    }
    for (int i = 1; i <= n; ++i)
        a[i] = b[i] = 1;
    for (int i = 0; i < prime_size; ++i)
    {
        for (int j = prime[i]; j <= n; j += prime[i])
        {
            a[j] *= prime[i];
            b[j] *= (prime[i] - 1);
        }
    }
    miu[1] = 1;
}

int main()
{
    euler(1000000);
    int T;
    scanf("%d", &T);
    while (T--)
    {
        mst(inv);
        int n, m;
        scanf("%d %d %d\n", &n, &m, &mod);
        if (m > n) swap(n, m);
        for (int i = 1; i <= n; ++i)
            if (!inv[i]) get_inv(i);
        for (int i = 1; i <= n; ++i)
        {
            f[i] = (ll)(n / i) * (m / i);
            g[i] = (ll)a[i] * inv[b[i]%mod] % mod;
        }
        ll ans = 0;
        for (int i = 1; i <= m; ++i)
        {
            ll t = 0;
            for (int j = 1; j*i <= n; ++j)
                t += miu[j] * f[i*j];
            t %= mod;
            ans += t * g[i] % mod;
            //printf("%lld\n", ans);
        }
        printf("%lld\n", ans % mod);
    }
        
    return 0;
}
