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
const int maxn = 1e6 + 100;
const int MAX = 1e4;
int f[maxn];
int w[10];
int main()
{
	w[1] = 150;
	w[2] = 200;
	w[3] = 350;
	int t;
	int m;
	for (int i = 1;i <= 3;i++){
        for (int j = MAX;j >= w[i];j--){
            for (int k = 1;k * w[i] <=j;k++){
                f[j] = max(f[j],f[j-k*w[i]] + k*w[i]);
            }
		}
    }	
	scanf("%d",&t);
	while (t--){
		scanf("%d",&m);	
		printf("%d\n",m-f[m]);
	}
	return 0;
}
