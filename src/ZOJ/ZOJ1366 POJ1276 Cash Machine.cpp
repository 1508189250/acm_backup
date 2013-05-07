/*******************************************************************************
 * Author : Neo Fung
 * Email : neosfung@gmail.com
 * Last modified : 2011-07-18 20:59
 * Filename : ZOJ1366 POJ1276 Cash Machine.cpp
 * Description : 
 * *****************************************************************************/
/*******************************************************************************
 * Author : Neo Fung
 * Email : neosfung@gmail.com
 * Last modified : 2011-07-18 17:41
 * Filename : ZOJ1366 POJ1276 Cash Machine.cpp
 * Description :	http://acm.zju.edu.cn/onlinejudge/showProblem.do?problemCode=1366
					http://poj.org/problem?id=1276
 * *****************************************************************************/
// ZOJ1366 POJ1276 Cash Machine.cpp : Defines the entry point for the console application.
//

// #include "stdafx.h"



#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <vector>
#include <stack>
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
	int cash,N;
	int n,D;
	int temp;
	vector<int> cashVec;
	int *DP=new int[100001];
	int power[]={1,2,4,8,16,32,64,128,256,512};


	while(cin>>cash>>N)
	{

		for (int i=0;i<=cash;++i)
		{
			DP[i]=0;
		}
		DP[0]=0;
		cashVec.clear();
		cashVec.push_back(0);

		for(int i=1;i<=N;++i)
		{
			cin>>n>>D;
			if(!n) 
				temp=0;
			else
				temp = log((n+1)*1.0) / log(2.0) + 0.99999999;


			for(int j=0;j<temp;++j)
			{
				if(n>power[j])
				{
					cashVec.push_back(D*power[j]);
					n -=power[j];
				}
				else
				{
					cashVec.push_back(n*D);
				}
			}
		}

		if(cash == 0 || N==0)
		{
			cout<<0<<endl;
			continue;
		}

		for(int i=1;i<cashVec.size();++i)
			if (cash < cashVec.at(i))
			{
				continue;
			}
			else
			{
				for(int j=cash;j>= cashVec.at(i);--j)
				{
					// 				if(j<=cashVec.at(i))
					DP[j] = max(DP[j],DP[j-cashVec.at(i)]+cashVec.at(i));
				}
			}


		cout<<DP[cash]<<endl;
	}

	cashVec.clear();
	delete []DP;

	return 0;
}
