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
#define MAX 100010
using namespace std;

bool col[MAX*100];
bool ans[MAX*100];
int discretization[MAX*100];
struct POINT
{int beg,end;}point[4*MAX];

int func(const int &n,const int &cnt)
{
	memset(col,false, sizeof(col));
	memset(ans,false, sizeof(ans));
	for(int i=0;i<n;++i)
	{
		int beg=lower_bound(discretization,discretization+cnt,point[i].beg)-discretization;
		int end=lower_bound(discretization,discretization+cnt,point[i].end)-discretization;
		for(int i=beg;i<end;++i)
			col[i]=!col[i];
	}

	int max_len=0;
	int temp=0;
	for(int i=0;i<cnt-1;++i)
		if(col[i])
			for(int j=discretization[i];j<discretization[i+1];++j)
				ans[j]=true;
	for(int i=0;i<=discretization[cnt-1];++i)
		if(ans[i])
			++temp;
		else
		{
			max_len = max(max_len,temp);
			temp=0;
		}
	return max_len;
}

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  
  int l,m,n;

  while(~scanf("%d%d%d",&l,&n,&m))
  {
      int cnt=0;
	  for(int i=0;i<m+n;++i)
	  {
		  scanf("%d%d",&point[i].beg,&point[i].end);
		  ++point[i].end;
		  discretization[cnt++]=point[i].beg;
		  discretization[cnt++]=point[i].end;
	  }
	  sort(discretization,discretization+cnt);
	  cnt = unique(discretization,discretization+cnt) - discretization;
	  int ans=func(n+m,cnt);
	  printf("%d\n",ans);
  }

	return 0;
}
