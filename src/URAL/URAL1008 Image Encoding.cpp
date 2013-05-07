#include "stdafx.h"
#define DEBUG

#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <memory.h>
#include <queue>
#define MAX 100
using namespace std;

bool map[MAX][MAX],visit[MAX][MAX];
queue<int> xq,yq;
int n;

void solution1(void)
{
	int beg_x=n,beg_y;
	scanf("%d",&beg_y);
	memset(map,false,sizeof(map));
	memset(visit,false,sizeof(visit));
	xq.push(beg_x);
	yq.push(beg_y);
	char ch;
	int ncount=0;
	while(!xq.empty())
	{
		int x=xq.front(),y=yq.front();
		xq.pop();
		yq.pop();
		map[x][y]=true;
		++ncount;
		getchar();
		while(ch=getchar())
		{
			if(ch=='.' || ch==',')
				break;
			int x_temp=x,y_temp=y;
			if(ch=='R')
				++x_temp;
			else if(ch=='T')
				++y_temp;
			else if(ch=='L')
				--x_temp;
			else if(ch=='B')
				--y_temp;
			xq.push(x_temp);
			yq.push(y_temp);
		}
	}
	printf("%d\n",ncount);
	for(int i=1;i<MAX;++i)
		for(int j=1;j<MAX;++j)
			if(map[i][j])
				printf("%d %d\n",i,j);
}

int def[]={1,0,0,1,-1,0,0,-1};
char direction[]={'R','R','T','T','L','L','B','B'};
void solution2(void)
{
	int beg_x,beg_y,x,y;
	memset(map,false,sizeof(map));
	memset(visit,false,sizeof(visit));
	for(int i=0;i<n;++i)
	{
		scanf("%d %d",&x,&y);
		if(i==0)
			beg_x=x,beg_y=y;
		map[x][y]=true;
	}
	printf("%d %d\n",beg_x,beg_y);
	xq.push(beg_x);
	yq.push(beg_y);
	visit[beg_x][beg_y]=true;
	int ncount=n;
	while(!xq.empty())
	{
		beg_x=xq.front();
		beg_y=yq.front();
		xq.pop();
		yq.pop();
		for(int i=0;i<8;i+=2)
		{
			x=beg_x+def[i];
			y=beg_y+def[i+1];
			if(!visit[x][y] && map[x][y])
			{
				xq.push(x);
				yq.push(y);
        printf("%c",direction[i]);
				visit[x][y]=true;
			}
		}
		if(--ncount)
			printf(",\n");
		else
			printf(".\n");
	}
}

int main(void)
{
#ifdef DEBUG  
  freopen("C:/Users/neo/Desktop/stdin.txt","r",stdin);
  freopen("C:/Users/neo/Desktop/stdout.txt","w",stdout); 
#endif  
	char ch;

	while(~scanf("%d",&n))
	{
		ch=getchar();
		if(ch==' ')
			solution1();
		else
			solution2();
	}

  return 0;
}
