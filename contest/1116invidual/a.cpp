/*********************************
Date: Thu Nov 16 19:03:37 CST 2017
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
char num[4][3];
bool check(char *s)
{
	for (int i=0;s[i];++i){
		int t=s[i]-'0';
		if (t==0)
			num[3][1]=1;
		else{
			num[(t-1)/3][(t+2)%3]=1;
		}
	}
	num[3][0]=2;
	num[3][2]=2;
	int n=4;
	int m=3;
	int f=1;
	for (int i=0;i<n;++i){
		for (int j=0;j<m;++j){
			if (num[i][j]==1){
				if (i-1<0) {
					f=0;
					break;
				}
			}
		}
	}
	if (f) return true;
	f=1;
	for (int i=0;i<n;++i){
		for (int j=0;j<m;++j){
			if (num[i][j]==1){
				if (j-1<0 || num[i][j-1]==2) {
					f=0;
					break;
				}
			}
		}
	}
	if (f) return true;
	f=1;
	for (int i=0;i<n;++i){
		for (int j=0;j<m;++j){
			if (num[i][j]==1){
				if (j+1>=m || num[i][j+1]==2) {
					f=0;
					break;
				}
			}
		}
	}
	if (f) return true;
	f=1;
	for (int i=0;i<n;++i){
		for (int j=0;j<m;++j){
			if (num[i][j]==1){
				if (i+1>=n || num[i+1][j]==2) {
					f=0;
					break;
				}
			}
		}
	}
	if (f) return true;
	return false;
}
char s[maxn];
int main()
{
	int n;
	scanf("%d%s",&n,s);
	if (check(s))
		cout<<"NO"<<endl;
	else
		cout<<"YES"<<endl;

	return 0;
}
