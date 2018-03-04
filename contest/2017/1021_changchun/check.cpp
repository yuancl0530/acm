/*********************************
Date: Sat Oct 21 19:26:39 CST 2017
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
#include <list>
#include <set>
#include <sstream>
using namespace std;
#define CL(a) memset(a,0,sizeof(a))
#define Cl(a,b) memset(a,b,sizeof(a))
#define MP(a,b) make_pair(a,b)
#define INF 0x7fffffff
#define INFLL 0x7fffffffffffffff
#define LL long long
const int MOD = 1e9 + 7;
const int maxn = 1e6 + 100;

int main()
{
	system("g++ j.cpp -o a");
	system("g++ data.cpp -o data");
	for (int i=1;i<=1000;++i){
		system("./data >in");
		system("./a < in >out");
		system("./sum <out >out2");
		if (!system("diff in out2")){
			cout<<"wrong"<<endl;
			break;
		}
		else
			cout<<"accepted"<<i<<endl;
	}


	return 0;
}
