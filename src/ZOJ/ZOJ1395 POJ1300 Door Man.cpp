/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2012-04-19 20:57
 # Filename: ZOJ1395 POJ1300 Door Man.cpp
 # Description : 
 ******************************************************************************/
#ifdef _MSC_VER
#define DEBUG
#define _CRT_SECURE_NO_DEPRECATE
#endif

#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <limits.h>
#include <algorithm>
#include <math.h>
#include <numeric>
#include <functional>
#include <ctype.h>
#include <sstream>
#define MAX 100010
using namespace std;

int degree[MAX],door;

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

  int beg,n,v;
	string str;
  //   scanf("%d",&ncase);

	while(cin>>str && str!="ENDOFINPUT")
  {

    cin>>beg>>n;
    getchar();
		memset(degree,0,sizeof(degree));
		door=0;
		for(int u=0;u<n;++u)
		{
      getline(cin,str);
			stringstream is(str);
			while(is>>v)
			{
				++door;
				++degree[u];
				++degree[v];
			}
		}
		int odd=0;
		for(int i=0;i<n;++i)
			if(degree[i]%2)
				++odd;
    if(!beg)  //起点与终点0一样，欧拉回路
    {
      if(odd>0)
        cout<<"NO"<<endl;
      else
        cout<<"YES "<<door<<endl;
    }
    else
		{
      if(odd==2 && degree[beg]%2 && degree[0]%2)
        cout<<"YES "<<door<<endl;
      else
        cout<<"NO"<<endl;
    }
		cin>>str;
  }

  return 0;
}
