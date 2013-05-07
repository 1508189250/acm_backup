/*******************************************************************************
 * Author : Neo Fung
 * Email : neosfung@gmail.com
 * Last modified : 2011-09-07 16:47
 * Filename : ZOJ1871 POJ2590 Steps.cpp
 * Description : 
 * *****************************************************************************/
// ZOJ1871 POJ2590 Steps.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"



#include <stdio.h>
#include <string.h>

int main(void)
{
	int ncases;
	int a,b,len;
	char str[50];

	while(gets(str) && strlen(str))
	{
		sscanf(str,"%d %d",&a,&b);
// 		if (a==b)
// 		{
// 			printf("0\n");
// 			continue;
// 		}
		len=b-a;

		int temp=0;
		int index;
		for(int i=0;;++i)
		{
			if(len<=temp+(i+1)/2)
			{
				index=i;
				break;
			}
			temp+=(i+1)/2;
		}
		printf("%d\n",index);
	}

	return 0;
}
