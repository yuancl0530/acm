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
char s[50100];
int main()
{
	srand((int)time(0));
	int t = 100;
	cout << 100 <<endl;
	while (t--){
	cout << rand()%5000<<endl;
	for (int i = 0;i < 5000;i++){
		s[i] = 'a' + rand() % 25;
	}
	cout << s <<endl;
	}
	return 0;
}
