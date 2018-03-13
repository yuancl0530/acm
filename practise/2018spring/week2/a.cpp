/*********************************
Date: Tue Mar 13 19:24:50 CST 2018
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
map<int,int> xx;
map<int,int> yy;
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	int x,y;
	char s[5];
	char &op=s[0];
	map<int,int>::iterator it;
	int ans;
	for (int i=0;i<m;++i){
		scanf("%d%d%s",&x,&y,s);
		if (op == 'U'){
			it = xx.lower_bound(x);
			if (xx.count(x)){
				ans = 0;
			}
			else {
				if (it == xx.end()){
					ans=y;
				}
				else{
					ans=y - (it->second);
				}
				xx[x] = y-ans;
				yy[y] = x;
			}
				
		}
		else {
			it = yy.lower_bound(y);
			if (yy.count(y)){
				ans = 0;
			}
			else {
				if (it == yy.end()){
					ans = x;
				}
				else {
					ans = x-(it->second);
				}
				yy[y] = x-ans;
				xx[x] = y;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
