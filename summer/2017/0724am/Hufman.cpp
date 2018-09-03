#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
using namespace std;
const int maxn = 1e6 +10;
struct Node
{
    int wet;
}Huf[maxn];
bool operator < (Node a,Node b){return a.wet > b.wet;}
priority_queue<Node>Q;
int wet[maxn];
long long ans;
void creat_huffman(int n)
{
    while (!Q.empty())
        Q.pop();
    int i;
    for (int i = 0;i < n;i++){
        Huf[i].wet = wet[i];
        Q.push(Huf[i]);
    }
    int min1,min2;
    for (int i = n;i < 2*n-1;i++){
        min1 = Q.top().wet;
        Q.pop();
        min2 = Q.top().wet;
        Q.pop();
        Huf[i].wet = min1 + min2;
        ans += min1 + min2;
        Q.push(Huf[i]);
    }
}

int main()
{
    int n;
    while (scanf("%d",&n) != EOF){
        ans = 0;
        for (int i = 0;i < n;i++){
            scanf("%d",&wet[i]);
        }
        creat_huffman(n);
        printf("%lld\n",ans);
    }

    return 0;
}
