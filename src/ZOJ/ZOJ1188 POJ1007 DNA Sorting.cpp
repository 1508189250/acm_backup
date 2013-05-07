// ZOJ1188 POJ1007 DNA Sorting.cpp : Defines the entry point for the console application.
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
#include <assert.h>
#include <ctype.h>

using namespace std;

bool cmp(const pair<int,string> &lhs,const pair<int,string> &rhs)
{
	return lhs.first<rhs.first;
}

int main(void)
{
// 	ifstream cin("data.txt");
	int n,m,ncases,flag=1;
	string str;
	vector<pair<int,string> > myvec;

// 	cin>>ncases;
	ncases=1;

	while(ncases--)
	{
		cin>>n>>m;
		myvec.clear();
		for(int i=0;i<m;++i)
		{
			int sum=0;
			cin>>str;
			for(int j=0;j<str.length();++j)
				for(int k=j+1;k<str.length();++k)
					if(str.at(j)>str.at(k))
						++sum;

			myvec.push_back(make_pair(sum,str));
		}

		stable_sort(myvec.begin(),myvec.end(),cmp);

		if(flag)
			flag=0;
		else
			cout<<endl;

		for(vector< pair<int ,string> >::iterator iter=myvec.begin();iter !=myvec.end();++iter)
		{
			cout<<(*iter).second<<endl;
		}

	}



	return 0;
}


