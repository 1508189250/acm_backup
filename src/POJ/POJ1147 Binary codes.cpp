/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2012-03-07 19:24
 # Filename: POJ1147 Binary codes.cpp
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
#define MAX 3001
using namespace std;

int input[MAX],tmp[MAX],next[MAX];
bool used[MAX];

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

	int n;

	while(~scanf("%d",&n) && n)
	{
		int cnt=0;
		memset(used,false,sizeof(used));
		memset(tmp,0,sizeof(tmp));
		for(int i=0;i<n;++i)
		{
			scanf("%d",&input[i]);
			if(input[i])
				++cnt;
		}
		for(int i=n-cnt;i<n;++i)
			tmp[i]=1;

		for(int i=0;i<n;++i)
		{
			int j=0;
			while(tmp[i]!=input[j] || used[j])
				++j;
			used[j]=true;
			next[i]=j;
		}

		int ind=0;
		for(int i=0;i<n;++i)
		{
			ind=next[ind];
      printf("%d%c",input[ind],i==(n-1)?'\n':' ');
		}

	}


  return 0;
}
