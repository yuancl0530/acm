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
const int maxn = 1e6+10;
int a[maxn];
int main()
{
    int n;
    int b;

    long long ans = 0;
    ios::sync_with_stdio(false);
    while (cin >> n){
        memset(a,0,sizeof a);
        for (int i = 0;i < n;i++){
            cin>>b;
            a[b]++;
        }
        for (int i = 0;i <= 1000000;i++){
            if (!a[i])continue;
            a[i+1] += a[i]>>1;
            a[i] &= 1;
            ans += a[i];
        }
        while (a[1000001]){
            ans += a[1000001]&1;
            a[1000001]/=2;
        }
        cout<<ans<<endl;
    }
    return 0;
}
