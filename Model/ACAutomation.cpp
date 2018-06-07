#include <bits/stdc++.h>
using namespace std;
#define CL(a) memset(a,0,sizeof(a))
#define Cl(a,b) memset(a,b,sizeof(a))
#define MP(a,b) make_pair(a,b)
#define INF 0x7fffffff
#define ll long long
const int mod = 1e9 + 7;
const int maxn = 1e6 + 100;
#define N 26
struct Node
{
	int count;
	Node *fail,*next[N];
	void init(int c=0,Node *f=NULL)
	{
		CL(next);
		fail = f;
		count = c;
	}
}node[maxn];
int cnt;
char s[maxn];

inline void insert(Node *p,char *s)
{
	for (int i=0;s[i];++i){
		int id = s[i]-'a';
		if (!p->next[id]){
			p->next[id] = &node[cnt++];
			p->next[id]->init();
		}
		p = p->next[id];
	}
	++p->count;
}
inline void buildAC(Node *root)
{
	queue<Node*> Q;
	Node *p = root;
	p->fail = NULL;
	Q.push(p);
	Node *t;
	while (!Q.empty()){
		p = Q.front(); 
		Q.pop();
		for (int i=0;i<N;++i){
			if (!p->next[i]) continue;
			Q.push(p->next[i]);
			if (p == root) p->next[i]->fail = root;
			else {
				t = p->fail;
				while (t){
					if (t->next[i]){
						p->next[i]->fail = t->next[i];
						break;
					}
					t = t->fail;
				}
				if (!t) p->next[i]->fail = root;
			}
		}
	}
}
inline int query(Node *root,char *s)
{
	Node *p = root;
	Node *t;
	int ans = 0;
	for (int i=0;s[i];++i){
		int id = s[i]-'a';
		while (p!=root && p->next[id]==NULL)
			p = p->fail;
		p = p->next[id];
		if (!p) p = root;
		t = p;
		while (t!=root && t->count!=-1){
			ans += t->count;
			t->count = -1;
			t=t->fail;
		}
	}
	return ans;
}
int main()
{
	int T,n;
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n);
		Node * root = &node[cnt++];
		root->init();
		for (int i=0;i<n;++i){
			scanf("%s",s);
			insert(root,s);
		}
		buildAC(root);
		scanf("%s",s);
		printf("%d\n",query(root,s));
	}
	return 0;
}
