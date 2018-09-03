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
	int T;
	scanf("%d",&T);
	while (T--){
		double r,x1,x2,y1,y2;
		scanf("%lf%lf%lf%lf%lf",&r,&x1,&y1,&x2,&y2);
		double a = sqrt(x1*x1+y1*y1);
		double b = sqrt(x2*x2+y2*y2);
		double pq = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
		
		printf("%.6lf\n",2*ans);
	}


	return 0;
}
