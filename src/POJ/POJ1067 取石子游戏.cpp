#ifdef _MSC_VER
#define DEBUG
#define _CRT_SECURE_NO_DEPRECATE
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
#define MAX 100010
using namespace std;

bool NIM(int x,int y)
{
	if(!x && !y)
		return false;
	if(x==y)
		return true;

	if(x>y)
		swap(x,y);

	double a=(1+sqrt(5.0))/2;
	if(x==(int)((y-x)*a))
		return false;
	else
		return true;
}

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

	int x,y;
	while(~scanf("%d%d",&x,&y))
		if(NIM(x,y))
			printf("1\n");
		else
			printf("0\n");

  return 0;
}
