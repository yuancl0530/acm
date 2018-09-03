#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <vector>
#include <list>
#include <set>
using namespace std;
#define CL(a) memset(a,0,sizeof(a))
#define INF 0x7fffffff
#define LL long long
const int MOD = 1e9 + 7;
const int maxn = 1e6;
int ca[maxn];
int cb[maxn];
int v[maxn];
int a[maxn],b[maxn];
int main()
{
    int n,m;
    int Case = 0;
    while (scanf("%d%d",&n,&m) != EOF){
        int ta = 0;
        int tb = 0;
        memset(v,0,sizeof v);
        for (int i = 0;i < n;i++){
            scanf("%d",&a[i]);
            v[a[i]] = 1;
            if (v[i]){
                int sum = 1;
                int k = a[i];
                while (k < i){
                    sum++;
                    k = a[k];
                }
                if (k == i)
                    ca[ta++] = sum;
            }
        }
        memset(v,0,sizeof v);
        for (int i = 0;i < m;i++){
            scanf("%d",&b[i]);
            v[b[i]] = 1;
            if (v[i]){
                int sum = 1;
                int k = b[i];
                while (k < i){
                    sum++;
                    k = b[k];
                }
                if (k == i)
                    cb[tb++] = sum;
            }

        }
 /*       for (int i = 0;i < ta;i++)
            cout << ca[i] << " ";
        cout << endl;
        for (int i = 0;i < tb;i++)
            cout << cb[i] << " ";
        cout << endl;*/
        LL ans = 1;
        LL sum = 0;
        for (int i = 0;i < ta;i++){
            sum = 0;
            for (int j = 0;j < tb;j++){
                if (ca[i] % cb[j] == 0)
                    sum = (sum + cb[j]) % MOD;
            }
            ans = (ans * sum) % MOD;
        }
        printf("Case #%d: %lld\n",++Case,ans);
    }
	return 0;
}
