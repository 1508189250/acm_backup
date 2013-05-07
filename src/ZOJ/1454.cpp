// 1454.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <fstream>


#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int max3(const int &a,const int &b,const int &c)
{
	int res=a;
	if(res <b) res=b;
	if(res <c) res=c;
	return res;
}


int min3(const int &a,const int &b,const int &c)
{
	int res=a;
	if(res >b) res=b;
	if(res >c) res=c;
	return res;
}

double calculate(const pair<int,int> &a, const pair<int,int> &b, const pair<int,int> &c)
{
	double result;
	int x,y;
	x = max3(a.first,b.first,c.first) - min3(a.first,b.first,c.first);
	y = max3(a.second,b.second,c.second) - min3(a.second,b.second,c.second);

	result = (long)x * (long)y /2;
	return result;
}

bool fn(const pair<int,int> &lhs,const pair<int,int> &rhs)
{ 
	if(lhs.first < rhs.first) return true;
	else return false;
}

int main(int argc, char* argv[])
{
	vector< pair<int,int> > pairVec;
	int x,y,count;
	double result(0.0);

	ifstream cin("data.txt");

	cin>>count;
	for(int i=0; i<count;++i)
	{
		cin>>x>>y;
		pairVec.push_back(make_pair(x,y));
	}

	sort(pairVec.begin(),pairVec.end(),fn);


	vector< pair<int,int> >::iterator pos=pairVec.begin();
	vector< pair<int,int> >::iterator next = pos+2;

	for (;next != pairVec.end();++pos,++next)
	{
		result += calculate(*pos,*(pos+1),*next);
	}

	cout<<result<<endl;
	cin.close();
	return 0;
}


