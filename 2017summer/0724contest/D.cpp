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
const int maxn  = 2e3 + 100;
int p[maxn][maxn];
int s[maxn][maxn];
int main()
{
    int n,x;
    while (scanf("%d%d",&n,&x) != EOF){
        if (x >= n){
            printf("-1\n");
            continue;
        }
        int dog = 1;
        int m = n*x;
        for (int i = 0;i < n;i++){
            for (int j = 0;j < x;j++){
                p[i][j] = dog;
                s[(i+1+j)%n][j] = dog;
                dog++;
            }

        }
        for (int i = 0;i < n;i++){
            for (int j = 0;j < x;j++){
                printf("%d ",p[i][j]);
            }
            for (int j = 0;j < x;j++){
                printf("%d ",s[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
