#ifdef _MSC_VER
#define DEBUG
#define _CRT_SECURE_NO_DEPRECATE
#endif

#include <fstream>
#include <stdio.h>
#define MAX 10000001
using namespace std;

long  num[MAX];
int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

  int p2=1,p3=1;

	num[1]=1;
	for(int i=2;i<MAX;++i)
	{
		num[i]=min(num[p2]*2+1,num[p3]*3+1);
		if(num[i]==(num[p2]*2+1))
			++p2;
		if(num[i]==(num[p3]*3+1))
			++p3;
	}

	int n;
	while(~scanf("%d",&n))
	{
		printf("%ld\n",num[n]);
	}


	return 0;
}
