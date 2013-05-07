/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2012-02-05 17:43
 # Filename: HDU3927 Math Geek.cpp
 # Description : ·´»Ã·½
 ******************************************************************************/
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
#define MAX 210
using namespace std;

int map[MAX][MAX];

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

  int ncases,n;
  scanf("%d",&ncases);

  for(int nc=1;nc<=ncases;++nc)
  {
	  printf("Case #%d:\n",nc);
	  scanf("%d",&n);
	  for(int i=1;i<=n;++i)
		  for(int j=1;j<=n;++j)
			  if(j!=n)
				  printf("%d ",(i-1)*(n-1)+j);
			  else
				  printf("%d\n",n*(n-1)+i);
  }

  return 0;
}
