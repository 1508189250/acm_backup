/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2012-01-29 22:22
 # Filename: POJ2892 HDU 1540 Tunnel Warfare.cpp
 # Description : ������״�����find_k_thʵ���ҵ�sumΪk����Сλ��, 
 ʱ�临�Ӷ�ΪO(log(n))
 ******************************************************************************/
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
#include <stack>
#include <math.h>
#define MAX 50010
#define lowbit(x) (x&(-x))
using namespace std;

int c[MAX];
stack<int> order;

int getsum(int x)
{
	int sum=0;
	for(int i=x;i>0;i-=lowbit(i))
			sum+=c[i];
	return sum;
}

void updata(const int &x,const int &n, const int &val)
{
	for(int i=x;i<=n;i+=lowbit(i))
		c[i]+=val;
}

//�ҵ�kС��λ��
int find_k_th(int k,const int &n, const int &logn) 
{
  int cnt=0,cur=0;
  for (int i=logn;i>=0;--i) {
    cur+=(1<<i); 
    if (cur>n || cnt+c[cur]>=k) cur-=(1<<i); 
    else cnt+=c[cur];
  }
  return cur+1;
}


int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

  int n,m,x;
  char ch;

  while(~scanf("%d%d",&n,&m))
  {
	  memset(c,0,sizeof(c));
	  while(!order.empty())
		  order.pop();
    n+=2;
    updata(1,n,1);  //1��λ��n+2��λ�����ڱ�, ֻ��[2,n+1]��¼��Ч����;
    updata(n,n,1);
    int logn = int(log(n+1.0)/log(2.0));
	  while(m--)
	  {
      getchar();
		  scanf("%c",&ch);
		  if(ch=='D')
      {
        scanf("%d",&x);
        ++x;
			  order.push(x);
			  updata(x,n,1);
		  }
		  else if(ch=='R')
		  {
			  x=order.top();
			  order.pop();
			  updata(x,n,-1);
		  }
		  else
		  {
        scanf("%d",&x); ++x;
        int sum=getsum(x),pre=find_k_th(sum,n,logn),next=find_k_th(sum+1,n,logn);
        if (pre!=x) printf("%d\n",next-pre-1);
        else printf("0\n");
      }
	  }
  }

	return 0;
}
