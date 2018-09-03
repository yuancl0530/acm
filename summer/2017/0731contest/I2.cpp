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
bool check(char a)
{
	if (a == 'A' || a=='I'||a == 'H' || a == 'M' || a == 'O' || a == 'T'
	|| a == 'U' || a== 'V' || a == 'W' || a == 'X' || a == 'Y')
		return true;
	return false;
}
char a[maxn];
int main()
{
	int t;
	scanf("%d",&t);
	while (t--){
		scanf("%s",a);
		int  ans = 0;
		int len = strlen(a);
		for (int i = 0;i < len;i++){
			int left;
			int right;
			left = right = i;
		//	cout << a[i] <<endl;
			while (left >=0 && right < len && a[left] == a[right] && check(a[left]) && check(a[right])){
				ans = max(right - left + 1,ans);
				left--;
				right++;
			}
			left = i;
			right = i + 1;
			while (left >=0 && right < len && a[left] == a[right] && check(a[left]) && check(a[right])){
				ans = max(right - left + 1,ans);
				left--;
				right++;
			}
		}
		printf("%d\n",ans);
	
	}
	return 0;
}
