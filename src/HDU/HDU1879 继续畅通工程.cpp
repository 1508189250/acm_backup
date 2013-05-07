/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2012-06-13 16:07
 # Filename: acm.cpp
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
using namespace std;

const int kMAX=110;
const double kEPS=10E-6;

int map[kMAX][kMAX],dist[kMAX];
bool visit[kMAX];

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

  int n;
	int u,v,d,c;

  while(~scanf("%d",&n) && n)
  {
		int m=n*(n-1)/2.0;
		memset(map,0,sizeof(map));

		while(m--)
		{
			scanf("%d%d%d%d",&u,&v,&d,&c);
			if(!c)
				map[u][v]=map[v][u]=d;
		}

		int ans=0;
		memset(visit,false,sizeof(visit));
		for(int i=2;i<=n;++i)
			dist[i]=INT_MAX;
		dist[1]=0;

		for(int i=0;i<n;++i)
		{
			int min_len=INT_MAX;
			int idx=1;
			for(int j=1;j<=n;++j)
				if(!visit[j] && dist[j]<min_len)
        {
          min_len=dist[j];
					idx=j;
        }

			visit[idx]=true;
			ans+=dist[idx];

			for(int j=1;j<=n;++j)
				if(!visit[j] && dist[j]>map[idx][j])
					dist[j]=map[idx][j];
		}

		printf("%d\n",ans);
  }

  return 0;
}

