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
char a[100][100];
int main()
{
	int n,m;
	while (scanf("%d%d",&n,&m) != EOF){
		for (int i = 0;i < n;i++){
			scanf("%s",a[i]);
		}
		int B=0,G=0,R=0;
		bool flag = 0;
		int t = 0;
		if (a[0][0] == 'B')B++;
		if (a[0][0] == 'G')G++;
		if (a[0][0] == 'R')R++;
		for (int i = 1;i < n;i++){
			if (a[i][0] != a[i-1][0])t++;
			if (a[i][0] == 'B')B++;
			if (a[i][0] == 'G')G++;
			if (a[i][0] == 'R')R++;
		}
	//	cout<<B<<G<<R<<t<<endl;
		if (B==G && G== R && t==2){
			flag = 1;
			for (int i = 0;i < n;i++){
				for (int j = 1;j<m;j++){
					if (a[i][j] != a[i][0]){
						flag = 0;
						break;
					}
				}
			}
			if (flag){
				printf("YES\n");
				continue;
			}
		}
		flag = 0;
		B=G=R=0;
		t=0;
		if (a[0][0] == 'B')B++;
		if (a[0][0] == 'G')G++;
		if (a[0][0] == 'R')R++;
		for (int i = 1;i < m;i++){
			if (a[0][i] != a[0][i-1])t++;
			if (a[0][i] == 'B')B++;
			if (a[0][i] == 'G')G++;
			if (a[0][i] == 'R')R++;
		}
	//	cout<<B<<G<<R<<t<<endl;
		if (B==G && G== R && t==2){
			flag = 1;
			for (int i = 1;i < n;i++){
				for (int j = 0;j<m;j++){
					if (a[i][j] != a[0][j]){
						flag = 0;
						break;
					}
				}
			}
		}
		if (flag){
			printf("YES\n");
		}
		else{
			printf("NO\n");
		}


	}
	return 0;
}
