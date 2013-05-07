// #include "stdafx.h"
// #define DEBUG

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

#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
using namespace std;

int main(void)
{
#ifdef DEBUG  
	freopen("data.txt","r",stdin);  
#endif  
	string plain,subs,text;
	getline(cin,plain);
	getline(cin,subs);
	cout<<subs<<endl;
	cout<<plain<<endl;
	while(getline(cin,text) && text.length())
	{
		int len=text.length();
		for(int i=0;i<len;++i)
		{
			int pos=plain.find(text.at(i));
			if(pos!=-1)
				text.at(i) = subs.at(pos);
		}
		cout<<text<<endl;
	}

	return 0;
}
