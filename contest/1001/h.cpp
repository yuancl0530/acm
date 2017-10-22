/*********************************
Date: Sun Oct  1 17:03:31 CST 2017
*********************************/
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
#include <sstream>
using namespace std;
#define CL(a) memset(a,0,sizeof(a))
#define Cl(a,b) memset(a,b,sizeof(a))
#define MP(a,b) make_pair(a,b)
#define INF 0x7fffffffffffffff
#define LL long long
const int MOD = 1e9 + 7;
const int maxn = 1e5 + 100;
struct Node
{
	int value;
	LL suma;
	int va;
	LL sumb;
	int vb;
}a[maxn];
int main()
{
	int n;
	while (scanf("%d",&n) != EOF){
		for (int i=1;i<=n;++i)
			scanf("%d",&a[i].value);
		a[1].va=a[1].value;
		a[1].suma=0;
		for (int i=2;i<=n;++i){
			if (a[i].value>a[i-1].va){
				a[i].va=a[i].value;
			}
			else{
				a[i].va=a[i-1].va+1;
			}
			a[i].suma=a[i-1].suma+a[i].va-a[i].value;
		}
		a[n].sumb=0;
		a[n].vb=a[n].value;
		for (int i=n-1;i>=1;--i){
			if (a[i].value>a[i+1].vb){
				a[i].vb=a[i].value;
			}
			else{
				a[i].vb=a[i+1].vb+1;
			}
			a[i].sumb=a[i+1].sumb+a[i].vb-a[i].value;
		}
		LL ans=INF;
		for (int i=2;i<n;++i){
			ans=min(ans,a[i-1].suma+a[i+1].sumb+max(a[i].va,a[i].vb)-a[i].value);
		}
		ans=min(ans,min(a[1].sumb,a[n].suma));
		cout<<ans<<endl;
	}
	return 0;
}
