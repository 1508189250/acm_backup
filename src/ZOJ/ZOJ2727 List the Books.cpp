// #include "stdafx.h"
// #define DEBUG

#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <memory.h>
#include <algorithm>
#define MAX 105

using namespace std;

struct BOOK
{
	string name;
	int years,price;
}book[MAX];

bool cmp1(const BOOK &lhs,const BOOK &rhs)
{
	if(lhs.name != rhs.name)
		return lhs.name<rhs.name;
	else if(lhs.years !=rhs.years)
		return lhs.years<rhs.years;
	else
		return lhs.price<rhs.price;
}
bool cmp2(const BOOK &lhs,const BOOK &rhs)
{
	if(lhs.years !=rhs.years)
		return lhs.years<rhs.years;
	else if(lhs.name != rhs.name)
		return lhs.name<rhs.name;
	else
		return lhs.price<rhs.price;
}
bool cmp3(const BOOK &lhs,const BOOK &rhs)
{
	if(lhs.price!=rhs.price)
		return lhs.price<rhs.price;
	if(lhs.name != rhs.name)
		return lhs.name<rhs.name;
	else 
		return lhs.years<rhs.years;
}

int main(void)
{
#ifdef DEBUG  
	freopen("data.txt","r",stdin);  
#endif  
	int n;
	string criteria;
	int flag=1;
	while(scanf("%d",&n)&&n)
	{
		for(int i=0;i<n;++i)
			cin>>book[i].name>>book[i].years>>book[i].price;
		cin>>criteria;
		if(criteria.at(0)=='N')
			sort(book,book+n,cmp1);
		else if(criteria.at(0)=='Y')
			sort(book,book+n,cmp2);
		else
			sort(book,book+n,cmp3);
		if(flag)
			flag=0;
		else
			printf("\n");
		for(int i=0;i<n;++i)
			cout<<book[i].name<<' '<<book[i].years<<' '<<book[i].price<<endl;
	}

	return 0;
}
