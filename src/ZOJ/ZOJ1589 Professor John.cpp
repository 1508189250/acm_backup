/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2011-08-17 13:42
 # Filename: ZOJ1589 Professor John.cpp
 # Description : 
 ******************************************************************************/
// ZOJ1589 Professor John.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"



#include <stdio.h>
#include <memory.h>

using namespace std;

int main(void)
{
// 	ifstream cin("data.txt");
	int ncase;
	int m;
	int map[30][30];
	int mark[30][30];
	int lhs,rhs;
	char oprat;
	char str[5];

	scanf("%d",&ncase);

	for(int casenum=1;casenum<=ncase;++casenum)
	{
		int flag(1);

		memset(map,0,sizeof(map));

		scanf("%d",&m);
		for(int i=0;i<m;++i)
		{
// 			cin>>lhs>>oprat>>rhs;
			scanf("%s",&str);
			lhs=str[0]-'A';
			rhs=str[2]-'A';
			oprat=str[1];
			if(oprat=='<')
			{
				map[lhs][rhs]=1;
			}
			else

			{
				map[rhs][lhs]=1;
			}
		}

		memcpy(mark,map,sizeof(map));

		for(int k=0;k<30 ;++k)
		{
			for(int i=0;i<30 ;++i)
			{
				for(int j=0;j<30 ;++j)
				{
					map[i][j] = map[i][j] || map[i][k] && map[k][j];
				}

			}
		}

		printf("Case %d:\n",casenum);
		for(int i=0;i<30;++i)
		{
			for(int j=0;j<30;++j)
			{

				if((map[i][j]) && !mark[i][j] )
				{
					printf("%c<%c\n",i+'A',j+'A');
					flag=0;
				}
			}
		}
		if(flag)
			printf("NONE\n");

	}


	return 0;
}
