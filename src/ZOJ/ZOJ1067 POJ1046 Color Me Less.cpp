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

struct DATA
{
	int a,b,c;
	bool get()
	{
		scanf("%d%d%d",&a,&b,&c);
		if(a==-1 && b==-1 &&c==-1)
			return false;
		return true;
	}
	void put()
	{
		printf("(%d,%d,%d)",a,b,c);
	}

	int dis(const DATA &tmp)
	{
		return (tmp.a-a)*(tmp.a-a)+(tmp.b-b)*(tmp.b-b)+(tmp.c-c)*(tmp.c-c);
	}
}data[16],tmp;

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

	for(int i=0;i<16;++i)
		data[i].get();

	while(tmp.get())
	{
		int ans=0;
		int dis=data[0].dis(tmp);
		for(int i=1;i<16;++i)
		{
			int temp=data[i].dis(tmp);
			if(temp<dis)
			{
				dis=temp;
				ans=i;
			}
		}
		tmp.put();
		printf(" maps to ");
		data[ans].put();
		printf("\n");
	}

  return 0;
}
