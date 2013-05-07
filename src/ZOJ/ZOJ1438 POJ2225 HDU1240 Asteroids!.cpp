// #include "stdafx.h"
// #define DEBUG

#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <memory.h>
#include <limits.h>
#include <queue>
#define MAX 15
using namespace std;

struct NODE
{
	int x,y,z,len;
}begin,end;

bool operator==(const NODE &lhs,const NODE &rhs)
{
	return lhs.x==rhs.x && lhs.y==rhs.y && lhs.z==rhs.z;
}

queue<NODE> mq;
char map[MAX][MAX][MAX];
bool visit[MAX][MAX][MAX];
int n;
int num[]={-1,0,0,1,0,0,0,-1,0,0,1,0,0,0,-1,0,0,1};

int main(void)
{
#ifdef DEBUG  
	freopen("data.txt","r",stdin);  
#endif  
	char str[10];
	int x,y,z,a,b,c;

	while(~scanf("%s %d",&str,&n))
	{
		memset(map,'\0',sizeof(map));
		memset(visit,false,sizeof(visit));
		while(!mq.empty())mq.pop();
		int len=0; 
		getchar();
		for(int i=0; i<n; i++)  // 这个这个 = = 。。。   
			for(int k=0; k<n; k++)  
			{  
				for(int j=0; j<n; j++)  
					scanf("%c",&map[j][k][i]);  
				getchar();  
			}  
		scanf("%d%d%d",&begin.x,&begin.y,&begin.z);
		begin.len=0;
		if (map[begin.x][begin.y][begin.z] == 'X')
			goto end;
		scanf("%d%d%d",&end.x,&end.y,&end.z);
		scanf("%s",str);
		visit[begin.x][begin.y][begin.z]=true;
		mq.push(begin);

		while(!mq.empty())
		{
			begin = mq.front();
			len=begin.len;x=begin.x;y=begin.y;z=begin.z;
			if(begin==end)
				break;
			mq.pop();
			for(int i=0;i<18;i+=3)
			{
				a=num[i]+x;
				b=num[i+1]+y;
				c=num[i+2]+z;
				if(a>=0 && a< n && b>=0 &&b<n &&c>=0 &&c<n && visit[a][b][c]==false && map[a][b][c]=='O')
				{
					visit[a][b][c]=true;
					begin.x=a;
					begin.y=b;
					begin.z=c;
					begin.len=len+1;
					mq.push(begin);
				}
			}
		}

end:
		if(mq.empty())
			printf("NO ROUTR\n");
		else
			printf("%d %d\n",n,len);

	}

	return 0;
}
