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

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

	char str[5001];

	while(gets(str))
	{
		int len=strlen(str);
		int ans=0;
		for(int i=0;i<len;++i)
		{
			int beg=i,end=i;
			while(str[beg]==str[end] && beg>=0 && end<len)
      {
        --beg;
        ++end;
				++ans;
      }

			beg=i,end=i+1;
			while(str[beg]==str[end] && beg>=0 && end<len)
      {
        --beg;
        ++end;
				++ans;
      }

		}
		printf("%d\n",ans);
	}

  return 0;
}
