#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>
#include <cctype>
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
#define Cl(a,b) memset(a,b,sizeof(a))
#define INF 0x7fffffff
#define LL long long
const int MOD = 1e9 + 7;
const int maxn = 5e3 + 10;
struct Node
{
    int left;
    int right;
    int value;
};
int a[maxn];
Node node[4*maxn];
void build(int left,int right,int pos = 1)
{
    node[pos].left = left;
    node[pos].right = right;
    node[pos].value = 0;
    if (left == right){
        return ;
    }
    build(left,(left+right)/2,2*pos);
    build((left+right)/2+1,right,2*pos+1);
    return ;
}
int query(int left,int right,int pos = 1)
{
    if (left > node[pos].right || right < node[pos].left){
        return 0;
    }
    if (left <= node[pos].left && node[pos].right <= right){
        return node[pos].value;
    }
    int l = query(left,right,2*pos);
    int r = query(left,right,2*pos+1);
    return l + r;
}
int update(int index,int pos = 1)
{
    if (index < node[pos].left || index > node[pos].right){
        return node[pos].value;
    }
    if (node[pos].left == node[pos].right){
        return node[pos].value = 1;
    }
    int l = update(index,2*pos);
    int r = update(index,2*pos+1);
    return node[pos].value = l + r;
}


int main()
{
    int n;
    while (scanf("%d",&n) != EOF){
        LL sum = 0;
        build(1,n);
        for (int i = 1;i <= n;i++){
            scanf("%d",&a[i]);
            sum += query(a[i]+1,n);
            update(a[i] + 1);
        }
        LL ans = sum;
        for (int i = 1;i <= n;i++){
            sum +=  n - 1 - 2*a[i];
            ans = min(ans,sum);
        }
        printf("%lld\n",ans);
    }


    return 0;
}
