// ZOJ2277 The Gate to Freedom.cpp : Defines the entry point for the console application.
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
	double n;
	
	while(cin>>n)
	{
		cout<<(int)pow((double)10,n*log10(n)-(int)(n*log10(n)))<<endl;
// 		cout<<n*log10(n)-(int)n*log10(n)<<endl;
// 		printf("%d\n", ( int )pow( (double)10, n*log10( n ) - (int)( n*log10( n ) ) ) )	;
	}



	return 0;
}
