/*********************************
Date: Thu Aug  2 14:22:15 CST 2018
Author: ycl
*********************************/
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
#define CL(a) memset(a,0,sizeof(a))
#define Cl(a,b) memset(a,(b),sizeof(a))
#define MP(a,b) make_pair(a,b)
#define INF 0x3f3f3f3f
#define ll long long
const int mod = 1e9 + 7;
const int maxn = 4e5 + 100;
struct Node
{
	int cnt;
	Node *next[26];
}node[maxn];
char s[100];
struct Trie
{
private:
	Node *root;
	int id;
	Node *createNode(int cnt=0)
	{
		Node *p = &node[id++];
		p->cnt = cnt;
		//for (int i = 0;i < 26;++i) p->next[i] = NULL;
		return p;
	}
public:
	Trie()
	{
		id=0;
		root = createNode();
	}
	void insert(char *s)
	{
		Node *p = root;
		int len = strlen(s);
		for (int i = 0;i < len;++i){
			int k = s[i] - 'a';
			if (!p->next[k]) p->next[k] = createNode();
			p = p->next[k];
			++p->cnt;
		}
	}
	int query(char *s)
	{
		Node *p = root;
		int len = strlen(s);
		for (int i = 0;i < len;++i){
			int k = s[i]-'a';
			if (p->next[k]==NULL) return 0;
			p = p->next[k];
		}
		return p->cnt;
	}
}trie;
int main()
{
	//ios::sync_with_stdio(false);
	while (cin.getline(s,100) && s[0])
		trie.insert(s);
	while (scanf("%s",s) != EOF)
		printf("%d\n",trie.query(s));
	return 0;
}
