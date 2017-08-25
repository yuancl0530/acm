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
int son[maxn];
int father[maxn];
int main()
{
	int T;
	scanf("%d",&T);
	while (T--){
		int n,k;
		CL(father);
		CL(deg);
		scanf("%d%d",&n,&k);
		for (int i = 1;i < n;i++){
			scanf("%d",&k);
			son[k]++;
			father[i+1] = k;
		}
		bool ans = 0;
		for (int i = 1;i <= n;i++){
			if (son[i]==0){
				if (father[i] && son[father[i]]>=2){
					ans = 1;
					break;
				}
				if (father[i] && deg[father[i]] == 1 && deg[father[father[i]]] == 2){
					ans = 1;
					break;
				}
			}
		}
		if (ans)
			cout <<"Alice"<<endl;
		else
			cout <<"Bob"<<endl;
	}


	return 0;
}
