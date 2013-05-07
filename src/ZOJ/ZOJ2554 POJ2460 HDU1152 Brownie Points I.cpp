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
#define MAX 200010
using namespace std;

struct POINT
{int x,y;}point[MAX];

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  
  int n;

  while(scanf("%d",&n) &&n)
  {
	  for(int i=0;i<n;++i)
		  scanf("%d%d",&point[i].x,&point[i].y);
	  swap(point[0],point[n/2]);

	  POINT &cross=point[0];

	  int sum_a=0,sum_b=0;
	  for(int i=1;i<n;++i)
	  {
		  if(point[i].x>cross.x && point[i].y>cross.y ||
				  point[i].x<cross.x && point[i].y<cross.y)
			  ++sum_a;
		  else if( point[i].x>cross.x && point[i].y<cross.y ||
				  point[i].x<cross.x && point[i].y>cross.y)
			  ++sum_b;
	  }
	  printf("%d %d\n",sum_a,sum_b);
  }

  return 0;
}
