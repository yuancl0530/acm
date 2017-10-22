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
#include <sys/time.h>
using namespace std;
#define CL(a) memset(a,0,sizeof(a))
#define Cl(a,b) memset(a,b,sizeof(a))
#define INF 0x7fffffff
#define LL long long
const int maxn = 1e6 + 100;
const LL maxdata = 1e2;//随机数最大值
void creatseed();
LL GetTime();
LL mrand(LL mod = maxdata);//获取一个随机数
void randLine(int n,LL mod = maxdata);//获取n个随机数
int main()
{
	creatseed();
	int t=120000;
	while (t--)
		cout<<10100<<" "<<10000<<endl;
	return 0;
}

/*****************************/
LL mrand(LL mod)
{
	return rand()%mod+1;
}
void randLine(int n,LL mod)
{
	for (int i = 1;i <= n;i++){
		cout<<mrand(mod)<<" ";
	}
	cout<<endl;
}


LL GetTime()
{
	struct timeval tv;
	gettimeofday(&tv,NULL);
	return tv.tv_sec * 1000 + tv.tv_usec / 1000;
}
void creatseed()
{
	LL seed = GetTime();
	srand(seed);
}

