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
	int s,p,y,j,d=12;
	int sa,pa,ya;
	
	while(~scanf("%d%d%d%d",&s,&p,&y,&j))
	{
		for(sa=0;sa<=j+d;++sa)
			for(pa=0;pa<sa;++pa)
				for(ya=0;ya<pa;++ya)
					if(sa+pa+ya==d+j || sa+pa+ya==d+j+1)
						if(sa-pa==s || sa-pa==s+1)
							if(pa-ya==p || pa-ya==p+1)
								if(sa-ya==y || sa-ya==y+1)
									goto end;
end:
		printf("%d %d %d\n",sa,pa,ya);
	}

  return 0;
}
