/*******************************************************************************
 * Author : Neo Fung
 * Email : neosfung@gmail.com
 * Last modified : 2011-09-08 20:10
 * Filename : ZOJ3627 POJ1631 HDU1950 Bridging Signals.cpp
 * Description : 设置一个array数组。对于array数组，对于第一个元素，存放的是长度
				为i的上升子序列中最小的末元素。同时用index来记录最长上升子序列的
				长度对于新的输入temp，如果它比array[index]大，则
				array[++index]=temp；否则，则在array中搜索到某个位置ops，
				array[ops]<temp，array[ops+1]>=temp，这时可以更新array[ops+1]=temp。
 * *****************************************************************************/
// ZOJ3627 POJ1631 HDU1950 Bridging Signals.cpp : Defines the entry point for the console application.
//

// #include "stdafx.h"



#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <memory.h>

using namespace std;

int array[50000];

void birfind(const int &a,const int &b,const int &data)
{
	if(a==b)
		array[a]=data;
	else if(a>b)
		return;
	else
	{
		int mid=a+(b-a)/2;
		if(array[mid]<data && array[mid+1]>=data)
			array[mid+1]=data;
		else if(array[mid]>=data)
			birfind(a,mid,data);
		else
			birfind(mid+1,b,data);
	}
}

int main(void)
{
	int p;
	int num[50000];
	int temp;
	int ncases;
	scanf("%d",&ncases);
	while(ncases--)
	{
		scanf("%d",&p);
		memset(array,0,sizeof(array));
		int index=0;
		for(int i=1;i<=p;++i)
		{
			scanf("%d",&temp);
			if(temp>array[index])
				array[++index]=temp;
			else
			{
				birfind(1,index,temp);
			}
		}
		printf("%d\n",index);
	}


	return 0;
}
