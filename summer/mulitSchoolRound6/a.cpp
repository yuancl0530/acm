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
const int maxn = 1e5+50;
const int inf = 1e9;

int main()
{
    int T;
    scanf("%d", &T);
    double pi = acos(-1);
    while (T--)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        ll ans = (2 * b + pi * a)*1000000;
		a = ans/1000000;
		b = ans%1000000;
        printf("%d.%06d\n",a,b);
    }
    return 0;
}
