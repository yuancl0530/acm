#include <stdio.h>
#include <sys/resource.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/time.h>
#define KB (1024)
void set_limit(int data=64,int s=8,int t=1);
int main(int argc,char *argv[])
{	if (argc != 7) {printf("judge error!\n"); exit(-1);}	
	const char *file = argv[1];
	const char *input = argv[2];
	const char *output = argv[3];
	const int data = atoi(argv[4]);
	const int stack = atoi(argv[5]);
	const int time = atoi(argv[6]);
	pid_t pid;
	if ((pid = fork()) < 0) {printf("fork error\n"); exit(0); }
	else if (pid == 0){
		freopen(input,"r",stdin);
		freopen(output,"w",stdout);
		set_limit(data,stack,time);
		int ret = execl(file,file,(char*)0);
		fclose(stdin);
		fclose(stdout);
	}
	int ret = 0;
	int status = 0;
	if (wait(&status) != pid) {printf("error\n"); exit(-1);}	
	if(WIFSIGNALED(status))
		ret = (int)WTERMSIG(status);
//	printf("judge return %d\n",ret);
	return ret;
}
void set_limit(int data,int s,int t)
{
	struct rlimit memory_limit;

    //限制进程虚拟地址段大小
    memory_limit.rlim_cur = memory_limit.rlim_max = (long long)data*1024*KB;
    if(setrlimit(RLIMIT_AS, &memory_limit)){
        perror("setrlimit:");
	}

    //限制进程数据段大小
    memory_limit.rlim_cur = memory_limit.rlim_max = data*1024*KB;
    if(setrlimit(RLIMIT_DATA, &memory_limit))
        perror("setrlimit:");

    //限制进程栈大小
    memory_limit.rlim_cur = memory_limit.rlim_max = s*1024*KB;
    if(setrlimit(RLIMIT_STACK, &memory_limit))
        perror("setrlimit:");

    //限制进程CPU时间
    memory_limit.rlim_cur = memory_limit.rlim_max = t;
    if(setrlimit(RLIMIT_CPU, &memory_limit))
        perror("setrlimit:");
	
}
