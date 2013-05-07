/*******************************************************************************
 * Author : Neo Fung
 * Email : neosfung@gmail.com
 * Last modified : 2011-07-28 12:09
 * Filename : ZOJ1291 POJ1503 Integer Inquiry.cpp
 * Description : 
 * *****************************************************************************/
// ZOJ1291 POJ1503 Integer Inquiry.cpp : Defines the entry point for the console application.
//

// #include "stdafx.h"



#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <math.h>
#include <algorithm>
#include <numeric>
#include <functional>
#include <memory.h>

using namespace std;

#define MAXLENGTH 110

void longintegersum(int sum[MAXLENGTH],int temp[MAXLENGTH])
{
	for(int i=0;i<MAXLENGTH-1;++i)
	{
		sum[i] +=temp[i];
		if(sum[i]>9)
		{
			sum[i] %=10;
			++sum[i+1];
		}
	}
}

int main(void)
{
// 	ifstream cin("data.txt");
	int ncases;
	int firstcase=1;
	string str;
	int sum[MAXLENGTH],temp[MAXLENGTH];

	cin>>ncases;	//ZOJÓÃ
// 	ncases=1;		//POJÓÃ

	while(ncases--)
	{

		memset(sum,0,sizeof(sum));
		memset(temp,0,sizeof(temp));

		while(cin>>str && str!="0")
		{
			int i(str.length()-1);
			int j(0);
			for(;i>=0;--i,++j)
			{
				temp[j]=str.at(i)-'0';
			}

			longintegersum(sum,temp);
		}

		if(!firstcase)
		{
			printf("\n");
		}
		else
			firstcase=0;

		int flag=0;
		for(int i=MAXLENGTH-1;i>=0;--i)
		{
			if(sum[i]||flag)
			{
				flag=1;
				printf("%d",sum[i]);
			}
		}
		printf("\n");

	}


	return 0;
}
