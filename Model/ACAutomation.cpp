/*********************************
Date: Sat Aug 26 10:26:02 CST 2017
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
const int maxm = 55;
char word[maxm];
char str[maxn];
struct Node
{
	Node *child[26];
	Node *fail;
	int cnt;
	Node()
	{
		fail=NULL;
		for (int i=0;i<26;i++)
			child[i]=NULL;
		cnt=0;
	}
};
Node *root=NULL;
queue<Node *>Q;
void insert(char *s)
{
	Node *p=root;
	while (*s){
		int id=*s-'a';
		if (p->child[id]==NULL){
			p->child[id]=new Node();
		}
		p=p->child[id];
		++s;
	}
	p->cnt++;
}
void buildFailePoint()
{
	while (!Q.empty()) Q.pop();
	Q.push(root);
	while (!Q.empty()){
		Node *now=Q.front();
		Q.pop();
		for (int i=0;i<26;i++){
			if (now->child[i]){
				if (now==root)
					now->child[i]->fail=root;
				else{
					Node *p=now->fail;
					while (p){
						if (p->child[i]){
							now->child[i]->fail=p->child[i];
							break;
						}
						p=p->fail;
					}
					if (!p) now->child[i]->fail=root;
				}
				Q.push(now->child[i]);
			}
		}
	}
}
int query(char *s)
{
	int ret = 0;
	int len=strlen(s);
	Node *now=root;
	for (int i=0;i<len;i++){
		int id=s[i]-'a';
		while (now->child[id]==NULL && now!=root) now=now->fail;
		now=now->child[id];
		now=(now==NULL)? root:now;
		Node *temp=now;
		while (temp != root && temp->cnt!=-1){
			ret+=temp->cnt;
			temp->cnt=-1;
			temp=temp->fail;
		}
	}
	return ret;
}
void clear(Node *root)
{
	if (!root) return ;
	for (int i=0;i<26;i++){
		if(root->child[i])
			clear(root->child[i]);
	}
	delete root;
}
void init()
{
	clear(root);
	root = new Node();
}
int main()
{
	int T;
	scanf("%d",&T);
	while (T--){
		int n;
		init();
		scanf("%d",&n);
		while (n--){
			scanf("%s",word);
			insert(word);
		}
		scanf("%s",str);
		buildFailePoint();
		int ans=query(str);
		printf("%d\n",ans);
	}
	return 0;
}
