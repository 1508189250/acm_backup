/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2012-07-19 18:57
 # Filename: HDU2149 Public Sale.cpp
 # Description : ��һ��n����Ʒ,�����������������Ʒ��ȡ��,�涨ÿ������ȡp��,���ȡq��.���ȡ���ߵ�ʤ.
 n = (m+1)r+s , (rΪ������Ȼ��,s��m), ��n%(p+q) != 0, ����ȡ�߿϶���ʤ(Ĭ�����һ��ȡ��Ϊwin)
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

const int kMAX=10010;
const double kEPS=10E-6;

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

  int n,m;

  while(~scanf("%d%d",&m,&n) )
  {
		int t=m%(1+n);
		if(!t)
			printf("none\n");
		else
			printf("%d\n",t);
  }

  return 0;
}

