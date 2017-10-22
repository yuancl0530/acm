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
const int maxn = 1e5 + 10;
const int N=26;
char s[maxn];
char str[maxn];
struct Node
{
	Node *next[26];
	Node *fail;
	int count;
	Node ()
	{
		CL(next);
		fail=NULL;
		count=0;
	}
}*q[maxn];

void insert(char *s,Node *root)
{
	Node *p=root;
	for (int i=0;s[i];++i){
		int id=s[i]-'a';
		if (p->next[id]==NULL)
			p->next[id]=new Node();
		p=p->next[id];
	}
	p->count++;
}
void build(Node *root)
{
	int head=0;
	int tail=0;
	q[tail++]=root;
	while (head<tail){
		Node *p=q[head++];
		for (int i=0;i<26;++i){
			if (p->next[i]){
				if (p==root)
					p->next[i]->fail=root;
				else{
					Node *t=p->fail;
					while (t){
						if (t->next[i]){
							p->next[i]->fail=t->next[i];
							break;
						}
						t=t->fail;
					}
					if (!t)p->next[i]->fail=root;
				}
				q[tail++]=p->next[i];
			}
		}
	}
}
int query(char *str,Node *root)
{
	Node *p=root;
	int ans=0;
	for (int i=0;str[i];++i){
		int id=str[i]-'a';
		while (p->next[id]==NULL && p!=root)p=p->fail;
		p=p->next[id];
		if (!p)p=root;
		Node *t=p;
		while (t !=root && t->count!=-1){
			ans+=t->count;
			t->count=-1;
			t=t->fail;
		}
	}
	return ans;
}
void clear(Node *root)
{
	for (int i=0;i<26;++i){
		if (root->next[i]){
			clear(root->next[i]);
		}
	}
	delete root; 
}
int main()
{
	int T;
	scanf("%d",&T);
	ios::sync_with_stdio(false);
	cin.tie(0);
	while (T--){
		int n;
		cin>>n;
		Node *root=new Node();
		int maxlen=0;
		int mm=n;
		while (mm--){
			cin>>s;
			int t=strlen(s);
			if (maxlen<t){
				maxlen=t;
				strcpy(str,s);
			}
			insert(s,root);
		}
		build(root);
		int ans=query(str,root);
		if (ans==n)
			printf("%s\n",str);
		else
			printf("NO\n");
		clear(root);
	}
	return 0;
}
