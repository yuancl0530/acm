/*********************************
Date: Thu Aug  2 15:15:48 CST 2018
Author: ycl
*********************************/
#include <iostream>
#include <cstdio>
#include <cstring>
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
	int x;
	Node *next[26];
	Node()
	{
		cnt = 0;
		CL(next);
	}
};
//Node *node = new Node[maxn]();
int id;/*
Node *createNode()
{
	Node *p = &node[id++];
	p->cnt = 0;
	return p;
}*/
void insert(Node *root,char *s)
{
	Node *p = root;
	for (int i = 0;s[i];++i){
		int k = s[i] - 'a';
		if (p->next[k] == NULL) p->next[k] = new Node();//createNode();
		p = p->next[k];
		p->cnt++;
	}
}
int query(Node *root,char *s)
{
	Node *p = root;
	for (int i = 0;s[i];++i){
		int k = s[i] - 'a';
		if (p->next[k] == NULL) return 0;
		p = p->next[k];
	}
	return p->cnt;
}
char s[maxn];
int main()
{
	id = 0;
	Node *root = new Node();//createNode();
	while (cin.getline(s,100) && s[0])
		insert(root,s);
	while (scanf("%s",s) != EOF)
		printf("%d\n",query(root,s));
	
	return 0;
}
