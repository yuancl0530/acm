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
const int maxn = 1e6 + 100;
int a[maxn];
int main()
{
	int n,k;
	int ans = 1;
	int s = 1;
	cin >> k >> n;
	for (int i = 0;i < n;i++){
		s = s*k + 1;
		ans ^= s;
		cout << ans <<endl;
	}


	return 0;
}
