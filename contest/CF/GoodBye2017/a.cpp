/*********************************
Date: Fri Dec 29 23:41:17 CST 2017
Author: ycl
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
#define INF 0x7fffffff
#define INFLL 0x7fffffffffffffff
#define LL long long
const int MOD = 1e9 + 7;
const int maxn = 1e6 + 100;
char s[maxn];
bool check(char s)
{
    if (s == 'a' || s=='e' || s=='i' || s=='o' || s == 'u')
        return true;
    if (s == '1' || s=='3' || s=='5' || s=='7' || s=='9')
        return true;
    return false;
        
}
int main()
{
    cin>>s;
    int ans=0;
    for (int i=0;s[i];++i)
        if(check(s[i]))
           ++ans;
    cout<<ans<<endl;
	return 0;
}
