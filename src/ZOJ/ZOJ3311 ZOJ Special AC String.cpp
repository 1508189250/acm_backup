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

  int n,ncase=1;
	char str[128];
  //   scanf("%d",&ncase);

	while(gets(str))
  {
		int len=strlen(str);
		int z_count=0,j_count=0,z_idx,j_idx;
		for(int i=0;i<len;++i)
		{
			if(str[i]=='J')
			{
				j_count++;
				j_idx=i;
			}
			else if(str[i]=='Z')
			{
				z_count++;
				z_idx=i;
			}
		}
		if((z_count!=1 || j_count!=1) || (j_idx-z_idx<2))
		{
			printf("Wrong Answer\n");
			continue;
		}
		int mid=j_idx-z_idx-1;
		int last=len-j_idx-1;
		if(mid>last)
		{
			printf("Wrong Answer\n");
			continue;
		}
		printf("Accepted\n");
  }

  return 0;
}
