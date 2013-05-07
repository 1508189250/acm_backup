/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2012-04-17 19:26
 # Filename: ZOJ1008 Gnome Tetravex.cpp
 # Description : 
 ******************************************************************************/
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
#define MAX 100
using namespace std;

struct NODE
{
	int top,right,buttom,left;
	bool operator== (const NODE &tmp)
	{
		return top==tmp.top && right==tmp.right && buttom==tmp.buttom && left==tmp.left;
	}
}node[MAX];

int map[MAX][MAX],visit[MAX];
int sum[MAX];
bool ans;
void dfs(int p,const int &n)
{
	if(p==n*n || ans )
  {
    ans=true;
		return;
  }
	int x=p/n,y=p%n;
	for(int i=0;i<n*n && !ans;++i)
		if(sum[i])
		{
			if(x>0)
				if(node[i].top!=node[map[x-1][y]].buttom)
					continue;
			if(y>0)
				if(node[i].left!=node[map[x][y-1]].right)
					continue;
			map[x][y]=i;
			--sum[i];
			dfs(p+1,n);
			++sum[i];
		}
}

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

  int n,ncases=1;;
  //   scanf("%d",&ncase);

  while(scanf("%d",&n) && n)
  {
		if(ncases>1)
      printf("\n");
		memset(sum,0,sizeof(sum));
		for(int i=0;i<n*n;++i)
		{
      scanf("%d%d%d%d",&node[i].top,&node[i].left,&node[i].buttom,&node[i].right);
			bool flag=false;
			for(int j=0;j<i;++j)
				if(sum[j] && node[j]==node[i])
				{
					++sum[j];
					flag=true;
					break;
				}
			if(!flag)
				++sum[i];
		}
		memset(map,0,sizeof(map));
		ans=false;
		dfs(0,n);
    printf("Game %d: ",ncases++);
		if(ans)
			printf("Possible\n");
		else
			printf("Impossible\n");
  }

  return 0;
}
