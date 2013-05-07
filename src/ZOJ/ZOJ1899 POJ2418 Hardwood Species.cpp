// ZOJ1899 POJ2418 Hardwood Species.cpp : Defines the entry point for the console application.
//

// #include "stdafx.h"



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

#include <map>
#include <stack>
#include <queue>
#include <deque>

#define DEBUG 0

using namespace std;

int main(void)
{
#if DEBUG   
    freopen("data.txt","r",stdin);  
#endif 
		int sum=0;
		string str;
		map<string,int> mymap;
		map<string , int >::iterator iter;

		while(getline(cin,str))
		{
			if(str.size())
			{
				iter=mymap.find(str);
				if(iter!=mymap.end())
					++(iter->second);
				else
					mymap.insert(make_pair(str,1));
				++sum;
			}
            else
            {		
                for(iter=mymap.begin();iter!=mymap.end();++iter)
                    printf("%s %0.4f\n",(iter->first).c_str(),(double)(iter->second)*100/sum);

                printf("\n");
								sum=0;
								mymap.clear();
            }
		}

		for(iter=mymap.begin();iter!=mymap.end();++iter)
			printf("%s %0.4f\n",(iter->first).c_str(),(double)(iter->second)*100/sum);
		sum=0;
		mymap.clear();

    return 0;
}


