/*******************************************************************************
 * Author : Neo Fung
 * Email : neosfung@gmail.com
 * Last modified : 2011-08-28 19:21
 * Filename : ZOJ1204 Additive equations.cpp
 * Description : 
 * *****************************************************************************/
// ZOJ1204 Additive equations.cpp : Defines the entry point for the console application.
//

// #include "stdafx.h"



#include <fstream>
#include <stdio.h>
#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

typedef set<int,less<int> > ELEM;

//setÅÅÐòµÄ·Âº¯Êý
class comp
{
public:
	comp ()
	{}
	bool operator() (const ELEM &lhs,const ELEM &rhs) const
	{
		if(lhs.size() !=rhs.size()) return lhs.size()<rhs.size();
		else
			return lhs<rhs;
// 		{
// 			ELEM::const_iterator iter1,iter2;
// 			for(iter1=lhs.begin(),iter2=rhs.begin();iter1!=lhs.end();++iter1,++iter2)
// 				if(*iter1 != *iter2)
// 					return *iter1<*iter2;
// 			return false;
// 		}
	}
};

typedef set< ELEM,comp > RESULT_TYPE;


int num[40];
RESULT_TYPE result;
int m;

void dfs(int index,int end,int remain,ELEM &myelem)
{
	if(num[index]==-1)
		return;
	else if(remain == num[index] )
	{
		myelem.insert(num[index]);
		result.insert(myelem);
		myelem.erase(num[index]);
		return;
	}
	else if(remain>num[index])
	{
		myelem.insert(num[index]);
		int temp=num[index];
		num[index]=-1;
		for(int i=index+1;i<end;++i)
			dfs(i,end,remain-temp,myelem);
		num[index]=temp;
		myelem.erase(temp);
		return;
	}
}

int main(void)
{
	int ncases;
	scanf("%d",&ncases);

	while(ncases--)
	{
		result.clear();
		ELEM myelem;
		scanf("%d",&m);

		for(int i=0;i<m;++i)
			scanf("%d",&num[i]);

		sort(num,num+m);

		for(int i=0;i<m;++i)
		{
			for(int j=0;j<i;++j)
				dfs(j,i,num[i],myelem);
		}

		if (result.empty())
		{
			cout<<"Can't find any equations."<<endl;
		}

		for(RESULT_TYPE::const_iterator iter1=result.begin();iter1 !=result.end();++iter1)
		{
			int sum=0;
			int flag=1;
			for(ELEM::const_iterator iter2=iter1->begin();iter2!=iter1->end();++iter2)
			{
				if(flag)
					flag=0;
				else
					printf("+");
				printf("%d",*iter2);
				sum+=*iter2;
			}
			printf("=%d\n",sum);
		}
		printf("\n");
	}

	return 0;
}
