// POJ1154 LETTERS.cpp : Defines the entry point for the console application.
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

char mat[25][25];
char mark[128];
int r,c,sum;

int dfs(int x,int y)
{
	if(mark[mat[x][y]]) return sum;

	int temp=0;
	mark[mat[x][y]]=1;
	++sum;

	if(x+1<r) temp=max(temp,dfs(x+1,y));
	if(x-1>=0) temp=max(temp,dfs(x-1,y));
	if(y+1<c) temp=max(temp,dfs(x,y+1));
	if(y-1>=0) temp=max(temp,dfs(x,y-1));

	mark[mat[x][y]]=0;
	--sum;
	return temp;
}

int main(void)
{
// 	ifstream cin("data.txt");

	while(cin>>r>>c)
	{
		memset(mark,0,sizeof(mark));
		sum=0;

		for(int i=0;i<r;++i)
			for(int j=0;j<c;++j)
				cin>>mat[i][j];

		cout<<dfs(0,0)<<endl;
	}


	return 0;
}
