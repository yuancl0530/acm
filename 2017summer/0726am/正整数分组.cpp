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
const int maxn = 1e4 + 100;
int f[maxn];
int a[maxn];
int main()
{
    int n;
    while (cin >> n){
        int sum = 0;
        for (int i = 1;i <= n;i++){
            cin >> a[i];
            sum += a[i];
        }
        int w = sum >> 1;
        //sort(a+1,a+1+n);
        for (int i = 1;i <= n;i++){
            for (int j = w;j >= a[i];j--){
                f[j] = max(f[j],f[j-a[i]] + a[i]);
            }
        }
        cout << sum - 2 * f[w] <<endl;
    }

    return 0;
}

