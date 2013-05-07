#include "stdafx.h"
#define DEBUG

#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <memory.h>
#include <limits.h>

#include <math.h>
#include <algorithm>
#include <numeric>
#include <functional>
#include <assert.h>
#include <ctype.h>
#include <set>
#include <vector>
using namespace std;

set<string> mset;
vector<string> mvec;


int main(void)
{
#ifdef DEBUG  
	freopen("data.txt","r",stdin);  
#endif  

	string str;

	while(cin>>str)
	{
		mvec.push_back(str);
		mset.insert(str);
	}

	vector<string>::iterator iter;
	for(iter=mvec.begin();iter!=mvec.end();++iter)
	{
		str = *iter;
		int len= str.length();
		for(int i=1;i<len-1;++i)
		{
			if(mset.find(str.substr(0,i)) !=mset.end())
				if(mset.find(str.substr(i,len-1)) != mset.end())
				{
					cout<<str<<endl;
					break;
				}
		}
	}

	return 0;
}
