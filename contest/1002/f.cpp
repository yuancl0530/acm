/*********************************
Date: Mon Oct  2 15:09:26 CST 2017
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
const char a[]="heidi";
char s[maxn];
int c[10];
int main()
{
	while (scanf("%s",s) != EOF){
		CL(c);
		for (int i=0;s[i];++i){
			if (s[i]=='h')
				++c[0];
			else if (s[i]=='e')
				c[1]=min(c[0],c[1]+1);
			else if (s[i]=='i'){
				c[2]=min(c[2]+1,c[1]);
				c[4]=min(c[4]+1,c[3]);
			}
			else if (s[i]=='d')
				c[3]=min(c[3]+1,c[2]);
		}
		if (c[4])
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;
}
