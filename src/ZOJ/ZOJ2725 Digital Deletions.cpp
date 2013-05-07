/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2012-06-17 10:52
 # Filename: ZOJ2725 Digital Deletions.cpp
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

int num[kMAX];
char str[kMAX];

int GetLen(int var)
{
	int ans=1;
	while(var/10)
	{
		++ans;
		var%=10;
	}
	return ans;
}

void Find(const int &var)
{

}

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

	while(gets(str))
	{
		int len=strlen(str);
		for(int i=0;i<len;++i)
			num[i]=str[i]-'0';
		bool ans=isWin(0,len);
		if(ans)
			printf("Yes\n");
		else
			printf("No\n");
	}
  return 0;
}

