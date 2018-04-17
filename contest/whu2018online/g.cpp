/*********************************
Date: Sun Apr 15 15:29:15 CST 2018
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
#include <set>
#include <sstream>
using namespace std;
#define CL(a) memset(a,0,sizeof(a))
#define Cl(a,b) memset(a,b,sizeof(a))
#define MP(a,b) make_pair(a,b)
#define INF 0x7fffffff
#define LL long long
const int mod = 1e9 + 7;
const int maxn = 1e6 + 100;
int d[]={5,3,4,3,4,3};
int v[10];
int t[10];
int main()
{
	vector<int>V;
	int start=0;
	for (int i=0;i<7;++i){
		if (d[i]==5){
			for (int j=0;j<n;++j){
				printf("%d ",start+i);
				t[j]=start+i;
			}
			fflush(stdout);
		}
		else if ()
		for (int i=0;i<5;++i){
			scanf("%d",&v[i]);
		}
		for (int i=0;i<5;++i){
			if (v[i]==1){
				V.push_back(t[v[i]]);
			}
		}
		for (int i=0;i<5;++i){
			if (v[i]==2){
				V.push_back(t[v[i]]);
			}
		}
		start+=d[i];
	}
	return 0;
}
