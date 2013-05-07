/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2011-08-28 12:53
 # Filename: ZOJ1711 POJ1564 Sum It Up.cpp
 # Description : 
 ******************************************************************************/
// ZOJ1711 POJ1564 Sum It Up.cpp : Defines the entry point for the console application.
//

// #include "stdafx.h"



#include <iostream>
#include <set>

using namespace std;

typedef multiset<int,greater<int> > ELEM;

set<ELEM > result;
int num[20];
int t,n;

void dfs(int x,int remain,ELEM &myelem)
{
	if(x==n)
	{
		return;
	}
	else if(num[x]==remain)
	{
		myelem.insert(num[x]);
		result.insert(myelem);
		ELEM::iterator iter=myelem.find(num[x]);
		myelem.erase(iter);
		return;
	}
	else if(num[x]<remain)
	{
		myelem.insert(num[x]);
		remain-=num[x];
		for(int i=x+1;i<n;++i)
			dfs(i,remain,myelem);
		remain+=num[x];
		ELEM::iterator iter=myelem.find(num[x]);
		myelem.erase(iter);
		return;
	}
}

int main(void)
{
// 	ifstream cin("data.txt");

	while(cin>>t>>n && t &&n)
	{
		ELEM myelem;
		result.clear();
		for(int i=0;i<n;++i)
			cin>>num[i];
		for(int i=0;i<n;++i)
			dfs(i,t,myelem);
		cout<<"Sums of "<<t<<':'<<endl;
		if (result.empty())
		{
			cout<<"NONE"<<endl;
		}
		for(set<ELEM >::reverse_iterator iter1= result.rbegin();iter1 != result.rend();++iter1)
		{
			int flag=1;
			for(ELEM::const_iterator iter2=iter1->begin();iter2 != iter1->end();++iter2)
				//必须要用const_iterator，否则编译不通过
			{
				if(flag)
					flag=0;
				else
					cout<<'+';
				cout<<*iter2;
			}
			cout<<endl;
		}
	}

	return 0;
}
