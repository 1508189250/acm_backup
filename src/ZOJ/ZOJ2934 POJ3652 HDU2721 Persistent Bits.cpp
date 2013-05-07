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
#define MAX 1<<16
using namespace std;

int num[MAX],bit[16];
bool visit[MAX];

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

	int a,b,c,s;
	while(scanf("%d",&a) &&a)
	{
		scanf("%d%d%d",&b,&c,&s);
		memset(visit,false,sizeof(visit));
		memset(num,0,sizeof(num));
		memset(bit,0,sizeof(bit));

		int cnt=0;
		do
		{
			num[cnt++]=s;
			visit[s]=true;
			s=(a*s+b)%c;
		}while(!visit[s]);
		
		for(int i=0;i<cnt;++i)
		{
			int temp=num[i];
			int ind=0;
			while(temp)
			{
				bit[ind++]+=temp&1;
				temp=temp>>1;
			}
		}
		for(int i=15;i>=0;--i)
			if( bit[i]==cnt)
				printf("1");
			else if(bit[i]==0)
				printf("0");
			else
				printf("?");
		printf("\n");
	}

  return 0;
}
