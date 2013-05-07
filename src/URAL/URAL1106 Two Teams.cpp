#include "stdafx.h"
#define DEBUG

#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <memory.h>
#define MAX 120
using namespace std;

int map[MAX][MAX];
int n;
bool used[MAX],team[MAX];

void dfs(const int &x)
{
	used[x]=true;
	for(int i=0;map[x][i];++i)
		if(!used[map[x][i]])
		{
      if(!team[x])
			  team[map[x][i]]=true;
			dfs(map[x][i]);
		}
}

int main(void)
{
#ifdef DEBUG  
  freopen("C:/Users/neo/Desktop/stdin.txt","r",stdin);
  freopen("C:/Users/neo/Desktop/stdout.txt","w",stdout); 
#endif  

	while(~scanf("%d",&n))
	{
		int num;
		for(int i=1;i<=n;++i)
		{
			int ind=0;
			while(scanf("%d",&map[i][ind]) && map[i][ind])
				++ind;
		}
		memset(used,false,sizeof(used));
		memset(team,false,sizeof(team));
		for(int i=1;i<=n;++i)
			if(!used[i])
				dfs(i);
		int ans=0;
		for(int i=1;i<=n;++i)
			if(team[i])
				++ans;
		printf("%d\n",ans);
		for(int i=1;i<=n;++i)
			if(team[i])
			{
				--ans;
				printf("%d",i);
				printf("%c",ans==0?'\n':' ');
			}
	}

  return 0;
}
