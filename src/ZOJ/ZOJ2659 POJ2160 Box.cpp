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
#define MAX 6
using namespace std;

struct REC
{
	int x,y;
	void get()
	{
		scanf("%d%d",&x,&y);
		if(x>y)
			swap(x,y);
	}
	bool operator==(const REC &rhs) const
	{
		return x==rhs.x && y==rhs.y;
	}

	bool operator<(const REC &rhs) const
	{
		if(x==rhs.x)
			return y<rhs.y;
		else
			return x<rhs.x;
	}
}rec[MAX];

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

	while(~scanf("%d%d",&rec[0].x,&rec[0].y))
	{
		if(rec[0].x>rec[0].y)
			swap(rec[0].x,rec[0].y);
		for(int i=1;i<MAX;++i)
			rec[i].get();

		sort(rec,rec+MAX);

		bool flag=true;
		if(flag)
			for(int i=0;i<MAX;i+=2)
				if(!(rec[i]==rec[i+1]))
					flag=false;

		if(flag)
		{
			REC &a=rec[0],&b=rec[2],&c=rec[4];

			if(a.x==b.x && a.y==c.x && b.y==c.y);
			else if(a.x==b.x && a.y==c.y && b.y==c.x);

			else if(a.x==b.y && a.y==c.x && b.x==c.y);
			else if(a.x==b.y && a.y==c.y && b.x==c.x);

			else if(a.x==c.x && a.y==b.x && c.y==b.y);
			else if(a.x==c.x && a.y==b.y && c.y==b.x);

			else if(a.x==c.y && a.y==b.x && c.x==b.y);
			else if(a.x==c.y && a.y==b.y && c.x==b.x);

			else flag=false;
		}

		if(flag)
			printf("POSSIBLE\n");
		else
			printf("IMPOSSIBLE\n");
	}

  return 0;
}
