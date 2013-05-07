/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2012-06-03 17:03
 # Filename: URAL1297 POJ2974 Palindrome.cpp
 # Description : �������������array������Ҫ��֤��������Ҫ���һ��0�����Ȼ�Ҫ��1, ��������CalculateHeight��������height
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

const int kMAXN=2000010;

int w[kMAXN],wa[kMAXN],wb[kMAXN],wv[kMAXN],array[kMAXN],sa[kMAXN];

// 
int cmp(const int *r,const int &a,const int &b,const int &l){
  return r[a]==r[b]&&r[a+l]==r[b+l];
}

// �����㷨
// rΪ���Ƚ����飻nΪr�ĳ��ȣ�mΪr��Ԫ�ص����ֵ 
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

// ����height���飬r��sa�Ķ���ͬ�ϣ�
// height���±��1��ʼ����n����������n��
int g_rank[kMAXN],height[kMAXN];
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

	char str[kMAXN];
	int array[kMAXN],ncases=1;

	while(gets(str))
  {
		if(!strcmp(str,"END"))
			break;
		int len=strlen(str);
		for(int i=0;i<len;++i)
			array[i]=str[i];
		int n=len;
		array[n++]='$';
		for(int i=len-1;i>=0;--i)
			array[n++]=str[i];
		array[n++]=0;

		DoublingAlgorithm(array,sa,n,128);
		CalculateHeight(array,sa,n-1);

		int max_height=0,idx=0;
		for(int i=1;i<n;++i)
		{
			if(height[i]>max_height)
			{
				max_height=height[i];
				idx=sa[i];
			}
      if(height[i]==max_height)
        idx=min(idx,sa[i]);
		}
// 		for(int i=idx;i<idx+max_height;++i)
// 			printf("%c",array[i]);
// 		printf("\n");
    printf("Case %d: %d\n",ncases++,max_height);
  }

  return 0;
}
