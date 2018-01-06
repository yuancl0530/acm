#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <queue>
#define ll long long
using namespace std;
const int maxn = 1e6 + 10;
int belong[maxn];
char str[20];
queue<int>Q;
queue<int>qu[1010];
int main()
{
    int t;
    int cnt = 0;
    while (scanf("%d",&t) != EOF && t){
        printf("Scenario #%d\n",++cnt);
        memset(belong,-1,sizeof (belong));
        while (!Q.empty())
            Q.pop();
        for (int i = 0;i < 1001;i++){
            while (!qu[i].empty())
                qu[i].pop();
        }
        for (int i = 0;i < t;i++){
            int k ;
            int m;
            scanf("%d",&k);
            for (int j = 0;j < k;j++){
                scanf("%d",&m);
                belong[m] = i;
            }
        }
        while (1){
            scanf("%s",str);
            if (!strcmp(str,"ENQUEUE")){
                int x;
                scanf("%d",&x);
                int k = belong[x];
                if (qu[k].empty()){
                    Q.push(k);
                    qu[k].push(x);
                }
                else{
                    qu[k].push(x);
                }
            }
            else if (!strcmp(str,"DEQUEUE")){
                int x = Q.front();
                printf("%d\n",qu[x].front());
                qu[x].pop();
                if (qu[x].empty()){
                    Q.pop();
                }
            }
            else{
                break;
            }
        }
        printf("\n");

    }
    return 0;
}
