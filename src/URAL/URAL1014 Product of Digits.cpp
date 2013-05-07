/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2012-06-13 16:07
 # Filename: acm.cpp
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
using namespace std;

const int kMAX=10010;
const double kEPS=10E-6;

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

  __int64	n;
  
  while(cin>>n)
  {
	  if(!n)
			cout<<10<<endl;
	  else if(n<10)
		  cout<<n<<endl;
	  else
	  {
			string s;
			bool flag=true;
		  while(n>1)
		  {
				int i;
				for(i=9;i>1;--i)
					if(n%i==0)
					{
						s+=('0'+i);
						n/=i;
						break;
					}

				if(i==1)
				{
					flag=false;
					break;
				}
		  }

			if(flag)
			{
				reverse(s.begin(),s.end());
				cout<<s<<endl;
			}
			else
				cout<<-1<<endl;
	  }
  }

  return 0;
}

