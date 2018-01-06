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
string s[maxn];
vector< pair<int,int> >a;
char ans[3*maxn];
int main()
{
	int n;
	scanf("%d",&n);
	CL(ans);
	for (int i = 0;i < n;i++){
		int k,p;
		cin >> s[i] >> k;
		for (int j = 0;j < k;j++){
			cin >> p;
			a.push_back(make_pair(p,i));
		}
	}
	sort(a.begin(),a.end());
	int len = 1;
	for (int i = 0;i < a.size();i++){
		int t1 = a[i].first;
		int t2 = a[i].second;
		while (t1 > len){
			ans[len-1] = 'a';
			len++;
		}
		for (int j = len - t1;j < s[t2].length();j++){
			ans[len-1] = s[t2][j];
			len++;
		}
	}
	cout << ans <<endl;
	return 0;
}
