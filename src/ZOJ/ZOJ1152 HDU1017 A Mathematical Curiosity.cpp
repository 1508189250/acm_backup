// #include "stdafx.h"
// #define DEBUG

#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <memory.h>

#include <math.h>
#include <algorithm>
#include <numeric>
#include <functional>
#include <limits>
#include <assert.h>
#include <ctype.h>

#include <vector>
#include <stack>
#include <queue>
#include <deque>

using namespace std;

int main(void)
{
#ifdef DEBUG  
	freopen("data.txt","r",stdin);  
#endif  
	int ncases;
	cin>>ncases;
	int flag=1;
	while(ncases--)
	{
		if(flag)
			flag=0;
		else
			printf("\n");
		int ind=1;
		int n,m;
		while(cin>>n>>m && (n||m))
		{
			int ans=0;
			for(int i=1;i<n;++i)
				for(int j=i+1;j<n;++j)
				{
					if((i*i+j*j+m)%(i*j)==0)
						++ans;
				}
			printf("Case %d: %d\n",ind++,ans);
		}
	}

	return 0;
}
