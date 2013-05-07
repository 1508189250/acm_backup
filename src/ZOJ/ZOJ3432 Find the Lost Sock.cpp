/*******************************************************************************
 * Author : Neo Fung
 * Email : neosfung@gmail.com
 * Last modified : 2011-09-01 16:17
 * Filename : ZOJ3432 Find the Lost Sock.cpp
 * Description : 
 * *****************************************************************************/
// ZOJ3432 Find the Lost Sock.cpp : Defines the entry point for the console application.
//

// #include "stdafx.h"



#include <stdio.h>
#include <string.h>
#include <string>

using namespace std;

int main(void)
{
	int n;
	char str[8],ch;
	while(scanf("%d",&n)!=EOF)
	{
		memset(str,'\0',sizeof(str));
		
		for(int i=0;i<n*2-1;++i)
		{
			getchar();
			for(int j=0;j<7;++j)
			{
				ch=getchar();
				str[j] = str[j]^ch;
			}
		}

		printf("%s\n",str);
	}


	return 0;
}
