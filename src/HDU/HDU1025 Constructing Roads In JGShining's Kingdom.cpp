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
#define MAX 500110
using namespace std;

int array[MAX];


int LIS(const int *num,const int &n)
{
	if(!n)
		return 0;
	int ind,len=1;
	int *record = new int[n];
	memset(record,0,sizeof(int)*n);
	record[0]=num[0];

	for(int i=1;i<n;++i)
	{
		if(num[i]<record[0])
			ind=0;
		else if(num[i]>record[len-1])
			ind=len++;
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

	int n;
	int ncase=1;
	int ind;
	while(~scanf("%d",&n))
	{
		for(int i=0;i<n;++i)
		{
			scanf("%d",&ind);
			scanf("%d",&array[ind-1]);
		}
		int ans=LIS(array,n);

		printf("Case %d:\n",ncase++);
		printf("My king, at most %d road%scan be built.\n\n",ans,ans<=1?" ":"s ");
	}

	return 0;
}
