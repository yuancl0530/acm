/*********************************
Date: Sat Oct 21 18:07:22 CST 2017
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
const int maxn = 1e3 + 100;
struct BigNum
{
	int d[maxn];
	int len;
	BigNum()
	{
		len=1;
		CL(d);
	}
	BigNum(const BigNum &a)
	{
		len=a.len;
		for (int i=0;i<len;++i)
			d[i]=a.d[i];
	}
	BigNum(const char *s)
	{
		len=strlen(s);
		int j=0;
		for (int i=len-1;i>=0;--i)
			d[i]=s[j++]-'0';
	}
	BigNum operator-(const BigNum &a)
	{
		int c=0;
		BigNum ret;
		for (int i=0;i<len;++i){
			ret.d[i]=(10+d[i]+c-a.d[i])%10;
		//	cout<<"-"<<ret.d[i]<<endl;
			if (d[i]+c>=a.d[i])
				c=0;
			else
				c=-1;
		}
		ret.len=len;
		while (ret.len>1 && ret.d[ret.len-1]==0)
			--ret.len;
		return ret;
	}
	int check()
	{
		if (len==1)
			return 0;
		int i=0;
		int j=len-1;
		while (i<j){
			if (d[i]!=d[j])
				return 1;
			++i;
			--j;
		}
		return 0;
	}
	bool check2()
	{
		if (d[len-1]==1){
			for (int i=0;i<len-1;++i)
				if (d[i])
					return 0;
			return 1;
		}
		return 0;
	}
	void print()
	{
		for (int i=len-1;i>=0;i--)
			printf("%d",d[i]);
		printf("\n");
	}
}ans[maxn];
char s[maxn];
int main()
{
	int T;
	scanf("%d",&T);
	BigNum b;
	BigNum c;
	for (int tt=1;tt<=T;++tt){
		scanf("%s",s);
		BigNum a(s);
		int cnt=0;	
		while (a.len/2){
			b=a;
			if (a.check()){
				int mid=a.len/2;
				if (a.len%2==1)++mid;
				if (a.check2())mid=0;
				c.d[mid]=1;
				b=b-c;
				//b.print();
				c.d[mid]=0;
				int ii=0;
				int jj=b.len-1;	
				while (ii<jj){
					b.d[ii]=b.d[jj];
					++ii;
					--jj;
				}
			}
			a=a-b;
			a.print();
			ans[cnt++]=b;
		}
		if (!(a.len==1 && a.d[0]==0))
			ans[cnt++]=a;
		printf("Case #%d: \n",tt);
		printf("%d\n",cnt);
		for (int i=0;i<cnt;++i)
			ans[i].print();
	}
	return 0;
}
