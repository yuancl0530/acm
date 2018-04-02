/*********************************
Date: Sun Mar 25 19:39:54 CST 2018
Author: ycl
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
#include <set>
#include <sstream>
#include <unistd.h>
#include <sys/wait.h>
#include <fstream>
using namespace std;
#define CL(a) memset(a,0,sizeof(a))
#define Cl(a,b) memset(a,b,sizeof(a))
#define MP(a,b) make_pair(a,b)
#define INF 0x7fffffff
#define LL long long
const int mod = 1e9 + 7;
const int maxn = 1e6 + 100;
#define N 100
int a[maxn],b[maxn],c[maxn];
int lch[maxn],rch[maxn];
int Id=1;
void preOrder(int u=1)
{
	a[Id++]=u;
	if (lch[u]) preOrder(lch[u]);
	if (rch[u]) preOrder(rch[u]);
}
void inOrder(int u=1)
{
	if (lch[u]) preOrder(lch[u]);
	a[Id++]=u;
	if (rch[u]) preOrder(rch[u]);
}
void postOrder(int u=1)
{
	if (lch[u]) preOrder(lch[u]);
	if (rch[u]) preOrder(rch[u]);
	a[Id++]=u;
}
int buildTree(int u=1)
{
	
	if (Id>N) return 0;
	if (rand()%3) lch[u]=buildTree(++Id);
	if (rand()%3) rch[u]=buildTree(++Id);
	return u;
}
void createData()
{
	srand(time(0));
	buildTree();
	Id=0;
	inOrder();
	Id=0;
	preOrder();
	Id=0;
	postOrder();
}
int main()
{
	int status=0;
	createData();
	ofstream fout1,fout2;
	fout1.open("in1");
	fout2.open("in2");
	fout1<<Id<<endl;
	for (int i=0;i<Id;++i)
		fout1<<a[i]<<" ";
	for (int i=0;i<Id;++i)
		fout1<<b[i]<<" ";
	for (int i=0;i<Id;++i)
		fout2<<c[i]<<" ";
	fout2<<endl;
	cout<<"#####"<<endl;
	fout1.close();
	fout2.close();
	pid_t pid;
	if (pid=fork()<0){
		printf("Error\n");
		exit(-1);
	}
	else if (pid==0){
		freopen("in1","r",stdin);
		freopen("out","r",stdout);
		//execlp("./a","./a",(char *)0);
		execlp("ls","ls",(char *)0);
	}
	else
    {
        if(wait(&status) != pid)
            perror("wait:");
		cout<<pid<<" "<<getpid()<<endl;
        if(WIFEXITED(status)){
            if (system("diff in1 out"))
				cout<<"Error"<<endl;
			else 
				cout<<"Ac"<<endl;
			return 0;
		}
        else if(WIFSIGNALED(status)){
            printf("abort,  signal number = %d\n", WTERMSIG(status));
			return WTERMSIG(status);
		}
    }
	return 0;
}
