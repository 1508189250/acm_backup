/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2012-04-07 20:29
 # Filename: ZOJ1003 Crashing Balloon.cpp
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
#define MAX 101
using namespace std;

int flag1,flag2;  
void dfs(int x,int y,int n)  
{  
  if(y==1)  
  {   
    flag2=1;  
    if(x==1)flag1=1; //先分解较小数，所以较大数被分解（就是flag1置1）的条件是较小数已经被分解  
  }  
  if(n>100 || flag1==1 && flag2==1) return;//递归出口：n超过100，或者两个数都被分解  
  if(x%n==0) dfs(x/n,y,n+1);  //大的数用因子n
  if(y%n==0) dfs(x,y/n,n+1);  //小的数用因子n
  dfs(x,y,n+1);               //都不用因子n
}  

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

  int a,b,t;  
  while(~scanf("%d%d",&a,&b))  
  {  
    if(a<b){t=a;a=b;b=t;} //确保a>b  
    flag1=flag2=0;  
    dfs(a,b,2);           //从2开始搜索  
    //printf("%d %d/n",flag1,flag2);  
    if(flag2&&!flag1)printf("%d\n",b);//挑战成功只有一种情况，就是较小数分解成功，大数失败  
    else printf("%d\n",a);  
  }  
  return 0; 
}
