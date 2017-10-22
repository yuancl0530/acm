/*********************************
Date: Fri Sep 29 19:45:05 CST 2017
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
stack<char> S;
int main()
{
	while (scanf("%s",s) != EOF){
		while (!S.empty()) S.pop();
		int ans=0;
		for (int i=0;s[i];++i){
			if (s[i]=='(' || s[i]=='[' ||s[i]=='{'||s[i]=='<')
				S.push(s[i]);
			else{
				if (S.empty()){
					ans=-1;
					break;
				}
				else{
					char t=S.top();
					S.pop();
					if (t=='[' && s[i] != ']')
						ans++;
					if (t=='{' && s[i] != '}')
						ans++;
					if (t=='(' && s[i] != ')')
						ans++;
					if (t=='<' && s[i] != '>')
						ans++;

				}
			}
		}
		if (!S.empty())
			ans=-1;
		if (ans==-1)
			cout<<"Impossible"<<endl;
		else{
			cout<<ans<<endl;
		}
	}
	return 0;
}
