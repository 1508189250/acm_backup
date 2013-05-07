/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2012-03-26 19:28
 # Filename: POJ1189 HDU271 The Cow Lineup.cpp
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
#define MAX 100010
using namespace std;

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

  int n,m,tmp;
	bool num[MAX];

  while(~scanf("%d%d",&n,&m) )
  {
		int ans=1,cnt=0;
    memset(num,false,sizeof(num));
    while(n--)
		{
			scanf("%d",&tmp);
			if(!num[tmp])
			{
				num[tmp]=true;
				++cnt;
				if(cnt==m)
				{
					cnt=0;
					memset(num,false,sizeof(num));
					++ans;
				}
			}
		}
		printf("%d\n",ans);
  }

  return 0;
}
