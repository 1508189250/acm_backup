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

const int kMAX=5000010;
const double kEPS=10E-6;

int factor_count_array[kMAX];
int array[kMAX];

void getsg()//难理解的地方
{
  int i,j;
  for(i=2;i<kMAX;i++)
  {
    if(!factor_count_array[i])
    {
      for(j=i*2;j<kMAX;j+=i)// 帅选出素数，且标记非素数为最大质因子
        factor_count_array[j]=i;
    }
  }
  factor_count_array[1]=0;
  for(i=2;i<kMAX;i++)
  {
    if(!factor_count_array[i]) factor_count_array[i]=1;
    else
    {
      factor_count_array[i]=factor_count_array[i/factor_count_array[i]]+1; //这里dp的思想
    }
  }

}

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

  int n,ncase,tmp=1;
//   scanf("%d",&ncase);
	memset(factor_count_array,0,sizeof(factor_count_array));
  getsg();

  int nc=1;
  while(~scanf("%d",&n) )
  {
		printf("Test #%d: ",nc++);
		;
		int remain=0;
		for(int i=0;i<n;++i)
		{
			scanf("%d",&tmp);
			array[i]=factor_count_array[tmp];
			remain^=array[i];
		}
		if(remain)
		{
			for(int i=0;i<n;++i)
			{
				int x=remain^array[i];
				if(x<array[i])
        {
            printf("Alice %d\n",i+1);
            break;
        }

			}
		}
		else
			printf("Bob\n");
  }

  return 0;
}

