#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
using namespace std;
const int maxn = 5*1e4 +10;
long long dp[maxn];
long long a[maxn];
int main()
{
    int n;
    long long ans;
    long long sum;
    while (scanf("%d",&n) != EOF){
        ans = 0;
        sum = 0;
        for (int i = 0;i < n;i++){
            scanf("%lld",&a[i]);
            sum = max(sum+a[i],0LL);
            ans = max(ans,sum);
        }

        printf("%lld\n",ans);
    }
    return 0;
}
