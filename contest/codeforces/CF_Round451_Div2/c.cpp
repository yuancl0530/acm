/*********************************
Date: Sat Dec 16 20:13:16 CST 2017
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
map<string,int>M;
int Id=0;
char s[25][100][100];
int num[100];
char a[100][100];
bool check(char *a,char *b)
{
    int lena=strlen(a)-1;
    int lenb=strlen(b)-1;
    while (lena >=0 && lenb>=0){
        if (a[lena]!=b[lenb])
            return false;
        --lena;
        --lenb;
    }
    if (lena>=0) return false;
    return true;
}
void solve(int t)
{
    int tmp=0;
    for (int i=0;i<num[t];++i){
        for (int j=0;j<num[t];++j){
            if (s[t][i][0]==0)continue;
            if (i!=j && s[t][j][0] && check(s[t][i],s[t][j])){
                tmp++;
                s[t][i][0]=0;
                break;
            }
        }
    }
    cout<<num[t]-tmp<<" ";
    for (int i=0;i<num[t];++i){
        if (s[t][i][0])
            cout<<s[t][i]<<" ";
    }
    printf("\n");
}
int main()
{
    int n,m;
    cin>>n;
    for (int i=0;i<n;++i){
        cin>>a[i];
        if (M[a[i]]==0)
            M[a[i]]=++Id;
        cin>>m;
        int t=M[a[i]];
        for (int j=0;j<m;++j){
            cin>>s[t][num[t]++];
        }
    }
    cout<<Id<<endl;
    for (int i=0;i<n;++i){
        int t=M[a[i]];
        if (num[t]==0)continue;
        cout<<a[i]<<" ";
        solve(t);
        num[t]=0;
    }
	return 0;
}
