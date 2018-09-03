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
const int maxn = 510;
LL  a[maxn][maxn];
LL c[maxn];
int main()
{
    int m,n;
    ios::sync_with_stdio(false);
    while (cin >> m){
        cin >> n;
        for (int i = 1;i <= n;i++){
            for (int j = 1;j <= m;j++){
                cin >> a[i][j];
            }
        }
        LL ans = -INF;
        LL sum = 0;
        for (int i = 1;i <= n;i++){
            for (int j = i;j <=n;j++){
                for (int k = 1;k <= m;k++){
                    c[k] = j==i? a[j][k] : c[k] + a[j][k];
                }
                sum = 0;
                for (int k = 1;k <= m;k++){
                    sum = max(sum + c[k],(LL)0);
                    ans = max(ans,sum);
                }
            }

        }
        cout << ans <<endl;
    }
    return 0;
}

