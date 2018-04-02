#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cstring>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <bitset>
#include <algorithm>
#include <functional>
#include <iomanip>
using namespace std;

#define LL long long
const int maxn = 100000 + 100;
char str1[maxn], str2[maxn];
int Next[maxn];

void get_next(char *str) {
    int j = 0;
    Next[1] = j;
    for(int i = 2; str[i]; ++i) {
        while(j != 0 && str[j + 1] != str[i]) {
            j = Next[j];
        }
        if(str[j + 1] == str[i]) {
            ++j;
        }
        Next[i] = j;
    }
}

int kmp(char *str1, char *str2) {
    int j = 0;
    for(int i = 1; str1[i]; ++i) {
        while(j != 0 && str2[j + 1] != str1[i]) {
            j = Next[j];
        }
        if(str1[i] == str2[j + 1]) {
            ++j;
        }
        if(str2[j + 1] == '\0' && str1[i + 1] != '\0') {
            j = Next[j];
        }
    }
    return j + 1;
}

int main() {
    #ifdef LOCAL
    freopen("test.txt", "r", stdin);
//    freopen("test1.out", "w", stdout);
    #endif // LOCAL
    ios::sync_with_stdio(false);

    while(scanf("%s%s", str1 + 1, str2 + 1) != EOF) {
        get_next(str2);
        int j2 = kmp(str1, str2);
        get_next(str1);
        int j1 = kmp(str2, str1);
        if(j1 > j2) {
            printf("%s%s\n", str2 + 1, str1 + j1);
        } else if(j2 > j1) {
            printf("%s%s\n", str1 + 1, str2 + j2);
        } else {
            if(strcmp(str1 + 1, str2 + 1) < 0) {
                printf("%s%s\n", str1 + 1, str2 + j2);
            } else {
                printf("%s%s\n", str2 + 1, str1 + j1);
            }
        }
    }

    return 0;
}
