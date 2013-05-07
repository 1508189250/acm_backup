// ZOJ1970 POJ1936 All in All.cpp : Defines the entry point for the console application.
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

int main(void)
{
// 	ifstream cin("data.txt");
	string lhs,rhs;

	while(cin>>lhs>>rhs)
	{
		int alen=lhs.length();
		int pos=0;
// 		char ch;

		for(int i=0;i<alen;++i)
		{
// 			ch = lhs.at(i);
			pos = rhs.find(lhs.at(i),pos);
			if (pos==-1)
			{
				break;
			}
			else
				++pos;
		}

		if(pos == -1)
			printf("No\n");
		else 
			printf("Yes\n");
	}


	return 0;
}
