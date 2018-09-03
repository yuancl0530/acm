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
#include <cmath>
using namespace std;
#define CL(a) memset(a,0,sizeof(a));
const int INF= 0x7fffffff;
const int maxn = 1e6 + 100;

int main()
{
    int m;
    int t = 1;
    while (scanf("%d",&m) != EOF){
        if (m == 1){
            printf("Case #%d: 0\n",t++);
            continue;
        }
        int ans = (int )m * log10(2);
        printf("Case #%d: %d\n",t++,ans);
    }

    return 0;
}
