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
	int n,k;
	int m;
	while (scanf("%d%d",&n,&k) != EOF){
		int t = (n-1)/k;
		int temp = n-1-t*k;
		m = 0;
		if (k == 2){
			printf("%d\n",n-1);
		}
		else{
			if (temp == 0)
				printf("%d\n",2*t);
			else if (temp == 1){
				printf("%d\n",2*t+1);
			}
			else 
				printf("%d\n",2*(t+1));
		}
		for (int i = 2;i <= n;i++){
			if (i !=2 &&((temp > 0 && m % (t+1) == 0) ||(temp<=0 && m%t==0))){
				m = 0;
				temp--;
			}
			if (m == 0){
				printf("%d %d\n",1,i);
			}
			else printf("%d %d\n",i-1,i);
			m++;
		}
	}
	return 0;
}
