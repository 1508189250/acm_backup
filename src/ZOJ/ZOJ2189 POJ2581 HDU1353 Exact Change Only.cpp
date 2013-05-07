#ifdef _MSC_VER
#define DEBUG
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


int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

	double a;
	int temp,b,c,d,e,i,j,k,m;
	
	while(~scanf("%lf",&a))
	{
		int total=(int)(a*100+0.01);
    scanf("%d%d%d%d",&b,&c,&d,&e);
    bool flag=true;

    for( i=0;i<=e && flag;++i)
      for( j=0;j<=d && flag;++j)
        for( k=0;k<=c && flag;++k)
          for( m=0;m<=b  && flag;++m)
            if(i+j*5+k*10+m*25==total) 
            {
              printf("%d %d %d %d\n",m,k,j,i);
              flag=false;
            }
    if(flag)
      printf("NO EXACT CHANGE\n");

	}

  return 0;
}
