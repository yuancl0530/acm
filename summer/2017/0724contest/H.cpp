#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <set>
#include <stack>
#include <queue>
#include <vector>
#include <cctype>
using namespace std;
const int MOD = 1000000007;
long long quick_mod(long long x,long long n)
{
    long long res = 1;
    while(n)
    {
        if(n & 1)
            res=(res*x)%MOD;
        x=(x*x)%MOD;
        n >>= 1;
    }
    return res;
}
int main()
{
    long long b = quick_mod(2,MOD-2);
    long long n;
    while (cin >> n){
        long long ans = (quick_mod(3,n+1)-1)*b % MOD;
        cout << ans<<endl;
    }

    return 0;
}
