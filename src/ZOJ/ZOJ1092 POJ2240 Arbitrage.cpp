/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2011-08-15 19:07
 # Filename: ZOJ1092 POJ2240 Arbitrage.cpp
 # Description : 
 ******************************************************************************/
// ZOJ1092 POJ2240 Arbitrage.cpp : Defines the entry point for the console application.
//

// #include "stdafx.h"
#include <iostream>
#include <string>
#include <map>
#include <memory.h>

using namespace std;

#define INFINITE 0.0

int main(void)
{
	int n,m;
	double len;
	string str1,str2;
	map< string,int > mymap;
	double currency[35][35];
	int ncases(1);
	
	while(cin>>n &&n)
	{
		mymap.clear();
		for(int i=0;i<n;++i)
		{
			cin>>str1;
			mymap.insert( make_pair(str1,i));

			for(int j=0;j<n;++j)
				currency[i][j]=INFINITE;

			currency[i][i]=1;
		}

		cin>>m;
		for(int i=0;i<m;++i)
		{
			cin>>str1>>len>>str2;
			currency[mymap[str1]][mymap[str2]]=len;
		}

		for(int i=0;i<n;++i)
			for(int j=0;j<n;++j)
				for(int k=0;k<n;++k)
					if (currency[j][k]< currency[j][i]*currency[i][k])
					{
						currency[j][k] = currency[j][i]*currency[i][k];
					}

		bool flag(false);
		for (int i=0;i<n;++i)
		{
			if (currency[i][i]>1.0)
			{
				flag=1;
				break;
			}
		}

		cout<<"Case "<<ncases++<<": ";
		if (flag)
		{
			cout<<"Yes"<<endl;
		}
		else
			cout<<"No"<<endl;

	}
	return 0;
}
