/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2012-06-21 17:50
 # Filename: ZOJ1827 HDU4155 The Game of 31.cpp
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

const int kMAX=10010;
const double kEPS=10E-6;
int num[7];

bool dfs(const int &sum)//�Ƿ�ذܵ�
{
	if(sum>=31)
		return true;//������ﱾ�ڵ�ʱsum���ڵ���31�����ʱ���κ����ֶ�����ģ���֪���ڵ��Ǳذܵ�

	for(int i=1;i<=6;++i)
		if(num[i] && sum+i<=31)
		{
			--num[i];
			if(dfs(sum+i))//�ҵ�һ�������ڵ��Ǳذܵ㣬�򱾽ڵ��Ǳ�ʤ��
			{
				++num[i];
				return false;
			}
			++num[i];
		}
	return true;//�Ҳ����κκ����ڵ��Ǳذܵ㣬�򱾽ڵ�Ҳ�ǱȰܵ�
}

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

  int n;
	char str[kMAX];

  while(~scanf("%s",str))
  {
		int len=strlen(str);
		for(int i=1;i<=6;++i)
			num[i]=4;

		int sum=0;
		for(size_t i=0;i<len;++i)
		{
			--num[str[i]-'0'];
			sum+=str[i]-'0';
		}
		printf("%s ",str);

		if(dfs(sum))
		{
			if(len&1)
				printf("A\n");
			else
				printf("B\n");
		}
    else
    {
      if(len&1)
        printf("B\n");
      else
        printf("A\n");
    }

  }

  return 0;
}

