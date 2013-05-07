/*******************************************************************************
 * Author : Neo Fung
 * Email : neosfung@gmail.com
 * Last modified : 2011-07-31 14:08
 * Filename : ZOJ1715 POJ2028 When Can We Meet.cpp
 * Description : 
 * *****************************************************************************/
// ZOJ1715 POJ2028 When Can We Meet.cpp : Defines the entry point for the console application.
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
	int N,Q;
	int index,M;

	while(cin>>N>>Q && (N||Q))
	{
		vector<int> myvec(100,0);
		vector<int>::iterator iter;

		for(int i=0;i<N;++i)
		{
			cin>>M;
			for(int j=0;j<M;++j)
			{
				cin>>index;
				++myvec.at(index);
			}
		}

		for(int i=N;i>=Q;--i)
		{
			iter=find(myvec.begin(),myvec.end(),i);
			if(iter !=myvec.end())
			{
				cout<<distance(myvec.begin(),iter)<<endl;
				break;
			}
			else if(i==Q)
			{
				cout<<0<<endl;
			}
		}

	}


	return 0;
}
