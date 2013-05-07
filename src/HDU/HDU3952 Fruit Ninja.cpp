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
#define MAX 11
#define EPS 1e-10
using namespace std;

// 点的定义
struct POINT{
  int x,y;
};

struct FRUIT
{
  int n;
  POINT point[MAX];
}fruits[MAX];

// 计算向量ac在ab的方向的叉积
double inline crossProduct(const POINT &a,const POINT &b,const POINT &c)	{
  return (c.x - a.x)*(b.y - a.y) - (b.x - a.x)*(c.y - a.y);  
}

bool inline intersect(const POINT  &a,const POINT &b,const POINT &c,const POINT &d)
{
  return crossProduct(c,d,a)*crossProduct(c,d,b)<=0;
}

int func(const POINT &a,const POINT &b,const int &n)
{
  int ans = 0;  
  for(int i=0; i<n; i++)  
  {  
    int len = fruits[i].n;  
    fruits[i].point[len] = fruits[i].point[0];  
    for(int k=0; k<len; k++)  
      if( intersect(fruits[i].point[k], fruits[i].point[k+1], a, b) )  
      {  
        ans++;  
        break;  
      }  
  }  
  return ans;  
}

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

  int ncases,n;
  scanf("%d",&ncases);

  for(int nc=1;nc<=ncases;++nc)
  {
    scanf("%d",&n);
    for(int i=0;i<n;++i)
    {
      scanf("%d",&fruits[i].n);
      for(int j=0;j<fruits[i].n;++j)
        scanf("%d%d",&fruits[i].point[j].x,&fruits[i].point[j].y);
    }

    int ans=1;
    for(int i=0; i<n; i++)  
      for(int k=0; k<fruits[i].n; k++)  
        for(int j=i+1; j<n; j++)  
          for(int l=0; l<fruits[j].n; l++)  
          {  
            int temp = func(fruits[i].point[k], fruits[j].point[l], n);  
            ans=max(temp,ans);
          }  		
          printf("Case %d: %d\n",nc,ans);

  }


  return 0;
}
