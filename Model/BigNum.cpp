/*********************************
Date: Mon Oct 16 15:17:02 CST 2017
Author: ycl
*********************************/
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
#define MP(a,b) make_pair(a,b)
#define INF 0x7fffffff
#define INFLL 0x7fffffffffffffff
#define LL long long
const int MOD = 1e9 + 7;
const int maxn = 1e6 + 100;
class BigNum
{
private:
	const int N=1000;
	int a[N];
	int len;
public:
	BigNum();
	BigNum(const BigNum &);
	BigNum(const int &);
	BigNum(const char *)
};
BigNum::BigNum()
{
	CL(a);
	len=1;
}
BigNum::BigNum(const BigNum &a)
{
	len=a.len;
	CL(a);
	for (int i=0;i<a.len;++i)
		a[i]=a.a[i];
}
BigNum::BigNum(const int &num)
{
	int x=1;
	int t=num;
	while (t/(x*10)) x*=10;
	while (t){
		a[len++]=t/x;
		t%=x;
		x/=10;
	}
}
BigNum
int main()
{



	return 0;
}
