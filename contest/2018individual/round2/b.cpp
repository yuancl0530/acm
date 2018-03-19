/*********************************
Date: Sat Mar 10 16:11:32 CST 2018
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
#define LL long long
const int MOD = 1e9 + 7;
const int maxn = 1e6 + 100;
struct Node
{
	int v;
	int t;
	friend bool operator < (Node a,Node b)
	{
		return a.v<b.v;
	}
}a[5];
char s[10];
int num[5];
int val()
{
	for (int i=0;i<4;++i)
		num[a[i].t]++;
	int ret=0;
	for (int i=0;i<4;++i)
		if (num[i])
			++ret;
	if (ret==1)
		return 3;
	return 4;
}
int main()
{
	for (int i=0;i<4;++i){
		scanf("%s",s);
		int len = strlen(s);
		if (len == 3){
			a[i].v=10;
		}
		else {
			if (s[0] == 'J')
				a[i].v=11;
			else if (s[0] =='Q')
				a[i].v=12;
			else if (s[0] =='K')
				a[i].v=13;
			else if (s[0]=='A')
				a[i].v=14;
			else
				a[i].v=s[0]-'0';
		}
		if (s[len-1] == 'S')
			a[i].t=0;
		else if (s[len-1] == 'H')
			a[i].t=1;
		else if (s[len-1] == 'C')
			a[i].t=2;
		else 
			a[i].t=3;
	}	
	sort(a,a+4);
	int v = val();
	int t1=0,t2=48;
	if (a[3].v-a[0].v==3){
		if (a[0].v>2)
			t1+=v;
		if (a[3].v<14)
			t1+=v;
	}
	else if (a[3].v-a[0].v == 4){
		t1+=v;
	}
	if (t1==0){
		printf("0/1\n");
	}
	else{
		for (int i=2;i<=48;++i)
			while (t1%i==0 && t2%i==0){
				t1/=i;
				t2/=i;
			}
		printf("%d/%d\n",t1,t2);
	}
	return 0;
}
