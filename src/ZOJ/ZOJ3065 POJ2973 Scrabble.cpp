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
#define MAX 1010
using namespace std;

char dict[MAX][10];
int letter[128],array[128];

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

  int n,ncase=1;
	char str[MAX];
  //   scanf("%d",&ncase);

  while(~scanf("%d",&n) && n)
  {
		memset(letter,0,sizeof(letter));
		getchar();
		for(int i=0;i<n;++i)
			gets(dict[i]);

		gets(str);
		int blank=0;
		for(size_t i=0;i<strlen(str);++i)
		{
			if(str[i]!='_')
				++letter[str[i]];
			else
				++blank;
		}

		int ans=0;
		for(int i=0;i<n;++i)
		{
			memcpy(array,letter,sizeof(letter));
			int tmp=0;
			for(size_t j=0;j<strlen(dict[i]);++j)
				if(array[dict[i][j]])
					--array[dict[i][j]];
				else
					++tmp;
			if(tmp<=blank)
				++ans;
		}
		printf("%d\n",ans);

  }

  return 0;
}
