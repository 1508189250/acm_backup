// ZOJ1108.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <fstream>

#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool second_sort(const pair<int,int> &lhs,const pair<int,int> &rhs)
{
	return	(rhs.second < lhs.second)?true:false;
}

int main(void)
{
	//ifstream cin("data.txt");
	vector<pair<int,int> > WSVec;
	vector<pair<int,int> > linkVec;

	int weight=0,speed,count=0;
	WSVec.push_back(make_pair(0,0));
	linkVec.push_back(make_pair(0,0));

	while(cin>>weight>>speed)
	{
		++count;
		WSVec.push_back(make_pair(weight,speed));
		linkVec.push_back(make_pair(count,speed));
	}
	sort(WSVec.begin()+1,WSVec.end(),second_sort);
	sort(linkVec.begin()+1,linkVec.end(),second_sort);

	int dp[1<<16],link[1<<16];
	int	length=WSVec.size();
	dp[1]=1;
	link[1]=-1;
	int maxdp,maxindex;
	for(int i=2;i<length;++i)
	{
		maxdp=0;
		maxindex=-1;
		for(int j=i-1;j>0;--j)
		{
			if(WSVec.at(i).first>WSVec.at(j).first && dp[j]>maxdp)
			{
				maxindex = j;
				maxdp = dp[j];
			}

		}

		link[i]=maxindex;
		dp[i]=maxdp+1;
	}
	maxdp=-1;
	vector<int> stack;
	for(int i=1;i<=length;++i)
	{
		if(dp[i]>maxdp) 
		{
			maxdp=dp[i];
			maxindex=i;
		}
	}

	cout<<maxdp<<endl;
	for (int i=1;i<=maxdp,maxindex>0;++i)
	{
		speed = linkVec.at(maxindex).first;
		stack.push_back(linkVec.at(maxindex).first);
		maxindex=link[maxindex];
	}
	for (vector<int>::reverse_iterator iter= stack.rbegin();iter!=stack.rend();iter++)
	{
		
		cout<<*iter<<endl;
	}
	return 0;
}
