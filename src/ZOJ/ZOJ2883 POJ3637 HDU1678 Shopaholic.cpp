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
#define MAX 20020
using namespace std;

int price[MAX];

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  
	int ncases,n;
	scanf("%d",&ncases);

	while(ncases--)
	{
		scanf("%d",&n);
		for(int i=0;i<n;++i)
			scanf("%d",&price[i]);
		sort(price,price+n,greater<int>());
		int total=0;
		for(int i=2;i<n;i+=3)
			total+=price[i];
		printf("%d\n",total);
	}

  return 0;
}
