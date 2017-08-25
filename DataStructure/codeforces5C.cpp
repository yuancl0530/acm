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
stack<char> S;
char a[maxn];
int main()
{
	while (scanf("%s",a) != EOF){
		while (!S.empty()) S.pop();
		int ans = 0,n = 0,sum = 0;
		int len = strlen(a);
		for (int i = 0;i <= len;i++){
			if (a[i] == '(' || !a[i]){
				S.push(a[i]);
				ans = max(ans,2*sum);
				if (sum)n++;
				sum = 0;
			}
			else{
				if (S.size() && S.top() == '('){
					sum++;
					S.pop();
				}
				else{
					S.push(a[i]);
				}
			}
		}
		printf("%d %d\n",ans,ans==0? 1:n);
	}
	return 0;
}
