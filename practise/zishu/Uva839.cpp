/*********************************
Date: Tue Apr  3 10:19:24 CST 2018
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
const int maxn = 1e6 + 100;
struct Node
{
	int ld,rd,lw,rw;
	int w;
	Node *left;
	Node *right;
	Node()
	{
		ld=rd=lw=rw=0;
		left = right = NULL;
	}
};
char s[maxn];
bool ans;
int dfs(Node * u)
{
	int l = u->lw;
	if (u->left)
		l += dfs(u->left);
	int r = u->rw;
	if (u->right)
		r += dfs(u->right);
	if (l*u->ld != r*u->rd){
		ans=false;
	}
	delete u;
	return l+r;
}
int main()
{
	int T;
	scanf("%d",&T);
	stack<Node *> S;
	Node *root=new Node();
	S.push(root);
	bool f=0;
	while (T--){
		while (true){
			int len=strlen(s);
			if (S.empty()){
				if (f)printf("\n");
				f=1;
				ans = true;
				dfs(root);
				if (ans){
					printf("YES\n");
				}
				else {
					printf("NO\n");
				}
				root = new Node();
				S.push(root);
				break;
			}
			else {
				Node* u=S.top();
				S.pop();
				scanf("%d%d%d%d",&u->lw,&u->ld,&u->rw,&u->rd);
				if (u->rw==0){
					Node *t=new Node();
					u->right = t;
					S.push(t);
				}
				if (u->lw==0){
					Node *t=new Node();
					u->left = t;
					S.push(t);
				}
			}
		}
	}
	return 0;
}
