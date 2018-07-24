/*********************************
Date: Tue Jul  3 22:46:42 CST 2018
Author: ycl
*********************************/
#include <bits/stdc++.h>
using namespace std;
#define CL(a) memset(a,0,sizeof(a))
#define Cl(a,b) memset(a,(b),sizeof(a))
#define MP(a,b) make_pair(a,b)
#define ll long long
const int mod = 1e9 + 7;
const int maxn = 1e5 + 100;

int main()
{
	int x,a,b;
	scanf("%d%d%d",&a,&b,&x);
	int n0;
	++x;
	if (x&1) n0 = x/2+1;
	else n0 = x/2;
	if (n0<=a) {
		int f0=1;
		int f1=1;
		for (int i = 0;i < x;++i){
			printf("%d",i%2);
			if (i%2 && f1){
				f1 = 0;
				for (int i = 0;i < b-x/2;++i)
					printf("1");
			}
			if (i%2==0 && f0){
				f0 = 0;
				for (int i = 0;i < a-n0;++i)
					printf("0");
			}
		}
	}
	else {
		int f0=1;
		int f1=1;
		for (int i = 1;i <= x;++i){
			printf("%d",i%2);
			if (i%2 && f1){
				f1 = 0;
				for (int i = 0;i < b-n0;++i)
					printf("1");
			}
			if (i%2==0 && f0){
				f0 = 0;
				for (int i = 0;i < a-x/2;++i)
					printf("0");
			}
		}
	}
	printf("\n");
	return 0;
}
