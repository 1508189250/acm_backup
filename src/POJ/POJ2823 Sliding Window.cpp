/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2012-07-20 19:55
 # Filename: POJ2823 Sliding Window.cpp
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

const int kMAX=1000010;
const double kEPS=10E-6;

int input[kMAX],output[kMAX],queue[kMAX],index[kMAX];

int MaxFunc(const int &n,const int &size)
{
	int cnt=0,front=0,back=0;

	for(int i=0;i<n;++i)
	{
		while(front<back && input[i]>queue[back-1])
			--back;

		queue[back]=input[i];
		index[back]=i;

		while(front<back && i - index[front] >= size)
			++front;

		if(i>=(size-1))
			output[cnt++]=queue[front];
		++back;
	}
	return cnt;
}

int MinFunc(const int &n,const int &size)
{
	int cnt=0,front=0,back=0;

	for(int i=0;i<n;++i)
	{
		while(front<back && input[i]<queue[back-1])
			--back;

		queue[back]=input[i];
		index[back]=i;

		while(front<back && i - index[front] >= size)
			++front;

		if(i>=(size-1))
			output[cnt++]=queue[front];
		++back;
	}
	return cnt;
}

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

  int n,m;

  while(~scanf("%d%d",&n,&m) && n)
  {
		for(int i=0;i<n;++i)
			scanf("%d",&input[i]);

		int cnt=MinFunc(n,m);
		for(int i=0;i<cnt;++i)
			printf("%d%c",output[i],i==(cnt-1)?'\n':' ');

		cnt=MaxFunc(n,m);
		for(int i=0;i<cnt;++i)
			printf("%d%c",output[i],i==(cnt-1)?'\n':' ');
  }

  return 0;
}

