/*********************************
Date: Fri Apr 13 13:45:57 CST 2018
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
#include <set>
#include <sstream>
using namespace std;
#define CL(a) memset(a,0,sizeof(a))
#define Cl(a,b) memset(a,b,sizeof(a))
#define MP(a,b) make_pair(a,b)
#define INF 0x7fffffff
#define LL long long
const int mod = 1e9 + 7;
const int maxn = 2e5 + 100;
char s[5][maxn];
int cnt=0;
int a[maxn];
bool check(int x,int y,int z)
{
	if (x==y && y==z){
		for (int i=0;i<cnt;++i){
			if (i==x) continue;
			if (s[0][a[i]]!=s[1][a[i]] || s[0][a[i]]!=s[2][a[i]]) return false;
		}
	}
	else if (x==y){
		if (s[0][a[z]]!=s[1][a[z]]) return false;
		//if (s[2][a[x]]==s[0][a[x]] || s[2][a[x]]==s[1][a[x]]) return false;
		for (int i=0;i<cnt;++i){
			if (i==x || i==z) continue;
			if (s[0][a[i]]!=s[1][a[i]] || s[0][a[i]]!=s[2][a[i]]) return false;
		}
	}
	else if (x==z){
		if (s[0][a[y]]!=s[2][a[y]]) return false;
		//if (s[1][a[x]]==s[0][a[x]] || s[1][a[x]]==s[2][a[x]]) return false;
		for (int i=0;i<cnt;++i){
			if (i==x || i==y) continue;
			if (s[0][a[i]]!=s[1][a[i]] || s[0][a[i]]!=s[2][a[i]]) return false;
		}
	}
	else if (z==y){
		if (s[2][a[x]]!=s[1][a[x]]) return false;
		//if (s[0][a[z]]==s[1][a[z]] || s[0][a[z]]==s[2][a[x]]) return false;
		for (int i=0;i<cnt;++i){
			if (i==x || i==z) continue;
			if (s[0][a[x]]!=s[1][a[i]] || s[0][a[i]]!=s[2][a[i]]) return false;
		}
	}
	else {
		if (s[0][a[z]]!=s[1][a[z]]) return false;
		if (s[2][a[x]]!=s[1][a[x]]) return false;
		if (s[0][a[y]]!=s[2][a[y]]) return false;
		for (int i=0;i<cnt;++i){
			if (i==x || i==z || i==y) continue;
			if (s[0][a[x]]!=s[1][a[i]] || s[0][a[i]]!=s[2][a[i]]) return false;
		}
	}
	return true;
}
void change(int x,int y,int z)
{
	x=a[x];
	y=a[y];
	z=a[z];
	if (x==y){
		s[0][x]=s[1][y]=s[2][x];
		s[2][z]=s[1][z];
	}
	else if (x==z){
		s[0][x]=s[2][z]=s[1][x];
		s[1][y]=s[0][y];
	}
	else if (y==z){
		s[1][y]=s[2][z]=s[0][y];
		s[0][x]=s[1][x];
	}
	else{
		s[0][x]=s[1][x];
		s[1][y]=s[0][y];
		s[2][z]=s[1][z];
	}
}
int main()
{
	scanf("%s%s%s",s[0],s[1],s[2]);
	for (int i=0;s[0][i];++i){
		if (s[0][i]!=s[1][i] || s[1][i]!=s[2][i]){
			a[cnt++]=i;
		}
	}
	int tmp=0;
	int x=-1,y=-1,z=-1;
	if (cnt>3){
		printf("Impossible\n");
	}
	else {
		for (int i=0;i<cnt;++i){
			for (int j=0;j<cnt;++j){
				for (int k=0;k<cnt;++k){
					if (check(i,j,k)){
						//cout<<i<<" "<<j<<" "<<k<<endl;
						if (x==i&&y==j&&z!=k || x==i&&y!=j&&z==k || x!=i&&y==j&&z==k) continue;
						if (!tmp){
							x=i;
							y=j;
							z=k;
							if (x==y && z==x)++tmp;
						}
						++tmp;
					}	
				}
			}
		}
		//cout<<tmp<<" "<<cnt<<endl;
		if (tmp>1 || cnt==0){
			printf("Ambiguous\n");
		}
		else if (tmp==0){
			printf("Impossible\n");
		}
		else {
			change(x,y,z);
			printf("%s\n",s[0]);
		}
	}
	return 0;
}
