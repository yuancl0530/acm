/*********************************
Date: Fri Sep 29 19:01:00 CST 2017
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
#define LL long long
const int MOD = 1e9 + 7;
const int maxn = 1e6 + 100;
char s[maxn];
int  exgcd(int a,int b,int &x,int & y)
{
	if (b==0){
		x=1,y=0;
		return a;
	}
	int  d = exgcd(b,a%b,x,y);
	int  t = x;
	x = y;
	y = t -a/b*y;
	return d;
}

int main()
{
	int n,p,q;
	while (scanf("%d%d%d",&n,&p,&q) != EOF){
		scanf("%s",s);
		if (p>q)
			swap(p,q);
		int x,y;
		int t=exgcd(p,q,x,y);
		if (n%t){
			cout<<-1<<endl;
		}
		else{
			x*=n/t;
			y*=n/t;
			int k=n/t;
			while (x<0 && y>=0){
				x+=q/t;
				y-=p/t;
			}
			while (y<0 && x>=0){
				x-=q/t;
				y+=p/t;
			}
			if (x <0 || y<0)
				cout<<-1<<endl;
			else{
				int i=0;
				cout<<x+y<<endl;
				while (x--){
					for (int j=0;j<p;j++){
						cout<<s[i++];
					}
					cout<<endl;
				}
				while (y--){
					for (int j=0;j<q;j++)
						cout<<s[i++];
					cout<<endl;
				}
			}
		}
	
	}
	return 0;
}
