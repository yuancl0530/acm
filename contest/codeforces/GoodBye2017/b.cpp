/*********************************
Date: Fri Dec 29 23:54:40 CST 2017
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
int cnt = 0;
int vs[5];
int token[10];
int f[30][10];
void dfs(int n)
{
    for (int i=0;i<4;++i){
        if (vs[i]) continue;
        token[n]=i;
        if (n==3){
            for (int j=0;j<4;++j){
                f[cnt][j]=token[j];
            }
            cnt++;
        }
        vs[i]=1;
        dfs(n+1);
        vs[i]=0;
    }
}
char M[110][110];
char s[120];
int n,m;
int X1,X2,Y1,Y2;
bool check(int tt)
{
    int x1=X1;
    int y1=Y1;
    for (int i=0;s[i];++i){
        int t = f[tt][s[i]-'0'];
        if (t == 0)
            ++y1;
        else if (t == 1)
            --y1;
        else if (t == 2)
            --x1;
        else
            ++x1;
        if (x1 < 0 || x1 >= n)
            return false;
        if (y1<0 || y1 >=m)
            return false;
        if (M[x1][y1] == '#')
            return false;
        if (x1 == X2 && y1 == Y2)
            return true;
    }
    if (x1 == X2 && y1 == Y2)
        return true;
    return false;
}
int main()
{
    dfs(0);
    scanf("%d%d",&n,&m);
    for (int i=0;i<n;++i)
        scanf("%s",M[i]);
    for (int i=0;i<n;++i)
        for (int j=0;j<m;++j){
            if (M[i][j] == 'S')
                X1=i,Y1=j;
            if (M[i][j] == 'E')
                X2=i,Y2=j;
        }
    int ans=0;
    cin>>s;
    for (int i=0;i<cnt;++i){
       if ( check(i)){
           ++ans;
       }
    }
    printf("%d\n",ans);
	return 0;
}
