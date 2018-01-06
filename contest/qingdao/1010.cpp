/*********************************
Date: Sun Sep 17 14:22:08 CST 2017
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
const int maxn = 1e5 + 100;
struct Node
{
	int value;
	Node *pre;
	Node *next;
	bool del;
	Node (int v=0,Node *p=NULL,Node *n=NULL)
	{
		value=v;
		pre=p;
		next=n;
		del=false;
	}
};
void nextInt(int &x)
{  
	char c;
    do {c=getchar(); }
	while (c<'0'||c>'9');  
    x=c-'0';  
    while ('0'<=(c=getchar())&&c<='9') x=x*10+c-'0';  
}
Node *d[maxn];
Node aa[maxn];
struct List
{
	Node *head;
	Node *end;
	int cnt;
	int size;
	Node *start;
	List(int s=0)
	{
		head=new Node;
		end=head;
		cnt=0;
		size=s;
		start=head;
	}
	/*~List()
	{
		Node *p=head;
		while (head){
			p=head;
			head=p->next;
			delete p;
		}
	}*/
	void read(int i)
	{
		end->next=&aa[i];
		end->next->pre=end;
		nextInt(aa[i].value);
		end=end->next;
	}
	int find()
	{
		cnt=0;
		Node *p;
		if (start == head)
			p=head->next;
		else
			p=start;
	//	cout<<"start "<<p->value<<endl;
		while (p&&p->next){
			if (p->value > p->next->value){
				if (p->del==false){
					d[cnt++]=p;
					p->del=true;
					if (cnt==1){
						start=p->pre;
					}
				}
				if (p->next->del==false){
					p->next->del=true;
					d[cnt++]=p->next;
				}
			}
			p=p->next;
		}
		return cnt;
	}
	void delNode(Node *p)
	{
		Node *t1=p->pre;
		Node *t2=p->next;
	//	delete p;
		t1->next=t2;
		if (t2) t2->pre=t1;
		--size;
	}
	void show()
	{
		Node *p=head->next;
		while (p){
			printf("%d ",p->value);
			p=p->next;
		}
		printf("\n");
	}
};
int main()
{
	int T;
	scanf("%d",&T);
	while (T--){
		int n;
		scanf("%d",&n);
		List* p=new List(n);
		for (int i=0;i<n;i++){
			p->read(i);
		}
		while (p->head->next&&p->find()){
			for (int i=0;i<p->cnt;++i){
				p->delNode(d[i]);
			}
		}
		if (p->size){
			printf("%d\n",p->size);
			p->show();	
		}
		else
			printf("0\n\n");
		//delete p;*/
	}
	return 0;
}
