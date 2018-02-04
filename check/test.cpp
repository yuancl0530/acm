#include <bits/stdc++.h>
using namespace std;
int n;
int a[200010];
char c[200010];
int main(int argc, char const *argv[]) {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    getchar();
    int pre = -1;
    for (int i = 1; i < n; i++) {
        c[i] = getchar();
        if (c[i] == '0') {
            if (pre != -1) {
                sort(a + pre, a + i + 1);
                // std::cout << pre << " " << i << '\n';
            } else {
                sort(a + 1, a + i + 1);
            }
            pre = i + 1;
        }
    }
    if (pre != n && pre != -1) {
        sort(a + pre, a + n + 1);
    }
    if (pre == -1) {
        sort(a + 1, a + n + 1);
    }
    bool fl = 1;
    for (int i = 2; i <= n; i++) {
        if (a[i] < a[i - 1]) {
            fl = 0;
            break;
        }
    }
    if (fl) {
        puts("YES");
    } else {
        puts("NO");
    }
    return 0;
}
