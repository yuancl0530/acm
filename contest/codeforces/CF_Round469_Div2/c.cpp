/*********************************
Date: Sat Mar 10 09:45:57 CST 2018
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
char s[maxn];
vector<int> V[maxn];
int cnt=0;
queue<int>Q0,Q1;
bool save(int t,int v)
{
	if (v==0){
		if (Q1.empty()){
			V[cnt].push_back(t);
			Q0.push(cnt++);
		}
		else{
			V[Q1.front()].push_back(t);
			Q0.push(Q1.front());
			Q1.pop();
		}
	}
	else {
		if (Q0.empty())
			return false;
		else{
			V[Q0.front()].push_back(t);
			Q1.push(Q0.front());
			Q0.pop();
		}
	}
	return true;
}
int main()
{
	scanf("%s",s+1);
	for (int i=1;s[i];++i){
		if (!save(i,s[i]-'0')){
			cnt=-1;
			break;
		}
	}
	if (!Q1.empty())
		cnt=-1;
	printf("%d\n",cnt);
	for (int i=0;i<cnt;++i){
		printf("%d ",(int)V[i].size());
		for (int j=0;j<V[i].size();++j)
			printf("%d ",V[i][j]);
		printf("\n");
	}
	return 0;
}
