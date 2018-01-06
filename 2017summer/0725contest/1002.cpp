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
const int INF= 0x7fffffff;
const int MOD = 1e9 + 7;
const int maxn = 1e5 + 100;
struct Node
{
    int c;
    int v[maxn];
}a[30];
int maxLen;
bool cmp(Node a,Node b)
{
    for (int i = maxLen - 1;i >= 0;i--){
        if (a.v[i] != b.v[i])
            return a.v[i] > b.v[i];
        else
            continue;
    }
    return a.v[0] > b.v[0];
}
bool nzero[30];
char str[maxn];
long long f[maxn];
long long value[30];
int main()
{
    int n;
    f[0] = 1;
    for (int i = 1;i < maxn;i++){
        f[i] = ( f[i-1] * 26 ) % MOD;
    }
    int cas = 0;
    while (scanf("%d",&n) != EOF){
        CL(a);
        CL(nzero);
        CL(value);
        maxLen = 0;
        for (int i = 0;i < 26;i++)
            a[i].c = i;
        for (int i = 0;i < n;i++){
            scanf("%s",str);
            int len = strlen(str);
            if (len != 1)
                nzero[str[0] - 'a'] = 1;
            maxLen = max(maxLen,len);
            for (int i = 1;i <= len;i++){
                a[str[i-1] - 'a'].v[len - i]++;
            }
        }

       for (int i = 0;i < 26;i++){
            for (int j = 0;j < maxLen - 1;j++){
                if (a[i].v[j] > 25){
                    a[i].v[j+1] += a[i].v[j] / 26;
                    a[i].v[j] %= 26;
                }
            }
        }

        sort(a,a + 26,cmp);
        bool z = 1;
        int t = 1;
        for (int i = 25;i >= 0;i--){
            if (z && !nzero[a[i].c]){
                value[a[i].c] = 0;
                z = 0;
                continue;
            }
            value[a[i].c] = t++;
        }
        long long ans = 0;

        /*for (int i = 0;i < 26;i++){
            printf("%c = %d\n",'a' + i,value[i]);
        }
        for (int i = 0;i < 26;i++){
            printf("%c:\n",'a' + a[i].c);
           for (int j = 0;j < maxLen;j++)
                printf("%d ",a[i].v[j]);
            cout<<endl;
        }*/
        for (int i=0;i<26;i++)
            printf("%c ",'a'+a[i].c);
        for (int i = 0;i < 26;i++){
            for (int j = 0;j < maxLen;j++){

                ans = ( ans + f[j] * value[a[i].c] % MOD * a[i].v[j] ) % MOD;
            }
        }
        printf("Case #%d: %I64d\n",++cas,ans);
    }
    return 0;
}


