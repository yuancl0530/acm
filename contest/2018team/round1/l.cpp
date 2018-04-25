/*********************************
Date: Tue Apr 17 19:58:25 CST 2018
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
#define ll long long
#define ull unsigned long long
const int mod = 1e9 + 7;
const int maxn = 1e6 + 100;
char s[maxn];
vector<int> V[30];
char op[10];
stack<int> S;

int b_search(vector<int> &V,int k)
{
	int l = -1;
	int r = V.size()-1;
	while (l+1 < r){
		int mid = (l+r)>>1;
		if (V[mid]>k){
			r = mid;
		}
		else{
			l = mid;
		}
	}
	if (r < 0) return -1;
//	cout<<V[r]<<endl;
	return V[r]>k? V[r]:-1;
}
int main()
{
	scanf("%s",s);
	int m;
	scanf("%d",&m);
	for (int i=0;s[i];++i){
		V[s[i]-'a'].push_back(i);
	}
	while (m--){
		scanf("%s",op);
		if (op[1]=='u'){
			char ch;
			cin >> ch;
			if (S.empty()){
				S.push(b_search(V[ch-'a'],-1));
			}
			else if (S.top() >= 0){
				S.push(b_search(V[ch-'a'],S.top()));
			}
			else {
				S.push(-1);
			}
			if (S.top() >= 0){
				printf("YES\n");
			}
			else {
				printf("NO\n");
			}
		}
		else {
			if (!S.empty()){
				S.pop();
			}
			if (S.empty() || S.top() >= 0){
				printf("YES\n");
			}
			else {
				printf("NO\n");
			}
		}
	}
	return 0;
}
