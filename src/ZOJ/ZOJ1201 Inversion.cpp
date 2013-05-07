/*******************************************************************************
 * Author : Neo Fung
 * Email : neosfung@gmail.com
 * Last modified : 2011-07-25 19:36
 * Filename : ZOJ1201 Inversion.cpp
 * Description : http://acm.zju.edu.cn/onlinejudge/showProblem.do?problemCode=1201
 * *****************************************************************************/
// ZOJ1201 Inversion.cpp : Defines the entry point for the console application.
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



void p2i(int n)
{
	vector<int> myVec;
	vector<int> result;
	vector<int>::iterator iter;
	int temp;
	int count;

	for(int i=0;i<n;++i)
	{
		cin>>temp;
		myVec.push_back(temp);
	}
	for(int i=1;i<=n;++i)
	{
		count=0;
		for(iter = find(myVec.begin(),myVec.end(),i);iter>=myVec.begin();--iter)
		{
			if(*iter>i) ++count;
		}
		result.push_back(count);
	}

	for(iter = result.begin();iter!=result.end();++iter)
		if (iter !=result.begin())
		{
			cout<<' ' <<*iter;
		}
		else
			cout<<*iter;
	cout<<endl;
}

void i2p(int n)
{
	vector<int> myvec;
	vector<int> result;
	vector<int>::iterator iter;
	vector<int>::iterator insertIter;
	int temp;
// 	int k;
	
	for(int i=0;i<n;++i)
	{
		cin>>temp;
		myvec.push_back(temp);
	}

	for(int i=0;i<=n;++i)
	{
		for(int j=0;j<n;++j)
		{

			if(myvec.at(j)==i)
			{

				if (!i)
				{
					result.push_back(j+1);
				} 
				else
				{
					int count(i);
					for (iter = result.begin();iter!=result.end();++iter)
					{
						if (*iter > j+1 )
						{
							--count;
						}
						if (count==0)
						{
							insertIter = iter+1;
						}
						if (myvec.at(*iter-1)==i)
						{
							insertIter = iter+1;
						}
					}
					result.insert(insertIter,j+1);
				}
			}
		}
	}
	for(iter = result.begin();iter!=result.end();++iter)
		if (iter !=result.begin())
		{
			cout<<' ' <<*iter;
		}
		else
			cout<<*iter;
	cout<<endl;
}

int main(void)
{
	int n;
	char ch;
	while(cin>>n && n)
	{
		cin>>ch;
		if (ch == 'P')
		{
			p2i(n);
		} 
		else
		{
			i2p(n);
		}
	}


	return 0;
}
