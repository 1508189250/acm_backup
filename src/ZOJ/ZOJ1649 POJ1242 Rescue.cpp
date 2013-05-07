// #include "stdafx.h"
// #define DEBUG

#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <memory.h>
#include <limits.h>

#include <math.h>
#include <algorithm>
#include <numeric>
#include <functional>
#include <assert.h>
#include <ctype.h>
#include <stack>
#include <queue>
#define MAX 500
using namespace std;

int m,n;
char map[MAX][MAX];
int num[8]={-1,0,1,0,0,-1,0,1};
struct NODE
{
	int x,y,time;
};
priority_queue<NODE> mque;

bool operator<(const NODE &lhs,const NODE &rhs)
{
	return rhs.time<lhs.time;
}

int func()
{
	NODE pos;
	int x,y,time;
	while(!mque.empty())
	{
		pos=mque.top();
		mque.pop();
		x=pos.x;
		y=pos.y;
		time=pos.time;
		char ch=map[x][y];
		if(ch=='a') return pos.time;
		else
		{
			for(int i=0;i<8;i+=2)
			{
				pos.x=x+num[i];
				pos.y=y+num[i+1];
				if(pos.x>=0 && pos.x<n &&pos.y>=0 && pos.y<m && map[pos.x][pos.y]!='#')
				{
					if(ch=='.')
						pos.time=time+1;
					else
						pos.time=time+2;
					mque.push(pos);
				}
			}
			map[x][y]='#';
		}
	}
	return -1;
}

void init()
{
	while(!mque.empty()) mque.pop();
}

int main(void)
{
#ifdef DEBUG  
	freopen("data.txt","r",stdin);  
#endif  
	char ch;
	NODE pos;

	while(scanf("%d%d",&n,&m)!=EOF)
	{
		init();
		for(int i=0;i<n;++i)
		{
			getchar();
			for(int j=0;j<m;++j)
			{
				scanf("%c",&map[i][j]);
				if(map[i][j]=='r')
				{
					pos.x=i;
					pos.y=j;
					pos.time=0;
					mque.push(pos);
					map[i][j]='.';
				}
			}
		}
		int ans=func();
		if(ans!=-1)
			printf("%d\n",ans);
		else
			printf("Poor ANGEL has to stay in the prison all his life.\n");
	}

	return 0;
}
