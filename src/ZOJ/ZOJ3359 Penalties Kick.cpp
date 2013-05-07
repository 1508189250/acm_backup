// ZOJ3359 Penalties Kick.cpp : Defines the entry point for the console application.
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

int main(void)
{
// 	ifstream cin("data.txt");
	int ncases;
	int casenum;
	char str1[4],str2[4],str3[4];
	cin>>ncases;
	int kick[3][22];
	for(casenum=1;casenum<=ncases;++casenum)
	{
		for(int i=0;i<22;++i)
		{
			scanf("%s %s %s",&str1,&str2,&str3);
			if (str1[0]=='y')
			{
				kick[0][i]=1;
			} 
			else
			{
				kick[0][i]=0;
			}
			if (str2[0]=='y')
			{
				kick[1][i]=1;
			} 
			else
			{
				kick[1][i]=0;
			}
			if (str3[0]=='y')
			{
				kick[2][i]=1;
			} 
			else
			{
				kick[2][i]=0;
			}
		}

		int away(0),home(0),count(0);
		int flag(1);

		printf("Match %d:\n",casenum);

		for(int i=0;i<3 && flag;++i)
		{
		
			for(int j=0;j<11;++j)
			{
				++count;
				home += kick[i][j];
				if(count<6 && home-away>5-count+1)
				{
					printf("Winner: home\nScore: %d:%d\n",home,away);
					flag=0;
					break;
				}
				if(count<6 && away-home>5-count)
				{
					printf("Winner: away\nScore: %d:%d\n",home,away);
					flag=0;
					break;
				}


				away += kick[i][j+11];

				if(count<6 && home-away>5-count)
				{
					printf("Winner: home\nScore: %d:%d\n",home,away);
					flag=0;
					break;
				}

				if(count<6 && away-home>5-count)
				{
					printf("Winner: away\nScore: %d:%d\n",home,away);
					flag=0;
					break;
				}

				if (count>5 && home>away)
				{
					printf("Winner: home\nScore: %d:%d\n",home,away);
					flag=0;
					break;
				} 
				else if(count>5 && away>home)
				{
					printf("Winner: away\nScore: %d:%d\n",home,away);
					flag=0;
					break;
				}
					
			}
		}


	}


	return 0;
}
