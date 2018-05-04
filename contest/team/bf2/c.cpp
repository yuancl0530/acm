/*********************************
Date: Thu May  3 15:34:08 CST 2018
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
#define ll long long
const int mod = 1e9 + 7;
const int maxn = 1e6 + 100;
int dis[maxn];
void getbit(int *t,int v)
{
	for (int i=0;i<6;++i){
		t[i] = v%6;
		v /= 6;
	}
}
int getid(int *t){
	int v = 0;
	for (int i=5;i>=0;--i){
		v = v*6 + t[i];
	}
	return v;
}
void init()
{
	static int tmp[10] = {0,1,2,3,4,5};
	int s = gitid(tmp);
	queue<int> Q;
	Q.push(s);
	dis[s] = 0;
	while (!Q.empty()){
		
	}
}

int main()
{
	
	return 0;
}
