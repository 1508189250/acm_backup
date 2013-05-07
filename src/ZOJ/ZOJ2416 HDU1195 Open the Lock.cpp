/*******************************************************************************
 * Author : Neo Fung
 * Email : neosfung@gmail.com
 * Last modified : 2011-09-06 13:46
 * Filename : ZOJ2416 HDU1195 Open the Lock.cpp
 * Description : 
 * *****************************************************************************/
// ZOJ2416 HDU1195 Open the Lock.cpp : Defines the entry point for the console application.
//

// #include "stdafx.h"



#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <memory>
#include <set>
#include <queue>

using namespace std;

int inline sum(int *array)
{
	return array[0]+array[1]*10+array[2]*100+array[3]*1000;
}

int main(void)
{
	int ncases;
	int source,target;
	int origenal[5],temp[5];
	queue<int> myqueue;
	int times[10000];

	scanf("%d",&ncases);

	while(ncases--)
	{
		while(!myqueue.empty())
			myqueue.pop();
		memset(times,0,sizeof(times));
		scanf("%d %d",&source,&target);
		myqueue.push(source);

		while(myqueue.front() != target)
		{
			source=myqueue.front();
			myqueue.pop();
			int tmp=source;
			for(int i=0;i<4;++i)
			{
				origenal[i]=tmp%10;
				tmp /=10;
			}

			//swap neighbor
			for(int i=0;i<3;++i)
			{
				memcpy(temp,origenal,sizeof(origenal));
				if (temp[i] != temp[i+1])
				{
					swap(temp[i],temp[i+1]);
					tmp=sum(temp);
					if(!times[tmp])
					{
						times[tmp]=times[source]+1;
						myqueue.push(tmp);
					}
				}
			}

			//add 1
			for(int i=0;i<4;++i)
			{
				memcpy(temp,origenal,sizeof(origenal));
				++temp[i];
				if(temp[i]>9)
					temp[i]=1;
				tmp=sum(temp);
				if(!times[tmp])
				{
					times[tmp]=times[source]+1;
					myqueue.push(tmp);
				}
			}

			//minus 1
			for(int i=0;i<4;++i)
			{
				memcpy(temp,origenal,sizeof(origenal));
				--temp[i];
				if(!temp[i])
					temp[i]=9;
				tmp=sum(temp);
				if(!times[tmp])
				{
					times[tmp]=times[source]+1;
					myqueue.push(tmp);
				}
			}
		}
		
		printf("%d\n",times[target]);
	}


	return 0;
}
