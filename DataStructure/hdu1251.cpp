#include <iostream>
#include <stdio.h>
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
struct Node
{
	Node *next[30];
	int t;
	Node()
	{
		t = 0;
		CL(next);
	}
};
void insert(Node *root,char *s)
{
	int id = *s - 'a';
	if (root->next[id] == NULL){
		root->next[id] = new Node;
	}
	root->next[id]->t+=1;
	if (*(s+1) == 0)  return ;
	insert(root->next[id],s+1);
}
int ans = 0;
void find(Node *root,char *s)
{
	int id = *s - 'a';
	cout <<*s<<endl;
	if (root->next[id] == NULL)
		return ;
	if (*(s+1) == 0){
		ans += root->next[id]->t;
		return ;
	}
	find(root->next[id],s+1);
}
char s[1000];
Node root;
int main()
{
	CL(s);
	while (gets(s)&& s[0]){
		int t = strlen(s);
		s[t] = 0;
		insert(&root,s);
	}
	while (scanf("%s",s)!=EOF){
		ans = 0;
		int t = strlen(s);
		s[t] = 0;

		find(&root,s);
		printf("%d\n",ans);
	}
	return 0;
}
