#ifdef _MSC_VER
#define DEBUG
#define _CRT_SECURE_NO_DEPRECATE
#endif

#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <limits.h>
#include <algorithm>
#include <math.h>
#include <numeric>
#include <functional>
#include <ctype.h>
#define MAX 30
using namespace std;

char mat[MAX][MAX];
bool visit[MAX][MAX];
int diff[]={-1,0,0,1,1,0,0,-1};

void func(int x,int y,int direction,char *ans)
{
	if(	visit[x][y])
		return;

	*ans=mat[x][y];
	visit[x][y]=true;
	++ans;

	while(!visit[x+diff[direction]][y+diff[direction+1]])
	{
		visit[x+diff[direction]][y+diff[direction+1]]=true;
		*ans=mat[x+diff[direction]][y+diff[direction+1]];
		++ans;
		x+=diff[direction];
		y+=diff[direction+1];
	}

	//
// 	x-=diff[direction];
// 	y-=diff[direction+1];

	//
	direction = (direction+2)%8;
	x+=diff[direction];
	y+=diff[direction+1];
	func(x,y,direction,ans);
}

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

	int n,m;
	char str[MAX*MAX];
	
	while(scanf("%d%d",&n,&m) && n&& m)
	{
		memset(visit,true,sizeof(visit));
		memset(str, '\0',sizeof(str));
    getchar();

		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=m;++j)
			{
				scanf("%c",&mat[i][j]);
				visit[i][j]=false;
			}
		}

		func(1,1,2,str);
		for(int i=0;i<strlen(str);++i)
			printf("%c",str[i]-7);
		printf("\n");

	}

  return 0;
}
