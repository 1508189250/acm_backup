/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2011-12-07 20:45
 # Filename: URAL1225 Flags.cpp
 # Description : 
 ******************************************************************************/
// #include "stdafx.h"
// #define DEBUG

#include <fstream>
#include <stdio.h>
#define MAX 50
using namespace std;

int main(void)
{
#ifdef DEBUG  
  freopen("C:/Users/neo/Desktop/stdin.txt","r",stdin);
  freopen("C:/Users/neo/Desktop/stdout.txt","w",stdout); 
#endif  
  long long num[MAX];
  num[1]=num[2]=2ll;
  for (int i=3;i<MAX;++i)
    num[i]=num[i-1]+num[i-2];
	int n;
	scanf("%d",&n);
	printf("%lld\n",num[n]);

  return 0;
}
