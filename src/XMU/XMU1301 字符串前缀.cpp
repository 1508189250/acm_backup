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

const int kMAX=200100;
const double kEPS=10E-6;

int w[kMAX],wa[kMAX],wb[kMAX],wv[kMAX],array[kMAX],sa[kMAX];

// 
int cmp(const int *r,const int &a,const int &b,const int &l){
  return r[a]==r[b]&&r[a+l]==r[b+l];
}

// 倍增算法
// r为待比较数组；n为r的长度；m为r中元素的最大值 
void DoublingAlgorithm(const int *r,int *sa,const int &n,int m){
  int i,j,p,*x=wa,*y=wb,*t;
  for (i=0;i<m;i++) w[i]=0;
  for (i=0;i<n;i++) w[x[i]=r[i]]++;
  for (i=1;i<m;i++) w[i]+=w[i-1];
  for (i=n-1;i>=0;i--) sa[--w[x[i]]]=i;
  for (p=1,j=1;p<n;j*=2,m=p){
    for (p=0,i=n-j;i<n;i++) y[p++]=i;
    for (i=0;i<n;i++) if (sa[i]>=j) y[p++]=sa[i]-j;
    for (i=0;i<m;i++) w[i]=0;
    for (i=0;i<n;i++) w[wv[i]=x[y[i]]]++;
    for (i=1;i<m;i++) w[i]+=w[i-1];
    for (i=n-1;i>=0;i--) sa[--w[wv[i]]]=y[i];
    for (t=x,x=y,y=t,p=1,i=1,x[sa[0]]=0;i<n;i++)
      x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;
  }
  return;
}

// 计算height数组，r和sa的定义同上；
// height的下标从1开始，到n结束，包含n；
int g_rank[kMAX],height[kMAX];
void CalculateHeight(const int *r,int *sa,const int &n){
  int i,j,k=0;
  for (i=1;i<=n;i++) g_rank[sa[i]]=i;
  for (i=0;i<n;height[g_rank[i++]]=k)
    for (k?k--:0,j=sa[g_rank[i]-1];r[i+k]==r[j+k];k++);
  return;
}


int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

  int n,ncase=1;
  scanf("%d",&ncase);
  char str[kMAX];

  getchar();
  while(ncase--)
  {
    gets(str);
		int n=strlen(str);
		for(int i=0;i<n;++i)
			array[i]=str[i];
		array[n++]=0;
    DoublingAlgorithm(array,sa,n,256);
		CalculateHeight(array,sa,n-1);
    int cnt=n-1,min_len=kMAX;
		for(int i=g_rank[0];i>=0 && height[i]>0;--i)
		{
      min_len=min(min_len,height[i]);
			cnt+=min_len;
			cnt %=1000000007;
		}
    min_len=kMAX;
    for(int i=g_rank[0]+1;i<n && height[i]>0;++i)
    {
      min_len=min(min_len,height[i]);
      cnt+=height[i];
      cnt %=1000000007;
    }

		printf("%d\n",cnt);
  }

  return 0;
}