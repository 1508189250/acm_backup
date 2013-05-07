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

	double speed;
	int weight,strength;
	while(scanf("%lf%d%d",&speed,&weight,&strength)&&(speed||weight||strength))
	{
		bool flag = false;
		if(speed<=4.5 && weight>=150 && strength>=200)
		{
			flag=true;
			printf("Wide Receiver");
		}
		if(speed<=6.0 && weight>=300 && strength>=500)
		{
      if(flag)
        printf(" ");
			flag=true;
			printf("Lineman");
		}
		if(speed<=5.0 && weight>=200 && strength>=300)
    {
      if(flag)
        printf(" ");
			flag=true;
			printf("Quarterback");
		}
		if(flag)
			printf("\n");
		else
			printf("No positions\n");
	}

  return 0;
}
