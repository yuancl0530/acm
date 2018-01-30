/*********************************
Date: Tue Jan 30 20:51:28 CST 2018
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
int ans[maxn];
int main()
{
	scanf("%s",s);
	stack<int>S1;
	stack<pair<int,int> >S2;
	int sum=0;

	for (int i=0;s[i];++i){
		if (s[i] == '\\')
			S1.push(i);
		else if (!S1.empty() && s[i] == '/'){
			int j =  S1.top();
			S1.pop();
			sum += i - j;
			int t = i - j; 
			while (!S2.empty() && S2.top().first > j){
				t+=S2.top().second;
				S2.pop();
			}
			S2.push(MP(j,t));
		}
	}
	printf("%d\n",sum);
	int cnt = 0;
	while (!S2.empty()){
		ans[cnt++] = S2.top().second;
		S2.pop();
	}
	printf("%d",cnt);
	for (int i=cnt-1;i>=0;--i)
		printf(" %d",ans[i]);
	printf("\n");
	return 0;
}
