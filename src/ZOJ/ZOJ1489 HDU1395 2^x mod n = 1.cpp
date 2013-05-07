// #include "stdafx.h"
// #define DEBUG

#include <stdio.h>

int main(void)
{
#ifdef DEBUG  
	freopen("data.txt","r",stdin);  
#endif  

	int n,num;
	int flag,x,ans;
	while(~scanf("%d",&n))
	{
		num=2;
		flag=1;
		x=1;
		if(n%2==0 /*|| n==1*/)
		{
			printf("2^? mod %d = 1\n",n);
			continue;
		}

		while(1)
		{
			num = num%n;
			if(num==1)
			{
				printf("2^%d mod %d = 1\n",x,n);
				break;
			}
			else
			{
				++x;
				num*=2;
			}
		}
	}

	return 0;
}
