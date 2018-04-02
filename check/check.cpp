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
#include <bitset>
#include <fstream>
using namespace std;
#define CL(a) memset(a,0,sizeof(a))
#define Cl(a,b) memset(a,b,sizeof(a))
#define INF 0x7fffffff
#define LL long long
const int MOD = 1e9 + 7;
const int maxn = 1e6 + 100;
int Time = 1000;
int run(string s);
void encode(string name);
void saveWrong();
void build();
void check(int t = Time);
void check0();
string testname = "test";
string stdname = "std";
string makedata = "makedata";
int main(int argc,char *argv[])
{
	build();
	if (argc==1)
		check();
	else if (argc==2 && !strcmp(argv[1],"-a"))
		check0();
	else
		cout<<"./check or ./check -a"<<endl;
	return 0;
}
void check0()
{
	run("./"+testname+" <input >output1");
	run("./"+stdname+" <input >output2");
	if (run("diff output1 output2"))
		cout<<"Wrong Answer"<<endl;
	else
		cout<<"Accepted"<<endl;
}
void check(int t)
{
	int wrong = 0;
	for (int i = 1;i <= t;i++){
		run("./"+makedata+" >input");
		run("./"+testname+" <input >output1");
		run("./"+stdname +" <input >output2");
		if (run("diff output1 output2")){
			wrong++;
			saveWrong();
			cout<<"Wrong Answer on test"<<i<<endl;
			cout<<"Continue?(y/n?): ";
			char c;cin>>c;
			if (c != 'n') continue;
			else break;
		}
		else cout<<"Accepted test"<<i<<endl;
	}
	if (!wrong) cout <<"All accepted"<<endl;
	else{
		cout<<"Display wrong data?(y/n):";
		char c;cin>>c;
		if (c == 'y') run("cat WrongData");
	}
}
int run(string s)
{
	int ret = system(s.c_str());
	if (ret){
		cout<<s<<":Runtime error!"<<endl;
		exit(-1);
	}
	return ret;
}
void encode(string name)
{
	int t = run("g++ "+name+".cpp -o "+name);
	if (t){
		cout<<name+".cpp: "<<"Complete error!"<<endl;
		exit(-1);
	}
}

void saveWrong()
{
	static int t = 0;
	++t;
	stringstream tt;tt<<t;
	run("echo \"Test Data "+tt.str()+":\"|cat >> WrongData");
	run("cat input >> WrongData");
	run("echo \"---------------\"|cat>>WrongData");
	run("echo \"Correct Answer:\" |cat>> WrongData");
	run("cat output2 >> WrongData");
	run("echo \"--------------\"|cat>>WrongData");
	run("echo \"Output Answer:\" |cat>> WrongData");
	run("cat output1 >> WrongData");
	run("echo \"---------------------------\"|cat>>WrongData");

}
void build()
{
	encode(makedata);
	encode(testname);
	encode(stdname);
	run("touch WrongData");
	run("rm WrongData");
}
