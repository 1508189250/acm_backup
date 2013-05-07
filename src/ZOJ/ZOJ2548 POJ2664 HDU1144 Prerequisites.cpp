#ifdef _MSC_VER
#define DEBUG
#endif

#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
//#include <memory.h>
#include <limits.h>
#include <algorithm>
#include <math.h>
#include <numeric>
#include <functional>
#include <ctype.h>
#define MAX 110
using namespace std;


bool courses[MAX*MAX];

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

	int k,m,c,r;
	int temp;

	while(~scanf("%d",&k)&&k)
	{
		scanf("%d",&m);

		memset(courses,false,sizeof(courses));
		for(int i=0;i<k;++i)
		{
			scanf("%d",&temp);
			courses[temp]=true;
    }
    bool flag=true;
		for(int i=0;i<m;++i)
		{
			scanf("%d%d",&c,&r);
			for(int j=0;j<c;++j)
			{
				scanf("%d",&temp);
				if(courses[temp])
					--r;
			}
      if(r>0)
        flag=false;
		}
		if(flag)
			printf("yes\n");
		else
			printf("no\n");
	}

  return 0;
}
