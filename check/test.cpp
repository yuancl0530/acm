
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int maxn = 1e5+50;
const int mod = 1e9+7;
ll n;

ll f(ll x)
{
    ll res = 0;
    for (int i = 0; i < 63 && (1LL<<i) <= x; ++i)
        res += x / (1LL << i);
    return res;
}

ll sum(ll x)
{
    ll res = 0;
    ll inv2 = (1e9+8) / 2;
    for (int i = 0; i < 63 && (1LL<<i) <= x; ++i)
    {
        ll tmp = x / (1LL<<i);
        res = (res + ((tmp * (tmp+1) % mod) * inv2 % mod) * ((1LL<<i) % mod) % mod) % mod;
    }
    return res;
}

ll read() {
    ll x = 0;
    char c = getchar();
    while (c < '0' || c > '9')c = getchar();
    while (c >= '0' && c <= '9') {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x;
}


int main()
{
    //freopen("in.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    while (T--)
    {
        n = read() - 1;
        ll l = n/2-64, r = n/2+64;
        while (r-l > 1)
        {
            ll mid = (l + r) / 2;
            if (f(mid) >= n) r = mid;
            else l = mid;
        }
        ll x = r;
        ll tmp = r * (n - f(r-1)) % mod;
        printf("%lld\n", (sum(r-1) + tmp + 1) % mod);
    }
    return 0;
}
