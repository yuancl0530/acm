#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <sstream>
#include <sys/times.h>
#include <sys/wait.h>
#include <unistd.h>
using namespace std;
#define KB (1024)
#define TLE 9
#define MLE 11

int Case = 1000;
string testname = "test";
string stdname = "std";
string makedata = "makedata";
string judge = "judge";
const char * memory = "128";
const char * stack = "8";
const char * ltime = "1";

int run(string s);
void encode(string name);
void saveWrong();
void build();
void check(int t = Case);
int run(const string file,const char *output,double &t,
	const char* ti=ltime,const char *m=memory,const char *s=stack);

int main(int argc,char *argv[])
{
	build();
	check();
	return 0;
}

void check(int t)
{
	int wrong = 0, t1 = 0, t2 = 0;
	double t_std, t_test;
	for (int i = 1;i <= t;i++){
		run("./bin/"+makedata+" > ./data/input");
		t1=run("./bin/"+testname,"./data/output1",t_test);
		t2=run("./bin/"+stdname, "./data/output2",t_std);
		if (t1 || t2) {
			printf("on test %d\n",i);
			cout<<"Continue?(y/n?): ";
			char c;cin>>c;
			if (c == 'y') continue;
			else break;
		}
		else if (run("diff ./data/output1 ./data/output2")){
			wrong++;
			saveWrong();
			cout<<"Wrong Answer on test"<<i<<endl;
			cout<<"Continue?(y/n?): ";
			char c;cin>>c;
			if (c == 'y') continue;
			else break;
		}
		else {
			printf("Accepted test %d",i);
			printf("(std:%.0lfms test:%.0lfms)\n",t_std,t_test);
		}
	}
	if (!wrong) printf("All accepted\n");
	else{
		printf("Display wrong data?(y/n):");
		char c;cin>>c;
		if (c == 'y') run("cat WrongData");
	}
}
int run(string s)
{
	int ret = system(s.c_str());
	return ret>>8;
}
int run(const string file,const char *output,double &t,
	const char*ti,const char *m,const char *s)
{ 
	static int clktck = 0;
	if (clktck == 0) clktck = sysconf(_SC_CLK_TCK);
	struct tms tms_start,tms_end;
	clock_t start,end;
	start = times(&tms_start);
	int ret = run("./bin/judge "+file+" ./data/input"+" "+output+" "+m+" "+s+" " +ti);
	end = times(&tms_end);
	clock_t real = end - start;
	t = real*1000 / (double)clktck;
	if (ret == -1) {fprintf(stderr,"fork error!\n"); exit(-1);}
	else if (ret == TLE) {cout<<file<<":Time Limited Exceeded ";}
	else if (ret == MLE) {cout<<file<<":Memory Limited Exceeded ";}
	return ret;
}

void encode(string name)
{
	if (run("g++ "+name+".cpp -o ./bin/"+name)){
		cout<<name+".cpp: "<<"Complete error!"<<endl;
		exit(-1);
	}
}

void saveWrong()
{
	static int t = 1;
	stringstream tt;tt<<t++;
	run("echo \"Test Data "+tt.str()+":\"|cat >> WrongData");
	run("cat ./data/input >> WrongData");
	run("echo \"---------------\"|cat>>WrongData");
	run("echo \"Correct Answer:\" |cat>> WrongData");
	run("cat ./data/output2 >> WrongData");
	run("echo \"--------------\"|cat>>WrongData");
	run("echo \"Output Answer:\" |cat>> WrongData");
	run("cat ./data/output1 >> WrongData");
	run("echo \"---------------------------\"|cat>>WrongData");

}
void build()
{
	encode(makedata);
	encode(testname);
	encode(stdname);
	encode(judge);
	run("touch WrongData");
	run("rm WrongData");
}
