/*********************************
Date: Sat Sep  9 15:37:02 CST 2017
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
#define LL long long
const int MOD = 1e9 + 7;
const int maxn = 1e5 + 100;
char s[maxn];
int sum[maxn];
char t[20];
int lowbit(int x){return x&(-x);}
int lens;
int lent;
int Sum(int n)
{
	int ret=0;
	while (n>0){
		ret+=sum[n];
		n-=lowbit(n);
	}
	return ret;
}
void update(int n,int d)
{
	while (n<=lens) {
		sum[n]+=d;
		n+=lowbit(n);
	}
}
void cal()
{
	bool flag=1;
	for (int i=1;i<=lens;++i){
		flag=1;
		for (int j=1;j<=lent;++j){
			if (s[i+j-1]!=t[j]){
				flag=0;
				break;
			}
		}
		if (flag){
			update(i,1);
		}
	}
}
void change(int pos,char c)
{	
	char tt=s[pos];
	if (c==tt)return ;
	for (int i=pos;i>0&&i>=pos-lent+1;--i){
		int tmp=1;
		for (int j=1;j<=lent;++j){
			if (s[i+j-1]!=t[j]){
				tmp=0;
				break;
			}
		}

		int flag=1;
		s[pos]=c;
		for (int j=1;j<=lent;++j){
			if (s[i+j-1]!=t[j]){
				flag=0;
				break;
			}
		}
		if (flag!=tmp)
			update(i,flag-tmp);
		s[pos]=tt;
	}
	s[pos]=c;
}
char op[5];
int main()
{
	int T;
	int n;
	scanf("%d",&T);
	int x,y;
	char c;
	while (T--){
		CL(sum);
		scanf("%d%s%s",&n,s+1,t+1);
		lens=strlen(s);
		lent=strlen(t);
		cal();
		while(n--){
			scanf("%s",op);
			if (op[0]=='Q'){
				scanf("%d%d",&x,&y);
				int tmp;
				if (y-x+1<lent)
					tmp=0;
				else 
					tmp=Sum(y-lent+1)-Sum(x-1);
				printf("%d\n",tmp);
			}
			else{
				scanf("%d%s",&x,op);
				change(x,op[0]);
			}
		}
	}
	return 0;
}
