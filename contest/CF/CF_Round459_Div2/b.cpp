/*********************************
Date: Mon Jan 29 22:44:22 CST 2018
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
map<string,int>ip;
char name[1010][20];
char t1[100],t2[100],t3[100];
int main()
{
	int n,m;
	cin>>n>>m;
	for (int i=1;i<=n;++i){
		scanf("%s%s",name[i],t1);
		ip[t1]=i;
	}
	for (int i=0;i<m;++i){
		scanf("%s%s",t1,t2);
		int len = strlen(t2);
		t2[len-1]=0;
		cout<<t1<<" "<<t2<<"; #"<<name[ip[t2]]<<endl;
	}


	return 0;
}
