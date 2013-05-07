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
#define MAX 50
using namespace std;

struct REC
{
	int cnt,len,ini,dis;

  REC(){}
	REC(const int &a,const int &b,const int &c,const int &d):cnt(a),len(b),ini(c),dis(d)
	{
	}

	bool operator<(const REC &tmp) const
	{
    if(cnt!=tmp.cnt)
      return cnt<tmp.cnt;
    else if(len!=tmp.len)
      return len<tmp.len;
    else if(ini != tmp.ini)
      return ini<tmp.ini;
    else
      return dis>tmp.dis;
	}
};

char lake[MAX];

REC func(const int &x,const int &d,const int &n)
{
	int cnt=0,len;
  for( cnt=0; x+d*cnt<n; ++cnt ){
    if( lake[x+d*cnt] != '.' )
      break ;
  }	
  if(x+1+d*cnt>n)
    len=n;
  else
    len=x+1+d*cnt;
  REC ans=REC(cnt,len,x,d);
	return ans;
}

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

	while(gets(lake))
	{
		if(!strcmp(lake,"END"))
			break;
		int n=strlen(lake);
		REC ans=REC(0,0,0,INT_MAX), tmp;
		for(int i=0;i<n;++i)
			for(int j=1;i+j<n;++j)
			{
				tmp=func(i,j,n);
				ans=max(tmp,ans);
			}
    tmp=func(n-1,1,n);
    ans=max(ans,tmp);
		printf("%d %d\n",ans.ini,ans.dis);
	}

  return 0;
}
