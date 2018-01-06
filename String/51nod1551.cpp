#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
#define LL long long
#define CL(a) memset(a,0,sizeof a)
#define Cl(a,b) memset(a,b,sizeof a)
const int maxn=1e6+100;
struct Node
{
	Node *next[2];
	int id;
	LL v;
	Node (int id=0,LL v=0):v(v),id(id)
	{
		CL(next);
	}
};
int tmp[40];
void insert(Node *root,LL a,int id)
{
	int cnt=0;
	LL t=a;
	for (int i=0;i<31;++i){
		tmp[i]=a&1;
		a>>=1;
	}
	Node *p=root;
	for (int i=30;i>=0;--i){
		if (!p->next[tmp[i]])
			p->next[tmp[i]] = new Node();
		p=p->next[tmp[i]];
	}
	p->id=id;
	p->v=t;
}
LL ans=0;
void dfs(Node *p,int pos,int l,int r,LL v=0)
{
	if (pos<0){
		if (p->id >= l && p->id <=r ){
			ans=max(ans,p->v^v);
		}
		return ;
	}
	if (ans) return ;
	if (tmp[pos]){
		if (p->next[0])
			 dfs(p->next[0],pos-1,l,r,v);
		if (p->next[1])
			 dfs(p->next[1],pos-1,l,r,v);
	}
	else {
		if (p->next[1])
			 dfs(p->next[1],pos-1,l,r,v);
		if (p->next[0])
			 dfs(p->next[0],pos-1,l,r,v);
	}
}

void query(Node *root,int l,int r,LL a)
{
	int cnt=0;
	LL v=a;
	for (int i=0;i<=30;++i){
		tmp[cnt++]=a&1;
		a>>=1;
	}
	dfs(root,30,l,r,v);
}
int main()
{
	int n,q;
	LL v;
	scanf("%d%d",&n,&q);
	Node *root = new Node;
	for (int i=0;i<n;++i){
		scanf("%lld",&v);
		insert(root,v,i);
	}
	int l,r;
	for (int i=0;i<q;++i){
		scanf("%lld%d%d",&v,&l,&r);
		ans=0;
		query(root,l,r,v);
		printf("%lld\n",ans);
	}
	return 0;
}
