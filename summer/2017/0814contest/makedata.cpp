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
const LL maxdata = 1e6;
/*************************/
const LL R[] = {1e1,1e2,1e3,1e4,1e5,1e6,1e7,1e8,1e9,1e10,1e11,1e12,1e13,1e14,1e15};
LL mrand(LL mod = maxdata);
void randLine(int n,LL mod = maxdata);


int main()
{
	srand((int)time(0));
	int t = mrand() % 20;
	cout<<t<<endl;
	randLine(t,1);
	return 0;
}



LL mrand(LL mod)
{
	return rand()%mod%(R[rand()%15])+1;
}
void randLine(int n,LL mod)
{
	for (int i = 1;i <= n;i++){
		cout<<mrand(mod)<<" ";
	}
	cout<<endl;
}

