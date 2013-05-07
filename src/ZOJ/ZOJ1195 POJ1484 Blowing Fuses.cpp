// ZOJ1195 POJ1484 Blowing Fuses.cpp : Defines the entry point for the console application.
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

using namespace std;

int main(void)
{
// 	ifstream cin("data.txt");
	int ncases(1);
	int n,m,c;
	int temp;
	int consumption[25];
	int state[25];
	while(cin>>n>>m>>c && n && m && c)
	{
		int max(0);
		int run(0);
		memset(consumption,0,sizeof(consumption));
		memset(state,0,sizeof(state));
		for(int i=1;i<=n;++i)
		{
			cin>>consumption[i];
		}
		for(int i=0;i<m;++i)
		{
			cin>>temp;
			if(state[temp])
			{
				run -=consumption[temp];
				state[temp]=0;
			}
			else
			{
				run +=consumption[temp];
				state[temp]=1;
				if(run>max)
					max=run;
			}
		}

		if(max>c)
			printf("Sequence %d\nFuse was blown.\n\n",ncases);
		else
			printf("Sequence %d\nFuse was not blown.\nMaximal power consumption was %d amperes.\n\n",ncases,max);
		++ncases;

	}


	return 0;
}
