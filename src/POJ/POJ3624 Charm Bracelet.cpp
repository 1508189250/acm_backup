// POJ3624 Charm Bracelet.cpp : Defines the entry point for the console application.
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
	int dp[12900],w[3500],d[3500];
	int n,m;

	scanf("%d %d",&n,&m);
	memset(dp,0,sizeof(dp));
	for(int i=0;i<n;++i)
		scanf("%d %d",&w[i],&d[i]);

	for(int i=0;i<n;++i)
		for(int j=m;j>=w[i];--j)
			dp[j]=max(dp[j],dp[j-w[i]]+d[i]);

	cout<<dp[m]<<endl;


	return 0;
}
