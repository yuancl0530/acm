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
using namespace std;
#define CL(a) memset(a,0,sizeof(a))
#define Cl(a,b) memset(a,b,sizeof(a))
#define INF 0x7fffffff
#define LL long long
const int maxn = 1e6 + 100;
LL num[maxn];
int cnt = 0;
void dfs(LL n)
{
	if (n > 1e18+1e17)
		return;
	num[cnt++] = n;
	dfs(n*10);
	dfs(n*10+1);
}
int main()
{
	LL n;
	dfs(1);
	cout << cnt<<endl;
	sort(num,num+cnt);
	cout << num[cnt-1] <<endl;
	while (scanf("%lld",&n) != EOF){
		printf("%4lld->",n);
		if (n == 3 || n==33 || n==333 || n==3333 || n==33333 || n==333333){
			while (n){
				cout << 111;
				n/=10;
			}
			cout << endl;
			continue;
		}
		else if(n == 9 || n== 99 || n== 999 || n==9999 || n==99999 | n==999999){
			while (n){
				cout << 111111111;
				n/=10;
			}
			cout << endl;
			continue;

		}
		int l = 0;
		int r = cnt;
		int mid;
		while (l+1 < r){
			mid = (l+r)>>1;
			if (n < num[mid]){
				r = mid;
			}
			else{
				l = mid;
			}
		}
		int k = l;
		//cout << num[k] <<endl;
		for (int i = k;i < cnt;i++){
			if (num[i] >= n && num[i]%n ==0){
				printf("%lld\n",num[i]);
				break;
			}
		}
		}
	return 0;
}
