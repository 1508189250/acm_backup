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

long long func(const int &n,const int &m)
{
  if( n == 0 ) return 1 % m;  //m==1µÄÇé¿ö
  long long ans=1ll,temp=1ll;

  for(int i=1;i<=n;++i)
  {
      temp*=i;
      temp %=m;
      ans +=temp;
      ans %=m;
  }
  return ans;
}

bool check(const char *lhs,const char *rhs)
{
  int llen=strlen(lhs),rlen=strlen(rhs);
  if(llen<rlen)
    return true;
  else if(llen>rlen)
    return false;

  if(strcmp(lhs,rhs)<0)
    return true;
  return false;
}

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

	int ncases,n,m;
  char l_str[110],r_str[110];
	scanf("%d",&ncases);

	while(ncases--)
	{
		scanf("%s%d",l_str,&m);
    sprintf(r_str,"%d",m);

    if(check(l_str,r_str))
      sscanf(l_str,"%d",&n);
    else
      n=m;

		printf("%lld\n",func(n,m));
	}

  return 0;
}
