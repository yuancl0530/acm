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
char s[maxn];
int main()
{
	int n;
	while (scanf("%d%*c",&n) != EOF){
		int sum = 0;
		int ans = 0;
		gets(s);
		//cout<<s<<endl;
		for (int i =0 ;i < n;i++){
			if (isupper(s[i])){
				sum++;
				ans = max(sum,ans);
			}
			if (s[i] == ' ' || !s[i]){
				sum = 0;
			}
		}
		printf("%d\n",ans);
	
	}


	return 0;
}
