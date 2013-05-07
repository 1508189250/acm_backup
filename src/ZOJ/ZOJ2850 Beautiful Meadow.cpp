/*******************************************************************************
# Author : Neo Fung
# Email : neosfung@gmail.com
# Last modified: 2011-08-14 10:49
# Filename: ZOJ2850 Beautiful Meadow.cpp
# Description : 
******************************************************************************/
// ZOJ2850 Beautiful Meadow.cpp : Defines the entry point for the console application.
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
#include <limits>

using namespace std;

int main(void)
{
// 	ifstream cin("data.txt");
	int meadow[12][12];
	int N,M;

	while(cin>>N>>M &&(N||M))
	{
		int flag(1);
		int mowed(0);
		for(int i=0;i<N;++i)
		{
			for(int j=0;j<M;++j)
			{
				cin>>meadow[i][j];
			}
		}


		for(int i=0;i<N && flag;++i)
		{
			for(int j=0;j<M && flag;++j)
			{
				if(!meadow[i][j])
				{
					if(i>0 && !meadow[i-1][j])
						flag=0;
					else if(i<N-1 && !meadow[i+1][j])
						flag=0;
					else if(j>0 && !meadow[i][j-1])
						flag=0;
					else if(j<M-1 && !meadow[i][j+1])
						flag=0;
					mowed=1;
				}
			}
		}



		if(flag && mowed)
			cout<<"Yes"<<endl;
		else
		{
			cout<<"No"<<endl;
		}

	}


	return 0;
}
