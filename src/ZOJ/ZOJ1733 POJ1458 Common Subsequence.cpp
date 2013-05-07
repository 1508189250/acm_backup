/*******************************************************************************
 * Author : Neo Fung
 * Email : neosfung@gmail.com
 * Last modified : 2011-09-03 15:17
 * Filename : ZOJ1733 POJ1458 Common Subsequence.cpp
 * Description : 
 * *****************************************************************************/
// ZOJ1733 POJ1458 Common Subsequence.cpp : Defines the entry point for the console application.
//

// #include "stdafx.h"

#include <string>
#include <iostream>
#include <fstream>
#include <string.h>


#define MAX 500

using namespace std;

int max3(const int &a,const int &b,const int &c)
{
	int temp=max(a,b);
	temp=max(temp,c);
	return temp;
}

int main(void)
{
// 	ifstream cin("data.txt");
	string lhs,rhs;
	int dp[MAX][MAX];

	while(cin>>lhs>>rhs)
	{
		memset(dp,0,sizeof(dp));

		for(int i=1;i<=lhs.length();++i)
		{
			for(int j=1;j<=rhs.length();++j)
			{
				int temp=(lhs.at(i-1)==rhs.at(j-1))?1:0;
				dp[i][j]=max3(dp[i-1][j-1]+temp,dp[i][j-1],dp[i-1][j]);
			}
		}

		cout<<dp[lhs.length()][rhs.length()]<<endl;
	}


	return 0;
}
