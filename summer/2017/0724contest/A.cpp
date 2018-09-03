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
const int maxn = 1e4 + 10;
char Map[5][5][10] ={{"***", "***","***", "***", "***"},
    {"*.*", "*.*","*..", "*.*", "*.."},
    {"***", "***","*..", "*.*", "***"},
    {"*.*", "*.*","*..", "*.*", "***"},
    {"*.*", "***","***", "***", "***"}},str[maxn];
int main()
{
    int n;
    while (scanf("%d",&n) != EOF){
        scanf("%s",str);
        for (int i = 0;i < 5;i++){
            for (int j = 0; str[j];j++){
                printf("%s",Map[i][(str[j]-'A')]);
            }
            printf("\n");
        }
    }
    return 0;
}

