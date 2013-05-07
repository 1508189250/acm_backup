/*******************************************************************************
 * Author : Neo Fung
 * Email : neosfung@gmail.com
 * Last modified : 2011-09-14 22:03
 * Filename : POJ3268 Silver Cow Party.cpp
 * Description : 
 * *****************************************************************************/
// POJ3268 Silver Cow Party.cpp : Defines the entry point for the console application.
//

// #include "stdafx.h"
// #define DEBUG

#include <fstream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <memory.h>
#include <queue>

#define MAX 1100
#define maxint 1<<30

using namespace std;

int farm1[MAX][MAX],farm2[MAX][MAX],path1[MAX],path2[MAX],visit[MAX];
queue<int> myqueue;

void SPFA(int (*farm)[MAX],int source,int n,int *path)
{
	for(int i=1;i<=n;++i)
		path[i]=maxint,visit[i]=0;
	path[source]=0;
	visit[source]=1;
	myqueue.push(source);

	while(!myqueue.empty())
	{
		int temp=myqueue.front();
		myqueue.pop();
		visit[temp]=0;
		for(int i=1;i<=n;++i)
			if(path[i]-path[temp]>farm[temp][i])
			{
				path[i]=path[temp]+farm[temp][i];
				if(!visit[i])
					myqueue.push(i),visit[i]=1;
			}
	}
}

int main(void)
{
#ifdef DEBUG  
	freopen("data.txt","r",stdin);  
#endif  

	int n,m,x,a,b,len;

	while(scanf("%d %d %d",&n,&m,&x)!=EOF)
	{
		for(int i=1;i<=n;++i)
		{
			for(int j=i+1;j<=n;++j)
				farm1[i][j]=farm1[j][i]=farm2[i][j]=farm2[j][i]=maxint;
			farm1[i][i]=farm2[i][i]=0;
		}
		for(int i=0;i<m;++i)
		{
			scanf("%d %d %d",&a,&b,&len);
			if(farm1[a][b]>len)
				farm1[a][b]=farm2[b][a]=len;
		}
		
		SPFA(farm1,x,n,path1);
		SPFA(farm2,x,n,path2);

		int maxlen=0;
		for(int i=1;i<=n;++i)
			if(maxlen-path1[i]<path2[i])
				maxlen=path1[i]+path2[i];
		printf("%d\n",maxlen);
	}

	return 0;
}
