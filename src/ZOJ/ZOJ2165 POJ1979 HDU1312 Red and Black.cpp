// #include "stdafx.h"
// #define DEBUG

#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <memory.h>

#include <math.h>
#include <algorithm>
#include <numeric>
#include <functional>
#include <limits>
#include <assert.h>
#include <ctype.h>

#include <vector>
#include <stack>
#include <queue>
#include <deque>

using namespace std;
char map[40][40];
int dis[]={-1,0,1,0,0,-1,0,1};
int num,w,h;
queue<int> hori,ord;
void BFS(void)
{
	int x=hori.front();hori.pop();
	int y=ord.front();ord.pop();
	if (map[x][y]!='.')return;
	++num;
	map[x][y]='#';
	for(int i=0;i<8;i=i+2)
	{
		int a=x+dis[i];
		int b=y+dis[i+1];
		if(a>=0&&a<h&&b>=0&&b<w)
			if(map[a][b]=='.')
			{
				hori.push(a);
				ord.push(b);
			}
	}
}

int main(void)
{
#ifdef DEBUG  
	freopen("data.txt","r",stdin);  
#endif  
	char ch;
	while(scanf("%d %d",&w,&h)&&w&&h)
	{
		num=0;
		while(!hori.empty())
		{
			hori.pop();
			ord.pop();
		}
		for(int i=0;i<h;++i)
		{
			getchar();
			for(int j=0;j<w;++j)
			{
				scanf("%c",&map[i][j]);
				if(map[i][j]=='@')
				{
					hori.push(i);
					ord.push(j);
					map[i][j]='.';
				}
			}
		}
		while(!hori.empty())
			BFS();
		printf("%d\n",num);
	}

	return 0;
}
