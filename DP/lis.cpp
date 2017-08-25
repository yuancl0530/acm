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
#define CL(a) memset(a,0,sizeof(a))
const int INF = 0x7fffffff;
const int maxn = 5e4+100;
int a[maxn];
int pos[maxn];
int main()
{
    int n;
    int ans = 0;
    while (cin >> n){
        CL(pos);
        for (int i = 1;i <= n;i++){
            cin >> a[i];
        }
        pos[0] = -INF;
        for (int i = 1;i <= n;i++)
            pos[i] = INF;
        for (int i = 1 ;i <= n;i++){
            int l = 0;
            int r = n + 1;
            int mid;
            while (l + 1 < r){
                mid = (l + r) >> 1 ;
                if (pos[mid] <= a[i])
                    l = mid;
                else
                    r = mid;
            }
			l = pos[r] < a[i] ? r : l;
            ans = max(ans,l+1);
            pos[l+1] = min(pos[l+1],a[i]);
        }
        cout << ans <<endl;
    }
    return 0;
}


