#include "stdafx.h"
#define DEBUG

#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <memory.h>
#include <limits.h>
#include <algorithm>
#include <math.h>
#include <queue>
#define MAX 50
using namespace std;

char map[MAX][MAX];
bool visit[MAX][MAX];
int def[]={-1,0,1,0,0,-1,0,1};
int sum;
struct POINT
{int x,y;};

int main(void)
{
#ifdef DEBUG  
  freopen("C:/Users/neo/Desktop/stdin.txt","r",stdin);
  freopen("C:/Users/neo/Desktop/stdout.txt","w",stdout); 
#endif  

	int n;
	POINT p_now,p_temp;

	while(~scanf("%d",&n))
	{
		queue<POINT> q_p;
		sum=0;
		memset(map,'#',sizeof(map));
		memset(visit,false,sizeof(visit));
		getchar();
		for(int i=1;i<=n;++i)
			gets(map[i]+1);

		p_now.x=1;
		p_now.y=1;
		q_p.push(p_now);
		visit[1][1]=true;
    p_now.x=n;
    p_now.y=n;
    q_p.push(p_now);
    visit[n][n]=true;
		while(!q_p.empty())
		{
			p_now = q_p.front();
			q_p.pop();
			for(int i=0;i<8;i+=2)
			{
				p_temp.x = p_now.x+def[i];
				p_temp.y = p_now.y+def[i+1];
				if(visit[p_temp.x][p_temp.y])
					continue;
				else if(map[p_temp.x][p_temp.y]=='#'||map[p_temp.x][p_temp.y]==0)
				{
					++sum;
				}
				else
				{
					visit[p_temp.x][p_temp.y]=true;
					q_p.push(p_temp);
				}
			}
		}
		printf("%d\n",(sum-4)*9);
	}

  return 0;
}
