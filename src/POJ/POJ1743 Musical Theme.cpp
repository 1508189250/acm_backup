/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2012-06-01 10:49
 # Filename: POJ1743 Musical Theme.cpp
 # Description :  http://poj.org/problem?id=1743
 二分检索答案
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

const int kMAXN=20010;

int w[kMAXN],wa[kMAXN],wb[kMAXN],wv[kMAXN],a[kMAXN],x[kMAXN],sa[kMAXN];

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
int rank[kMAXN],height[kMAXN];
void CalculateHeight(const int *r,int *sa,const int &n){
  int i,j,k=0;
  for (i=1;i<=n;i++) rank[sa[i]]=i;
  for (i=0;i<n;height[rank[i++]]=k)
    for (k?k--:0,j=sa[rank[i]-1];r[i+k]==r[j+k];k++);
  return;
}

bool Check(const int &k,const int &n)
{
	int max_sa=0,min_sa=kMAXN;
	for(int i=1;i<=n;++i)
  {
		if(height[i]<k)
		{
			max_sa=min_sa=sa[i];
		}
		else
		{
			max_sa=max(max_sa,sa[i]);
			min_sa=min(min_sa,sa[i]);
			if(max_sa-min_sa>=k)
				return true;
		}
  }
	  return false;
}

// 二分检索，l是左起点坐标，r是右起点坐标（包含r）
int BinSearch(int l,int r,const int &n)
{
  while(l+1<r){
    int mid=(l+r)>>1;
    if (Check(mid,n)) 
      l=mid; 
    else 
      r=mid;
  }
  return l;
}

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

  int n,array[kMAXN],r[kMAXN];

  while(~scanf("%d",&n) && n)
  {
		for(int i=0;i<n;++i)
			scanf("%d",&array[i]);
    for (int i=1;i<n;i++) r[i-1]=array[i]-array[i-1]+100;
    r[n-1]=0;

    DoublingAlgorithm(r,sa,n,201);
    CalculateHeight(r,sa,n-1);
    int ans=BinSearch(0,(n)/2,n-1)+1;
    if(ans<5)
      ans=0;
    printf("%d\n",ans);

  }

  return 0;
}
