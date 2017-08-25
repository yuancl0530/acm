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
#define CL(a) memset(a,0,sizeof(a));
#define LL long long
const int INF= 0x7fffffff;
const int maxn = 1e6 + 100;
LL a[maxn];
int main()
{
    int n;
	LL maxSum,minSum,ans,sum,tot;
    while (scanf("%d",&n) != EOF){
        tot = 0;
        for (int i = 0;i < n;i++){
            scanf("%lld",&a[i]);
            tot += a[i];
        }
        maxSum = sum = 0;
        minSum = INF;
        for (int i = 0;i < n;i++){
            sum = max(sum + a[i],0ll);
            maxSum = max(maxSum,sum);
        }
        for (int i = 0;i < n;i++){
            sum = min(sum + a[i],0ll);
            minSum = min(minSum,sum);
        }
        ans = max(maxSum,tot - minSum);
        printf("%lld\n",ans);
    }
    return 0;
}

