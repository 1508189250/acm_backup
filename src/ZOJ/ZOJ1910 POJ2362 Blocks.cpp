// #include "stdafx.h"
// #define DEBUG

#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <memory.h>
#include <limits.h>

using namespace std;

int main(void)
{
#ifdef DEBUG  
	freopen("data.txt","r",stdin);  
#endif  

	int ncases;
	int n;
	scanf("%d",&ncases);
	while(ncases--)
	{
		scanf("%d",&n);
		int min=INT_MAX;
		for(int a=1;a<=n;++a)
			if(n%a==0)
				for(int b=1;a*b<=n;++b)
					if(n%(a*b)==0)
					{
						int c=n/(a*b);
						if(min>a*b+b*c+a*c)
							min=a*b+b*c+a*c;
					}
		printf("%d\n",min*2);
	}

	return 0;
}
