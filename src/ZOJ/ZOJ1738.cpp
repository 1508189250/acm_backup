// ZOJ1738.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <fstream>

#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
//#define MAX_INTER 1<<15;

using namespace std;

int main(void)
{
	//ifstream cin("data.txt");
	const int MAX_INTER=1<<15;
	int squre[MAX_INTER+1][5]={0};
	squre[0][0]=1;
	int temp;


	int i,j,k;

	for(i = 1;i<=182;++i)
	{
		temp=i*i;

		for(j=0;j<=MAX_INTER;++j)
		{
			
			if(j+temp>MAX_INTER) break;
			else
			{
				for(k=1;k<5;++k)
				{
					squre[j+temp][k] +=squre[j][k-1];
				}
			}
		}

	}
	while(cin>>temp&&temp)
		cout<<squre[temp][1]+squre[temp][2]+squre[temp][3]+squre[temp][4]<<endl;




	return 0;
}
