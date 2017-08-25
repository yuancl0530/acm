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
const int maxn = 1e5 + 100;
LL f[maxn];
const int Max = 1e5 ;
int main()
{
	int n;
	int w[] = {1,2,5,10,20,50,100,200,500,1000,2000,5000,10000};
	f[0] = 1;
	for (int i = 0;i < 13;i++){
		for (int j = 1;j <= Max;j++){
			if (j-w[i] >= 0){
				f[j] = (f[j]+f[j-w[i]]) % MOD;
			}
		}
	}	
//	cout <<"**"<<endl;
	while (scanf("%d",&n) != EOF){
		printf("%lld\n",f[n]);
	}
	return 0;
}
