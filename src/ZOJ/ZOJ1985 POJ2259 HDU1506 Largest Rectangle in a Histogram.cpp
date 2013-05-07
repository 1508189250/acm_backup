#ifdef _MSC_VER
#define DEBUG
#define _CRT_SECURE_NO_DEPRECATE
#endif

#include <fstream>
#include <stdio.h>
#define MAX 100010
using namespace std;

int left_array[MAX],right_array[MAX];
long long array[MAX];

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

  int n,ncase=1;
  //   scanf("%d",&ncase);

  while(~scanf("%d",&n) && n)
  {
    array[0]=left_array[0]=0ll;
    for(int i=1;i<=n;++i)
    {
      scanf("%lld",&array[i]);
      left_array[i]=i;
      right_array[i]=i;
    }
    array[n+1]=right_array[n+1]=0ll;


    long long ans=0;
    for(int i=1;i<=n;++i)
    {
      int x=i;
      while(x && array[x-1]>=array[i])
        x=left_array[x-1];
      left_array[i]=x;
    }

    for(int i=n;i>0;--i)
    {
      int	x=i;
      while(x && array[x+1]>=array[i])
        x=right_array[x+1];
      right_array[i]=x;
    }
    for(int i=1;i<=n;++i)
      ans=max((right_array[i]-left_array[i]+1)*array[i],ans);
    printf("%lld\n",ans);
  }

  return 0;
}
