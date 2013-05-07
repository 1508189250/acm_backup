// ZOJ2014.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <stdio.h>
//#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;
int main(void)
{
	//ifstream cin("data.txt");
	int ncases,empty,full,grams,weight;
	int N;
	int P[501],W[501];
	int value[10001];
	cin >> ncases;
	while(ncases>0)
	{
		cin>>empty>>full;
		grams = full-empty;
		cin>>N;
		for(int i=1; i<=N;++i)
		{
			cin>>P[i]>>W[i];
			P[i]= -P[i];
		}
		//memset(value,-1000,501*sizeof(int));
 		for (int i = 0;i <=10000;++i)
 		{
 			value[i]=-10000000;
  		}
		value[0]=0;
		for(int i=1;i<=N;++i)
		{
			for(weight = W[i] ; weight<=grams;++weight)
			{
				value[weight]=max(value[weight],value[weight-W[i]]+P[i]);
			}
		}
		if (value[grams] == -10000000 )
		{
			printf("This is impossible.\n");
		} 
		else
		{
			printf("The minimum amount of money in the piggy-bank is %d.\n",-value[grams]);
		}
		--ncases;
	}

	return 0;
}
