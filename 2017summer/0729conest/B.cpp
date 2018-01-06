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
char s[maxn];
int main()
{
	while (scanf("%s",s) != EOF){
		int len = strlen(s);
		if (len&1){
			printf("No\n");
			continue;
		}
		int k = len/2;
		int ans = 0;
		for (int i = 0;i < k;i++){
			int j = 0;
			for (j = 0;j < k;j++){
				if (s[i+j] != s[(i+k+j)])
					break;
			}
			if (j==k){
				ans = 1;
				break;
			}
		}
		if (ans){
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
	
	}
	return 0;
}
