/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2012-03-23 19:46
 # Filename: POJ1026 HDU1439 Cipher.cpp
 # Description : 
 ******************************************************************************/
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
#define MAX 1100
using namespace std;

int num[MAX],array[MAX][MAX],order[MAX];
char input[MAX],output[MAX];

void func(const int &n)
{
  memset(order,0,sizeof(order));
  for(int i=0;i<n;++i)
    array[0][i]=i;
  int tmp=n;
  int ind=1;
  while(tmp)
  {
    for(int i=0;i<n;++i)
      if(!order[i])
        array[ind][num[i]]=array[ind-1][i];
    for(int i=0;i<n;++i)
      if(!order[i] && array[ind][i]==array[0][i])
      {
        order[i]=ind;
        --tmp;
      }

      ++ind;
  }
}

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

  int n,k;

  while(scanf("%d",&n) &&n)
  {
    // 		memset(num,-1,sizeof(num));
    for(int i=0;i<n;++i)
    {
      scanf("%d",&num[i]);
      --num[i];
    }

    func(n);

    while(scanf("%d",&k) && k)
    {
      getchar();
      gets(input);
      for(int i=strlen(input);i<n;++i)
        input[i]=' ';
      memset(output,' ',sizeof(output));
      for(int i=0;i<n;++i)
      {
        output[i]=input[array[k%order[i]][i]];
      }
      output[n]='\0';
      puts(output);
    }

    printf("\n");
  }

  return 0;
}
