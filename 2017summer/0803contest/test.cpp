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
int cal(int n)
{
	int ret = 0;
	for (int i = 1;i <= n;i++){
		if (n%i==0)ret ++;
	}
	return ret;
}
int main()
{
	int sum = 0;
	int n;
	cin >> n;
	for (int i =n;i <= 10000;i*=n){
		sum += cal(i);
		printf("%d:%d\n",i,cal(i));
	}


	return 0;
}
