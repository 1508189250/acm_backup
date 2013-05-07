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

bool dfs(const int &sum)//是否必败点
{
	if(sum>=31)
		return true;//如果到达本节点时sum大于等于31，则此时加任何数字都是输的，可知本节点是必败点

	for(int i=1;i<=6;++i)
		if(num[i] && sum+i<=31)
		{
			--num[i];
			if(dfs(sum+i))//找到一个后续节点是必败点，则本节点是必胜点
			{
				++num[i];
				return false;
			}
			++num[i];
		}
	return true;//找不到任何后续节点是必败点，则本节点也是比败点
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

