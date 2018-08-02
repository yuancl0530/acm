/*********************************
Date: Thu Aug  2 09:16:38 CST 2018
Author: ycl
*********************************/
#include <bits/stdc++.h>
using namespace std;
#define CL(a) memset(a,0,sizeof(a))
#define Cl(a,b) memset(a,(b),sizeof(a))
#define MP(a,b) make_pair(a,b)
#define INF 0x3f3f3f3f
#define ll long long
const int mod = 1e9 + 7;
const int maxn = 5e6 + 100;
char s1[10],s2[100];
struct Node
{
	int t,s;
	Node *next[2];
}node[maxn];
int id = 0;
Node *createNode(int s = 0,int t = INF)
{
	Node *p = &node[id++];
	p->s = s;
	p->t = t;
	p->next[0] = p->next[1] = NULL;
	return p;
}
void insert(Node *root,ll v,int s,int m,int t)
{
	Node *p = root;
	for (int i = 1;i <= m;++i){
		int k = (v>>(32-i))&1;
		if (p->next[k] == NULL) p->next[k] = createNode();
		p = p->next[k];
	}
	if (p->t > t){
		p->t = t;
		p->s = s;
	}
}
int query(Node *root,ll v)
{
	int s = 1;
	int t = INF;
	Node *p = root;
	if (p->s && p->t<t){
		t = p->t;
		s = p->s;
	}
	for (int i = 31;i>=0;--i){
		int k = (v>>i)&1;
		if (p->next[k]){
			p = p->next[k];
			if (p->s && p->t<t){
				t = p->t;
				s = p->s;
			}
		}
		else break;
	}
	return s;
}
int main()
{
	int n,m,t,mask;
	char ch;
	ll v;
	while (scanf("%d%d",&n,&m) != EOF){
		id = 0;
		Node *root = createNode();
		for (int i = 0;i < n;++i){
			scanf("%s%s",s1,s2);
			int s = (s1[0] =='d')+1;
			stringstream ss(s2);
			v = 0;
			for (int i = 0;i < 4;++i){
				ss >> t;
				v = (v<<8)|t;
				if(ss >> ch);
				else ch = 0;
			}
			if (ch == '/') ss >> mask;
			else mask = 32;
			insert(root,v,s,mask,i);
		}
		ll a,b,c,d;
		while (m--){
			scanf("%lld.%lld.%lld.%lld",&a,&b,&c,&d);
			v = (a<<24)|(b<<16)|(c<<8)|d;
			int s = query(root,v);
			if (s==2) printf("NO\n");
			else printf("YES\n");
		}
	}
	return 0;
}
