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
using namespace std;
#define CL(a) memset(a,0,sizeof(a))
#define Cl(a,b) memset(a,b,sizeof(a))
#define INF 0x7fffffff
#define LL long long
const int MOD = 1e9 + 7;
const int maxn = 1e6 + 100;

int main()
{
	int n,a,b,c;
	int cn;
	while (scanf("%d%d%d",&n,&a,&b) != EOF){
		c = 0;
		int ans =0;
		for (int i = 0;i < n;i++){
			int x;
			scanf("%d",&x);
			if (x == 1){
				if (a>0){
					a--;
				}
				else if (c<b){
					c++;
				}
				else if (c == b && b>0){
					c--;
					b--;
				}
				else ans++;
			}
			else if (x == 2){
				if (c < b){
					b--;
				}
				else ans+=2;
			}
		}
		printf("%d\n",ans);
	}


	return 0;
}
