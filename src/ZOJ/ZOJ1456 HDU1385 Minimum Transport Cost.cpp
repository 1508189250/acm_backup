/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2011-08-14 16:52
 # Filename: ZOJ1456 HDU1385 Minimum Transport Cost.cpp
 # Description : 
 ******************************************************************************/
// ZOJ1456 HDU1385 Minimum Transport Cost.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"



#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string>
#include <stack>
#include <numeric>
#include <memory.h>
#include <limits>

using namespace std;

#define INFINITE numeric_limits<int>::max()
#define MAX_LENGTH 200

void dijkstra(int (*map)[MAX_LENGTH],int (*lastvisit)[MAX_LENGTH],int (*minpath)[MAX_LENGTH],int *tax,int N)
{
	int *visit = new int[N+1];
	for(int source=1;source<=N;++source)
	{
		for(int j=1;j<=N;++j)
		{
			minpath[source][j]=map[source][j];
			if (minpath[source][j] <INFINITE)
			{
				lastvisit[source][j]=source;
			}
			visit[j]=0;
		}

		visit[source]=1;
		lastvisit[source][source]=0;

		for(int findnext=1;findnext<N;++findnext)
		{
			int min=INFINITE;
			int index=findnext;
			for(int findmin=1;findmin<=N;++findmin)
				if(!visit[findmin] &&min>minpath[source][findmin])
				{
					min=minpath[source][findmin];
					index=findmin;
				}

			visit[index]=1;

			for(int update=1;update<=N;++update)
			{

				if((!visit[update] && map[index][update] <INFINITE&&
					(minpath[source][update]> min+map[index][update]+tax[index])))
				{
					minpath[source][update]=min+map[index][update]+tax[index];
					lastvisit[source][update]=index;
				}


				//¥ µ‰–Ú
				else if (!visit[update]&&map[index][update]<INFINITE/*&&index<lastvisit[source][update]*/&&
					(minpath[source][update]==min+map[index][update]+tax[index]))
				{
					stack<int> lhs;
					stack<int> rhs;
					int oldindex(lastvisit[source][update]);
					int newindex(index);

					lhs.push(update);
					rhs.push(update);
					lhs.push(oldindex);
					rhs.push(newindex);

					while(lastvisit[source][oldindex])
					{
						oldindex=lastvisit[source][oldindex];
						lhs.push(oldindex);
					}
					while(lastvisit[source][newindex])
					{
						newindex=lastvisit[source][newindex];
						rhs.push(newindex);
					}


					int flag(0);
					while(!lhs.empty()&&!rhs.empty())
					{
						if (lhs.top()>rhs.top())
						{
							flag=1;
							break;
						}
						else if (lhs.top()<rhs.top())
						{
							break;
						}
						else
						{
							lhs.pop();
							rhs.pop();
						}
					}

					if(flag || rhs.empty())
						lastvisit[source][update]=index;
				}
			}
		}
	}
	delete [] visit;
}

int main(void)
{
	ifstream cin("data.txt");
	int N;
	int map[MAX_LENGTH][MAX_LENGTH];
	int lastvisit[MAX_LENGTH][MAX_LENGTH];
	int minpath[MAX_LENGTH][MAX_LENGTH];
	int tax[MAX_LENGTH];
	stack<int> record;
	int source,destination;

	while(cin>>N && N)
	{
		for(int i=1;i<=N;++i)
		{
			for(int j=1;j<=N;++j)
			{
				cin>>map[i][j];
				if (map[i][j]==-1)
				{
					map[i][j]=INFINITE;
				}
			}
		}
		for(int i=1;i<=N;++i)
			cin>>tax[i];

		dijkstra(map,lastvisit,minpath,tax,N);

		while(cin>>source>>destination && source!=-1 && destination!=-1)
		{
			while(!record.empty()) record.pop();
			record.push(destination);
			int index(destination);
			while(lastvisit[source][index]!=source && lastvisit[source][index])
			{
				index=lastvisit[source][index];
				record.push(index);
			}
			printf("From %d to %d :\n",source,destination);

			printf("Path: %d",source);
			if(source!=destination)
			{
			while(!record.empty())
			{
					printf("-->%d",record.top());
					record.pop();
			}
			}
			printf("\n");

			printf("Total cost : %d\n\n",minpath[source][destination]);
		}
	}


	return 0;
}
