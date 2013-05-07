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
#define MAX 5010
using namespace std;

int num[MAX];

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  
  int n;

  while(~scanf("%d",&n))
  {
	  for(int i=0;i<n;++i)
		  scanf("%d",&num[i]);

	  int sum=0;
	  for(int i=0;i<n;++i)
		  for(int j=i+1;j<n;++j)
			  sum+=(num[i]>num[j]);

	  int min_sum=sum;
	  for(int i=0;i<n;++i)
	  {
		  for(int j=0;j<n;++j)
			  if(i==j)
				  continue;
			  else if(num[i]<num[j])
				  ++sum;
			  else if(num[i]>num[j])
				  --sum;
		  min_sum=min(min_sum,sum);
	  }
	  printf("%d\n",min_sum);
  }

  return 0;
}
