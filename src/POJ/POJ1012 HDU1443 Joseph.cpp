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

int num[30];

bool func(const int &k,const int &m)
{
  int t=2*k; //������
  int s=0;  //��ʼλ��
  int i=k;  //��������
  while(i--)
  {
    s=(s-1+m)%t;
    t--;
    if(s<k)
      return false;
  }
  return true;
}


int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

	int ans[15];

	for(int i=1;i<15;++i)
	{
		for(int j=1;;++j)
			if(func(i,j))
			{
				ans[i]=j;
				break;
			}
	}

	int n;
	while(scanf("%d",&n) && n)
		printf("%d\n",ans[n]);

  return 0;
}
