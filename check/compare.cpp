#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main(int argc,char *argv[])
{
	if (argc != 3){
		printf("Compare: ./compare file1 file2 ");
		exit(-1);
	}
	string s1,s2;
	ifstream fin1(argv[1]);
	ifstream fin2(argv[2]);
	int  t = 1;
	int cnt = 0;
	while (fin1 >> s1 && fin2 >> s2){
		fin2 >> s2;
		if (s1 != s2){
			cout<<"Line:"<<t<<" "<<s1<<" "<<s2<<endl;
		}
		t++;
	}
	if (fin1.eof() || fin2.eof()) return -1;
	return 0;
}
