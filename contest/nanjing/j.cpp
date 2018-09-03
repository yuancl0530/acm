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

const int mod = 1e9+7;
const int maxn = 2e7+50;
const int inf = 1e9;

bool is_prime[maxn];
int prime[maxn];
int p[maxn];
int ans[maxn];
ll pre[maxn];

void euler()
{
    int cnt = 0;
    for (int i = 2; i < maxn; ++i)
        is_prime[i] = true;
    for (int i = 2; i < maxn; ++i)
    {
        if (is_prime[i])
        {
            p[i] = 1;
            prime[cnt++] = i;
        }
        for (int j = 0; j < cnt && prime[j]*i < maxn; ++j)
        {
            is_prime[i*prime[j]] = false;
            if (i % prime[j] == 0)
            {
                if (i / prime[j] % prime[j] == 0) p[i*prime[j]] = -1;
                else p[i*prime[j]] = p[i] - 1;
                break;
            }
            if (p[i] == -1) p[i*prime[j]] = -1;
            else p[i*prime[j]] = p[i] + 1;
        }
    }
    for (int i = 1; i < maxn; ++i)
    {
        if (p[i] == -1) ans[i] = 0;
        else ans[i] = 1 << p[i];
    }
    for (int i = 1; i < maxn; ++i)
        pre[i] = pre[i-1] + ans[i];
}

int main()
{
    //freopen("in", "r", stdin);
    euler();
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n;
        scanf("%d", &n);
        printf("%lld\n", pre[n]);
    }
    return 0;
}
