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
 int t,n,m,k,a[15][15];
    int i,j,sum;
    scanf("%d",&t);
    while(t--)
    {
      sum=0;
      scanf("%d%d%d",&n,&m,&k);
      for(i=0;i<n;i++)
        for(j=0;j<m;j++)
          a[i][j]=1;
      for(i=1;i<n-1;i++)
        for(j=1;j<m-1;j++)
        {
          if(sum==k)
            break;
          else
          {
            a[i][j]=0;//中心
            a[i-1][j]=0;//上
            a[i+1][j]=0;//下
            a[i][j-1]=0;//左
            a[i][j+1]=0;//右
            sum++;
          }
        }
        for(i=0;i<n;i++)
        {
          for(j=0;j<m;j++)
            if(j==0)
              printf("%d",a[i][j]);
            else
              printf(" %d",a[i][j]);
          printf("\n");
        }
    }
    return 0;
  }