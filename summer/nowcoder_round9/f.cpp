#include <bits/stdc++.h>
using namespace std;
#define CL(a) memset(a,0,sizeof(a))
#define Cl(a,b) memset(a,b,sizeof(a))
#define MP(a,b) make_pair(a,b)
#define INF 0x7fffffff
#define ll long long
const int mod = 1e9 + 7;
const int maxn = 1e5 + 100;
#define N 26
struct Node
{
	int count,v;
	Node *next[N];
	Node *fail;
	void init(int c=0,Node *f=NULL)
	{
		CL(next);
		fail = f;
		count = c;
		v = INF;
	}
}node[10*maxn];
int cnt;
char s[maxn];

void insert(Node *p,char *s)
{
	int n = strlen(s);
	p->v = min(p->v,n);
	for (int i=0;s[i];++i){
		int id = s[i]-'a';
		if (!p->next[id]){
			p->next[id] = &node[cnt++];
			p->next[id]->init();
		}
		p = p->next[id];
		p->v = min(p->v,n-i-1);
	}
	++p->count;
}
void buildAC(Node *root)
{
	queue<Node *> Q;
	Node *p=root;
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
int query(Node *root,char *s)
{
	Node *p = root;
	Node *t;
	int n = strlen(s);
	int ans = p->v;
	for (int i=0;ans && s[i];++i){
		int id = s[i]-'a';
		while (p!=root && p->next[id]==NULL){
			p = p->fail;
		}
		p = p->next[id];
		if (!p) p = root;
		ans = min(ans,p->v + n-i-1);
		t = p;
		while (t!=root){
			if (t->count){
				ans = min(ans,t->v+n-i-1);
			}
			t=t->fail;
		}
	}
	return ans;
}
char q[maxn];
int main()
{
	int n;
	cnt = 0;
	scanf("%d",&n);
	Node * root = &node[cnt++];
	root->init();
	for (int i=0;i<n;++i){
		scanf("%s",s);
		insert(root,s);
	}
	buildAC(root);
	scanf("%s",s);
	int cur = 0;
	q[cur] = 0;
	printf("%d\n",query(root,q));
	for (int i = 0;s[i];++i){
		if (s[i] == '-') --cur;
		else q[cur++] = s[i];
		if (cur < 0) cur = 0;
		q[cur] = 0;
		printf("%d\n",query(root,q));
	}
	return 0;
}
