// #include "stdafx.h"
// #define DEBUG
// 
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
#include <assert.h>
#include <ctype.h>

#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#define EPS 1e-10
using namespace std;

int main(void)
{
#ifdef DEBUG  
  freopen("C:/Users/neo/Desktop/stdin.txt","r",stdin);
  freopen("C:/Users/neo/Desktop/stdout.txt","w",stdout); 
#endif  
	
	double a,b,r1,r2;

	while(~scanf("%lf%lf%lf%lf",&a,&b,&r1,&r2))
	{

    bool flag = r1 + r2 < sqrt( (a-r1-r2)*(a-r1-r2) + (b-r1-r2)*(b-r1-r2) )+EPS;
		if(flag && a>2*r1 && b>2*r1 && a>2*r2 &&b>2*r2)
			printf("Yes\n");
		else
			printf("No\n");
	}

  return 0;
}
