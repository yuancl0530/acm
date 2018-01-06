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
#include <sstream>
using namespace std;
#define CL(a) memset(a,0,sizeof(a))
#define Cl(a,b) memset(a,b,sizeof(a))
#define INF 0x7fffffff
#define LL long long
const int MOD = 1e9 + 7;
const int maxn = 2e7 + 100;
int a[maxn],b[maxn];
int now,cnt;
int main()
{
	int T;
	scanf("%d",&T);
	while (T--){
		int n;
		scanf("%d",&n);
		a[1] = 1;
		a[2] = 2;
		a[3] = 1;
		b[1] = 1;
		b[2] = 2;
		now = 3;
		cnt = 3;
		for (int i = 3;cnt <= n;i++){
			if (i & 1){
				b[i] = a[now++];
				a[++cnt] = 1;
				if (b[i] == 2){
					a[++cnt] = 1;
				}
			}
			else{
				b[i] = a[now++];
				a[++cnt] = 2;
				if (b[i] == 2){
					a[++cnt] = 2;
				}
			}
		}
		cout << a[n] <<endl;
	}
	return 0;
}
