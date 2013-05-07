#include "stdafx.h"
#define DEBUG

#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <memory.h>
#include <limits.h>
#include <algorithm>
#include <math.h>
#include <numeric>
#include <functional>
#include <ctype.h>

using namespace std;

int main(void)
{
#ifdef DEBUG  
  freopen("C:/Users/neo/Desktop/stdin.txt","r",stdin);
  freopen("C:/Users/neo/Desktop/stdout.txt","w",stdout); 
#endif  
	char str[10010];
	int n;
  scanf("%d",&n);
  getchar();
	while(n--)
	{
		gets(str);
		int len=strlen(str);
		int cnt=1;
		for(int i=1;i<len;++i)
		{
			if(str[i]==str[i-1])
				++cnt;
			else
			{
				if(cnt==1)
					printf("%c",str[i-1]);
				else
					printf("%d%c",cnt,str[i-1]);
				cnt=1;
			}
    }
    if(cnt==1)
      printf("%c",str[len-1]);
    else
      printf("%d%c",cnt,str[len-1]);
    cnt=1;
		printf("\n");
	}

  return 0;
}
