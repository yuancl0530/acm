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
const int maxn = 2e5 + 100;
char s[maxn];
struct Node
{
	int l;
	int r;
}a[maxn];
int main()
{
	int t;
	scanf("%d",&t);
	while (t--){
		int n;
		scanf("%d",&n);
		scanf("%s",s);
		int cnt = 0;
		int sum = 0;
		for (int i = 0;s[i];i++){
			if (s[i] == '0'){
				sum++;
				if (i+1==n){
					a[cnt].r = sum;
				}
			}
			else{
				a[cnt].r = sum;
				a[++cnt].l = sum;
				sum = 0;
			}
		}
	/*	for (int i = 1;i <= cnt;i++){
			printf("%d %d\n",a[i].l,a[i].r);
		}*/

		LL ans = 0;
	/*	int t = (cnt-2)/2;
		ans += t*(1+t);
		if (cnt&1){
			ans += cnt/2+1;
		}*/
	//	cout << ans << endl;
		for (int i = 1;i <= cnt;i++){
			for (int j = 0;i-j >= 1 && i+j <= cnt;j++){
				if (!j){
					ans += a[i-j].l * a[i+j].r;
				}
				else{
					ans += (a[i-j].l+1) * (a[i+j].r+1);
				//	cout <<"*"<<endl;
				}
			}
		
		}
		printf("%lld\n",ans);
	}
	return 0;
}
