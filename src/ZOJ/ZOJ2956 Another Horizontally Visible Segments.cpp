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
#define MAX 4010
using namespace std;

struct LINE{
  int x,y1,y2;
  void get()
  {
    scanf("%d%d%d",&x,&y1,&y2);
  }
};

LINE lines[MAX];
int y_coord[2*MAX],sum[2*MAX];

int func(const int &n, const int &cnt)
{
	for(int i=0;i<n;++i)
	{
		int a=lower_bound(y_coord,y_coord+cnt,lines[i].y1)-y_coord;
		int b=lower_bound(y_coord,y_coord+cnt,lines[i].y2)-y_coord;
		for(int i=a;i<=b;++i)
			++sum[i];
	}
	int ans=0;
	for(int i=0;i<cnt;++i)
		ans=max(ans,sum[i]);
	return ans;
}

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
		memset(y_coord,0,sizeof(y_coord));
		memset(sum,0,sizeof(sum));
		int cnt=0;

		for(int i=0;i<n;++i)
		{
			lines[i].get();
			y_coord[cnt++]=lines[i].y1;
			y_coord[cnt++]=lines[i].y2;
		}
		sort(y_coord,y_coord+cnt);
		cnt=unique(y_coord,y_coord+cnt)-y_coord;

		int ans=func(n,cnt);
		printf("%d\n",ans);
	}

  return 0;
}
