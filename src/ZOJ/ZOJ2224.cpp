// ZOJ2224.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <stdio.h>
#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;

int main(void)
{
	//ifstream cin("data.txt");
	int ncases;
	cin>>ncases;
	int amount,years;
	int d,bonds[11],interest[11];
	int value[46001];
	int i,j,k,sum;
	while(ncases>0)
	{
		cin>>amount>>years;
		cin>>d;
		for(i=1;i<=d;++i)
		{
			cin>>bonds[i]>>interest[i];
			bonds[i] /=1000;
		}
		sum=amount;
		while(years--)
		{
			amount=sum/1000;

			for(i=0;i<46001;++i)
				value[i]=0;
			for(j=1;j<=d;j++)
				for(int v=bonds[j];v<=amount;++v)
				{
					value[v] = max(value[v],value[v-bonds[j]]+interest[j]);
				}
			sum +=value[amount];

		}
		printf("%d\n",sum);
		--ncases;
	}


	return 0;
}
