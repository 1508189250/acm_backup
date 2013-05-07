// HDU1213 How Many Tables.cpp : Defines the entry point for the console application.
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

int pre[1010];

int find(int x)
{
	while(x!=pre[x])
		x=pre[x];
	return x;
}

int main(void)
{
// 	ifstream cin("data.txt");
	int ncases;
	int n,m;
	int a,b;
	int result;

	cin>>ncases;

	while(ncases--)
	{
		result=0;
		cin>>n>>m;
		for(int i=1;i<=n;++i)
			pre[i]=i;

		for(int i=0;i<m;++i)
		{
			cin>>a>>b;
			a=find(a);
			b=find(b);
			if(a!=b)
				pre[a]=b;
		}

		for(int i=1;i<=n;++i)
			if(pre[i]==i)
				++result;

		cout<<result<<endl;
	}


	return 0;
}
