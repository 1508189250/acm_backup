/*******************************************************************************
 * Author : Neo Fung
 * Email : neosfung@gmail.com
 * Last modified : 2011-08-29 18:54
 * Filename : ZOJ2510 Concentric Rings.cpp
 * Description : 
 * *****************************************************************************/
// ZOJ2510 Concentric Rings.cpp : Defines the entry point for the console application.
//

// #include "stdafx.h"



#include <fstream>
#include <stdio.h>
#include <iostream>
#include <memory>
#include <string.h>
#include <algorithm>

using namespace std;

struct radius
{
	int inner,outer;
};

bool cmp(const radius &lhs,const radius &rhs)
{
	return lhs.outer<rhs.outer;
}

int main(void)
{
// 	ifstream cin("data.txt");
	int n;
	int flag[10010];

	while(cin>>n)
	{
		int sum=1;
		memset(flag,0,sizeof(flag));
		radius *record = new radius[n];
		for(int i=0;i<n;++i)
		{
			cin>>record[i].inner>>record[i].outer;
		}
		sort(record,record+n,cmp);

		int index=0;
		flag[index]=0;
		for(int i=1;i<n;++i)
			if(record[i].inner>=record[index].outer)
			{
				++sum;
				index=i;
			}

		cout<<n-sum<<endl;

		delete []record;
	}


	return 0;
}
