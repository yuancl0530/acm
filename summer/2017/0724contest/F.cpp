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
const int maxn = 1e5 + 10;
int a[maxn];
int le[maxn];
int ri[maxn];
int o[maxn];
int main()
{
    int n;
    int top=0;
    while (scanf("%d",&n) != EOF){
        for (int i = 1;i <= n;i++){
            scanf("%d",&a[i]);
        }
        o[top] = o[n+1] = 0;
        o[top = 1] = 0;
        for (int i = 1;i <= n;i++){
            while (top && a[o[top]] >= a[i])
                top--;
            le[i] = o[top] + 1;
            o[++top] = i;
        }
        o[top = 1] = n+1;
        for (int i = n;i > 0;i--){
            while (top && a[o[top]] >= a[i])
                top--;
            ri[i] = o[top] - 1;
            o[++top] = i;
        }
        long long ans = 0;
        for (int i = 1;i <= n;i++){
            ans = max(ans,(long long)a[i]*(ri[i] - le[i] + 1));
        }
        printf("%lld\n",ans);
    }
    return 0;
}

