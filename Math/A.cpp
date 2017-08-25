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
int a[200];
int b[200];
int main()
{
	int n,m;
	while (cin >> n >>m){
		int t,k;
		CL(a);
		CL(b);
		cin >> t;
		while (t--){
			cin >> k;
			a[k] = 1;
		}
		cin >> t;
		while (t--){
			cin >> k;
			b[k] = 1;
		}
		k = max(n,m);
		for (int i = 0;i <= 2*k*k;i++){
			int t1 = i%n;
			int t2 = i%m;
			if (a[t1] == 1 || b[t2] == 1)
				a[t1] = b[t2] = 1;
		}
		bool flag = 1;
		for (int i = 0;i < n;i++)
			if (!a[i]) {flag = 0;break;}
		for (int i = 0;i < m;i++)
			if (!b[i]) {flag = 0;break;}
		if (flag)
			cout << "YES" <<endl;
		else
			cout << "NO" <<endl;
	}
	return 0;
}
