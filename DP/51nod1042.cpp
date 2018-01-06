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
const int MOD = 1e9 + 7;
const int maxn = 1e6 + 100;
LL dp[20];
int bit[30];
LL a[30];
LL b[30];
LL test[20];
int fun(LL n)
{
	for (int i = 1;i <= n;i++){
		int t = i;
		while (t){
			test[t%10]++;
			t/=10;
		}
	}
}
void cal(LL n,LL * a)
{
	int cnt = 0;
	LL t = n;
	LL m = 1;
	while (t){
		bit[++cnt] = t % 10;
		t /= 10;
		m*=10;
	}
	for (int i = cnt;i >= 1;i--){
		m /= 10;
		if (bit[i] == 0){
			a[0] += n%m ;
			continue;
		}
		for (int j = 0;j <= 9;j++){
			if (i == cnt && j== 0){
				a[j] += i-1;
				a[j] += (bit[i]-1)*dp[i-1];
				for (int k = 1;k < i-1;k++){
					a[j] += 9*dp[k];
				}
				
				continue;
			}
			a[j] += bit[i] * dp[i-1];
		}
		for (int j = 1;j < bit[i];j++){
//			if (i==cnt && j==0) continue;
			a[j] += m;
		}
		if (i!=cnt)a[0] += m-1;
		a[bit[i]] += n%m + 1;
	}
	

}

int main()
{
	
	for (int i = 1;i <= 19;i++){
		dp[i] = i * pow(10,i-1);
	}
	LL p,q;
	while (cin >>p>>q){
		CL(a);
		CL(b);
	//	CL(test);
		cal(p-1,a);
	//	fun(p);
		cal(q,b);
		for (int i = 0;i <= 9;i++){
			cout <<b[i]-a[i]<<endl;
		}
	}

	return 0;
}
