// ZOJ2109 FatMouse' Trade.cpp : Defines the entry point for the console application.
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

struct node
{
	int f,j;
	double rate;
}rooms[1010];

bool cmp(const node &lhs,const node &rhs)
{
	return lhs.rate>rhs.rate;
}

int main(void)
{
// 	ifstream cin("data.txt");
	int m,n;

	while(cin>>m>>n && m>-1 &&n>-1)
	{
		for(int i=0;i<n;++i)
		{
			cin>>rooms[i].j>>rooms[i].f;
			rooms[i].rate=rooms[i].j*1.0/rooms[i].f;
		}
		sort(rooms,rooms+n,cmp);

		double sum=0;
		for(int i=0;i<n;++i)
		{
			if(m==0) break;
			else if(m>=rooms[i].f)
			{
				m-=rooms[i].f;
				sum+=rooms[i].j;
			}
			else
			{
				sum+=rooms[i].rate * m; 
				m=0;
				break;
			}
		}
		printf("%0.3f\n",sum);
	}


	return 0;
}

