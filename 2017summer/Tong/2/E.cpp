/*********************************
Date: Thu Aug 24 19:11:01 CST 2017
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
#define INF 0x7fffffff
#define LL long long
const int MOD = 1e9 + 7;
const int maxn = 1e3 + 100;
map<char,int>M;
map<pair<LL,LL>,int>arID;
set<pair<LL,LL> >Set;
int ID=0;
int ARRAY[100*maxn];
int cnt=0;
char op[10];
LL size[maxn];
LL query(char *s)
{
	if (isdigit(s[0])){
		LL num=0;
		for (int i=0;isdigit(s[i]);i++){
			num=num*10+s[i]-'0';
		}
	//	cout<<num<<endl;
		return num;
	}
	else{
		char arName=s[0];
		s+=2;
		LL id=query(s);
		if (id>=size[M[arName]]) return -1;
		LL x=M[arName];
		LL y=id;
	//	cout<<"("<<arName<<","<<y<<")"<<endl;
		if (!Set.count(make_pair(x,y))) return -1;
		return ARRAY[arID[make_pair(x,y)]];
	}
}
bool oper1(char *s)
{
	if (M[s[0]]) return false;
	M[s[0]]=++cnt;
	LL ss=0;
	s+=2;
	for (int i=0;isdigit(s[i]);i++){
		ss=ss*10+s[i]-'0';
	}
	size[cnt]=ss;
	return true;
}
bool oper2(char *s1,char *s2)
{
	LL value=query(s2);
	if (value==-1)return false;
	LL id=query(s1+2);
	if (id==-1) return false;
	if (id >= size[M[s1[0]]]) return false;
	LL x = M[s1[0]];
	LL y = id;
	LL arid = arID[make_pair(x,y)];
	if (!arid) arID[make_pair(x,y)]=arid=++ID;
	if (!Set.count(make_pair(x,y))) Set.insert(make_pair(x,y));
	ARRAY[arid]=value;
	return true;
}
bool check(char *s)
{
	int op=0;
	char *t;
	for (int i=0;s[i];++i){
		if (s[i]=='=')
			op=1,t=s+i+1;
	}
	if (op==0)
		return oper1(s);
	return oper2(s,t);
}

int main()
{
	int  flag=0;
	while (1) {
		int ans=0;
		Cl(ARRAY,0);M.clear();cnt=0;CL(size);ID=0;Set.clear();
		arID.clear();
		int line=0;
		while (scanf("%s",op) && op[0]!='.'){
			flag=0;
			++line;
			if (!check(op)){
			//	cout<<"wrong"<<endl;
				if (!ans)ans=line;
			}
		}
		++flag;
		if (flag==2)break;
		cout<<ans<<endl;
	};


	return 0;
}
