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
#define MAX 10
using namespace std;

char map[MAX][MAX];

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

  char str[20];
  int r,c;

  while(scanf("%s",str))
  {
    if(!strcmp(str,"ENDOFINPUT"))
      break;
    scanf("%d%d",&r,&c);
    getchar();
		for(int i=0;i<r;++i)
    {
      gets(map[i]);
    }
		for(int i=0;i<r-1;++i)
		{
			for(int j=0;j<c-1;++j)
				printf("%c",(map[i][j]+map[i+1][j]+map[i][j+1]+map[i+1][j+1])/4);
			printf("\n");
		}
		gets(str);
  }

  return 0;
}
