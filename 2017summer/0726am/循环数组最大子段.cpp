
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
    while (cin >> n){
        LL s = 0;
        for (int i = 0;i < n;i++){
            cin >> a[i];
            s += a[i];
        }
        LL maxSum = 0;
        LL minSum = INF;
        LL ans = 0;
        LL sum = 0;
        for (int i = 0;i < n;i++){
            sum = max(sum + a[i],(LL)0);
            maxSum = max(maxSum,sum);
        }
        for (int i = 0;i < n;i++){
            sum = min(sum + a[i],(LL)0);
            minSum = min(minSum,sum);
        }
        ans = max(maxSum,s - minSum);
        cout << ans <<endl;
    }
    return 0;
}
