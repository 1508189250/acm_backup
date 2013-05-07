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

#include <queue>
using namespace std;
struct NODE
{
	int x,y;
};
int map[10][10],used[10][10],steps[10][10];
int num[]={-1,0,1,0,0,-1,0,1};
int w,h,sx,sy;

int main(void)
{
#ifdef DEBUG  
	freopen("data.txt","r",stdin);  
#endif  

	queue<NODE> mque;
	int x,y,a,b;

	while(scanf("%d%d",&w,&h)&&(w||h))
	{
		while(!mque.empty()) mque.pop();
		memset(used,0,sizeof(used));
		bool ans=false;
		for(int i=0;i<h;++i)
			for(int j=0;j<w;++j)
			{
				scanf("%d",&map[i][j]);
				if(map[i][j]==2)
				{
					sx=i,sy=j;
				}
			}
		NODE pos;
		pos.x=sx;
		pos.y=sy;
		used[sx][sy]=6;
		steps[sx][sy]=0;
		mque.push(pos);
		while(!mque.empty() && !ans)
		{
			pos=mque.front();
			mque.pop();
			x=pos.x;
			y=pos.y;
			if(used[x][y] && map[x][y]==3)
			{
				ans=true;
				break;
			}
			for(int i=0;i<8 && !ans ;i+=2)
			{
				a=x+num[i];
				b=y+num[i+1];
				if(a>=0 && a<h && b>=0 &&b<w && map[a][b]!=0 && used[x][y]-1>used[a][b])
				{
					pos.x=a;
					pos.y=b;
					mque.push(pos);
					steps[a][b]=steps[x][y]+1;
					if(map[a][b]==4)
						used[a][b]=6;
					else
						used[a][b]=used[x][y]-1;
				}
			}
		}
		if(ans)
			printf("%d\n",steps[x][y]);
		else
			printf("%d\n",-1);
	}

	return 0;
}
