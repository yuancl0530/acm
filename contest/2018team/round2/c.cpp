/*********************************
Date: Fri Apr 20 13:24:35 CST 2018
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
#define ull unsigned long long
const int mod = 1e9 + 7;
const int maxn = 1e6 + 100;

int main()
{
	int s;
	char ch;
	while (scanf("%d",&s) != EOF){
		cin >> ch;
		int ans;
		if (ch == 'K'){
			if (s==1){
				ans = 1;
			}
			else {
				ans = 4;
			}
		}
		else if (ch == 'N'){
			if (s <= 2){
				ans = 1;
			}
			else {
				ans = 2;
			}
		}
		else if (ch == 'B'){
			ans = s;
		}
		else {
			ans = s;
		}
		printf("%d\n",ans);
	}
	return 0;
}
