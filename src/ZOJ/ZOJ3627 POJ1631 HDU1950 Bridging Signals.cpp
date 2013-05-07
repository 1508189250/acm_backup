/*******************************************************************************
 * Author : Neo Fung
 * Email : neosfung@gmail.com
 * Last modified : 2011-09-08 20:10
 * Filename : ZOJ3627 POJ1631 HDU1950 Bridging Signals.cpp
 * Description : ����һ��array���顣����array���飬���ڵ�һ��Ԫ�أ���ŵ��ǳ���
				Ϊi����������������С��ĩԪ�ء�ͬʱ��index����¼����������е�
				���ȶ����µ�����temp���������array[index]����
				array[++index]=temp����������array��������ĳ��λ��ops��
				array[ops]<temp��array[ops+1]>=temp����ʱ���Ը���array[ops+1]=temp��
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
