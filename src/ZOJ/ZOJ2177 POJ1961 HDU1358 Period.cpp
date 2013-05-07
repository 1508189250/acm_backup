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
#define MAX 1000100
using namespace std;

char str[MAX];
int next[MAX];

void get_next(const int &len)
{
	int i=0,j=-1;
	next[0]=-1;
	while(i<len)
		if(j==-1 || str[i]==str[j])
		{
			++i;++j;
			next[i]=j;
		}
		else
			j=next[j];
}

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

	int n,ncases=1;

	while(scanf("%d",&n) && n)
	{
		getchar();
		gets(str);
    get_next(n);
    printf("Test case #%d\n",ncases++);

    int i=1;
    while(i<=n)
		{
			int tmp=i-next[i];
			if(i%tmp==0 && i/tmp!=1)
				printf("%d %d\n",i,i/tmp);
			++i;
		}
		printf("\n");

	}

  return 0;
}
