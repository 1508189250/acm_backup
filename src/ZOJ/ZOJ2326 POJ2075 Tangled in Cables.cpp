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
#include <map>
#define MAX 500
#define maxdou 1<<30

using namespace std;

map<string,int> names;
int n,m,visit[MAX],pre[MAX];
double matrix[MAX][MAX],dist[MAX];

void init()
{
	names.clear();
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<n;++j)
			matrix[i][j]=maxdou;
		matrix[i][i]=0.0;
		pre[i]=i;
		dist[i]=maxdou;
	}
	memset(visit,0,sizeof(visit));
}

double cableLen()
{
	double sum=0.0;
	for(int j=0;j<n;++j)
		sum+=dist[j];
	return sum;
}

int main(void)
{
#ifdef DEBUG  
	freopen("data.txt","r",stdin);  
#endif  
	double maxlen,len;
	string str,stra,strb;

	while(scanf("%lf",&maxlen)!=EOF)
	{
		scanf("%d",&n);
		init();
		for(int i=0;i<n;++i)
		{
			cin>>str;
			names[str]=i;
		}
		scanf("%d",&m);
		while(m--)
		{
			cin>>stra>>strb>>len;
			matrix[names[stra]][names[strb]]=len;
			matrix[names[strb]][names[stra]]=len;
		}

		visit[0]=1;
		dist[0]=0;
		int minIndex=0;

		for(int ind=1;ind<n;++ind)
		{
			for(int i=0;i<n;++i)
				if(!visit[i] && dist[i]>matrix[minIndex][i])
				{
					dist[i]=matrix[minIndex][i];
				}

			double minlen=maxdou;
			minIndex=-1;
			for(int i=0;i<n;++i)
				if(!visit[i] && (minIndex==-1||dist[i]<minlen))
				{
					minlen=dist[i];
					minIndex=i;
				}
			if(minIndex>-1) visit[minIndex]=1;
		}

		double minlen=cableLen();

		if(minlen>maxlen)
			printf("Not enough cable\n");
		else
			printf("Need %0.1lf miles of cable\n",minlen);

	}

	return 0;
}
