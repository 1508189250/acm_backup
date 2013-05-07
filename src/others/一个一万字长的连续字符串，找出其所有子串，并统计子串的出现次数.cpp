/*
 * =====================================================================================
 *
 *       Filename:  acm.cpp
 *
 *    Description:  一个一万字长的连续字符串，找出其所有子串，并统计子串的出现次数
 *
 *        Version:  1.0
 *        Created:  2013/5/6 22:07:22
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (Neo), neosfung@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */


#ifdef _MSC_VER
#define _CRT_SECURE_NO_DEPRECATE
#endif

#include "stdafx.h"

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

int w[kMAXN],wa[kMAXN],wb[kMAXN],wv[kMAXN],array[kMAXN],sa[kMAXN];
char str[kMAXN];

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

int _tmain(int argc, _TCHAR* argv[])
{
#ifdef DEBUG  
	freopen("../stdin.txt","r",stdin);
	freopen("../stdout.txt","w",stdout); 
#endif  

	strcpy(str,"aba");

	int n=strlen(str);
	for(int i=0;i<n;++i)
		array[i]=str[i];
	array[n++]=0;
	DoublingAlgorithm(array,sa,n,128);
	CalculateHeight(array,sa,n-1);

	long long ans=0ll;
	for(int i=1;i<n;++i){
		int tmp=n-1-sa[i]-height[i];
		ans+=tmp;
		for (int j=n-1;j>sa[i]+height[i];--j)
		{
			for(int k=sa[i];k<j;++k)
				putchar(str[k]);
			puts("");
		}
	}

	printf("\ntotal: %lld\n",ans);

	return 0;
}
