/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2012-01-03 19:03
 # Filename: ZOJ2311 POJ2121 Inglish-Number Translator.cpp
 # Description : 
 ******************************************************************************/
// #include "stdafx.h"
// #define DEBUG

#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <memory.h>
#include <limits.h>
#include <algorithm>
#include <math.h>
#include <numeric>
#include <functional>
#include <ctype.h>
#include <map>
#include <sstream>
using namespace std;

string str2num[]={"zero", "one", "two", "three", "four", "five", "six", "seven", "eight","nine", "ten", "eleven", "twelve", 
"thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety","hundred", "thousand", "million"};

int num2str[]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,30,40,50,60,70,80,90,100,1000,1000000};

int main(void)
{
#ifdef DEBUG  
  freopen("C:/Users/neo/Desktop/stdin.txt","r",stdin);
  freopen("C:/Users/neo/Desktop/stdout.txt","w",stdout); 
#endif  

  map<string,int> sn_map;
  for(int i=0;i<31;++i)
    sn_map.insert(make_pair(str2num[i],num2str[i]));

	string str,line;

	while(getline(cin,line))
	{
    if(line.length()==0)
      break;
    istringstream ss(line);
    bool b_negative=false;
    long long ans=0;
    long long pre=0;

    while(ss>>str)
    {
      if(str=="negative")
        b_negative=true;
      else if(str=="hundred")
      {
        pre*=100;
      }
      else if(str=="thousand")
      {
        pre*=1000;
        ans+=pre;
        pre=0;
      }
      else if(str=="million")
      {
        pre*=1000000;
        ans+=pre;
        pre=0;
      }
      else
      {
        pre+=sn_map[str];
      }
    }
    ans+=pre;
    if(b_negative)
      ans*=-1;
    printf("%lld\n",ans);
	}

  return 0;
}
