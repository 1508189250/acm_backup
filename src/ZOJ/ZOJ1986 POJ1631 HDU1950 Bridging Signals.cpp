#ifdef _MSC_VER
#define DEBUG
#endif

#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
// #include <memory.h>
#include <limits.h>
#include <algorithm>
#include <math.h>
#include <numeric>
#include <functional>
#include <ctype.h>
#define MAX 40010
using namespace std;

int LIS(const int *num,const int &n)
{
	int *record = new int[n];
	memset(record,0,sizeof(int)*n);
	int len=1;
	int ind;
	record[0]=num[0];

	for(int i=1;i<n;++i)
	{
		if(num[i]<record[0])
			ind = 0;
		else if(num[i]>record[len-1])
			ind = len++;
		else
			ind = upper_bound(record,record+len,num[i])-record;
		record[ind]=num[i];
	}

	delete []record;
	return len;
}

int main(void)
{
#ifdef DEBUG  
	freopen("../stdin.txt","r",stdin);
	freopen("../stdout.txt","w",stdout); 
#endif  

	int num[MAX],n;
	int ncases;
	scanf("%d",&ncases);

	while(ncases--)
	{
		scanf("%d",&n);
		for(int i=0;i<n;++i)
			scanf("%d",&num[i]);

		int ans = LIS(num,n);
		printf("%d\n",ans);
	}

	return 0;
}
