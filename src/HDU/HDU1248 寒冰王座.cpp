// HDU1248 º®±ùÍõ×ù.cpp : Defines the entry point for the console application.
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
	int ncases;
	int n;
	int dp[10010];
	int val[]={150,200,350};
	cin>>ncases;
	while(ncases--)
	{
		cin>>n;
		memset(dp,0,sizeof(dp));
		for(int i=0;i<3;++i)
		{
			for(int j=val[i];j<=n;++j)
			{
				dp[j]=max(dp[j],dp[j-val[i]]+val[i]);
			}
		}
		cout<<n-dp[n]<<endl;
	}


	return 0;
}
