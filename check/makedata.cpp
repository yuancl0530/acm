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
void creatseed();
LL GetTime();
/*****************************************************************************/
const LL maxdata = 1e4;//默认随机数最大值
//char str[]="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRTSUVWXYZ0123456789";
char str[]="ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
LL mrand(LL mod = maxdata);//获取一个随机数[1,n]
void randLine(int n,LL mod = maxdata);//获取n个随机数
void getStr(int n);//生成一个随机字符串
int main()
{
	creatseed();
	int T=mrand(12);
	cout<<T<<endl;
	while (T--){
		int n=mrand(100);
		cout<<n<<endl;
		for (int i=0;i<n;++i){
			getStr(mrand(100));
			cout<<" ";
		}
		cout<<endl;
	}
	return 0;
}

/***************************************************************************/
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
void getStr(int n)
{
	int len=strlen(str);
	for (int i=0;i<n;++i){
		int t=mrand()%len;
		cout<<str[t];
	}
}
/*************************************************************************/
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

