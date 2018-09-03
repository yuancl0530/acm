#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
using namespace std;
const int maxn = 1e3 + 10;
struct Node{
    int len;
    char c;
    int from;
}lcs[maxn][maxn];
char a[maxn];
char b[maxn];
void fun(int x,int y)
{
    if (x < 0 || y < 0 ||lcs[x][y].len == 0)return ;
    if (lcs[x][y].from == 0)
        fun(x-1,y-1);
    else if (lcs[x][y].from == 1)
        fun(x-1,y);
    else
        fun(x,y-1);
    if (!lcs[x][y].from)
        printf("%c",lcs[x][y].c);
}
int main()
{
    while (scanf("%s",a) != EOF){
        scanf("%s",b);
        int end_i;
        int end_j;
        int ans_l = 0;
        memset(lcs,0,sizeof lcs);

        for (int i = 1;a[i-1];i++){
            for (int j = 1;b[j-1];j++){
                if (a[i-1] == b[j-1]){
                    lcs[i][j].len = lcs[i-1][j-1].len+1;
                    lcs[i][j].c = a[i-1];
                    lcs[i][j].from = 0;
                    if (lcs[i][j].len> ans_l){
                        end_i = i;
                        end_j = j;
                        ans_l = lcs[i-1][j-1].len + 1;
                    }
                }
                else {
                    if (lcs[i-1][j].len > lcs[i][j-1].len){
                        lcs[i][j].len = lcs[i-1][j].len;
                        lcs[i][j].c = lcs[i-1][j].c;
                        lcs[i][j].from = 1;
                    }
                    else {
                        lcs[i][j].len = lcs[i][j-1].len;
                        lcs[i][j].c = lcs[i][j-1].c;
                        lcs[i][j].from = 2;
                    }
                }
            }
        }
        fun(end_i,end_j);
        cout<<endl;
        memset(a,0,sizeof a);
        memset(b,0,sizeof b);
    }

    return 0;
}
