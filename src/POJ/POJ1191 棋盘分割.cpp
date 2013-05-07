#include "stdafx.h"
#define DEBUG

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
using namespace std;

int sum[9][9],dp[15][9][9][9][9];

int inline sum_mat(const int &x1,const int &y1,const int &x2,const int &y2)
{
  return sum[x2][y2]-sum[x2][y1-1]-sum[x1-1][y2]+sum[x1-1][y1-1];
}

int func(const int &n,const int &x1,const int &y1,const int &x2,const int &y2)
{
  if(dp[n][x1][y1][x2][y2]!=-1)
    return dp[n][x1][y1][x2][y2];
  if(n==0)
  {
    int t=sum_mat(x1,y1,x2,y2);
//     t*=t;
    dp[n][x1][y1][x2][y2]=t*t;
    return t*t;
  }
  int min_sum=10000000;
  for(int a=x1;a<x2;++a)
  {
    int c=sum_mat(a+1,y1,x2,y2);
    int e=sum_mat(x1,y1,a,y2);
    int t=min(func(n-1,x1,y1,a,y2)+c*c,e*e+func(n-1,a+1,y1,x2,y2));
    if(min_sum>t) min_sum=t;
  }

  for(int b=y1;b<y2;++b)
  {
    int c=sum_mat(x1,b+1,x2,y2);
    int e=sum_mat(x1,y1,x2,b);
    int t = min(func(n-1,x1,y1,x2,b)+c*c,e*e+func(n-1,x1,b+1,x2,y2));
    if(min_sum>t) min_sum=t;
  }
  dp[n][x1][y1][x2][y2]=min_sum;
  return min_sum;
}

int main(void)
{
#ifdef DEBUG  
  freopen("C:/Users/neo/Desktop/stdin.txt","r",stdin);
  freopen("C:/Users/neo/Desktop/stdout.txt","w",stdout); 
#endif  

  int n,s,temp;

  scanf("%d",&n);
  for(int i=0;i<9;++i)
    sum[i][0]=sum[0][i]=0;
  for(int i=1;i<9;++i)
    for(int j=1,s=0;j<9;++j)
    {
      scanf("%d",&temp);
      s+=temp;
      sum[i][j]=sum[i-1][j]+s;
    }
    s = sum[8][8]*sum[8][8];
    memset(dp,-1,sizeof(dp));
    temp=func(n-1,1,1,8,8);
    temp*=n;
    temp-=s;
    double ans=double(temp)/double(n*n);
    printf("%.3lf\n",sqrt(ans));

    return 0;
}
