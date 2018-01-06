/*********************************
Date: Fri Aug 25 09:50:39 CST 2017
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
#define INF 0x7fffffff
#define LL long long
const int MOD = 1e9 + 7;
const int maxn = 1e6 + 100;
int bit[maxn];
void getBit(int n)
{
	int cnt=0;
	while (n){
		bit[cnt++]=n&1;
		n>>=1;
	}
	bit[cnt]=0;
}
int main()
{
	int T;
	scanf("%d",&T);
	for (int casee=1;casee<=T;++casee){
		printf("Case #%d:\n",casee);
		CL(bit);
		int n,m;
		scanf("%d%d",&n,&m);
		int tt=pow(2,m-1);
		getBit(tt-(n+1)/2);
		int t=1;
		for (int i=0;i<m;i++){
			if (i!=m-1){
				if (bit[i]&1)
					printf("%d -\n",t);
				else
					printf("%d +\n",t);
			}
			else{
				printf("%d +\n",n&1? t:t+1);
			}
			t<<=1;
		}
	}



	return 0;
}
