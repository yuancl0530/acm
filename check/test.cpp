#include<stdio.h>
#include<iostream>
#include<queue>
#include<algorithm>
#include<string.h>

using namespace std;
int flag[200010];
int N,K;
int bfs();

struct point
{
    int x,step;
} pos;


int main()
{
	scanf("%d%d",&N,&K);
    pos.x = N;
    pos.step=0;
	int times;
	times=bfs();
    printf("%d\n",times);

	return 0;
}

int bfs()
{
    queue<point>q;
	flag[pos.x]++;
	q.push(pos);

	while(!q.empty())
	{
		point now= q.front();
        q.pop();

		if(now.x==K)
			return now.step;

		for(int j=0;j<3;j++)
		{
			point temp=now;

			if(j==0)
                temp.x=temp.x+1;
			if(j==1)
				temp.x=temp.x-1;
			if(j==2)
				temp.x=temp.x*2;

			if(temp.x<=2*K && temp.x>=0 && flag[temp.x]==0 )
			{
			    temp.step++;
				flag[temp.x]++;
				q.push(temp);
			}
		}
	}

    return 0;

}
