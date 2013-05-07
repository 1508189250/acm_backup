/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2012-03-14 20:19
 # Filename: POJ2752 Seek the Name, Seek the Fame.cpp
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
#define MAX 400010
using namespace std;

char str[MAX];
int ans[MAX],next[MAX];

void get_next(){
  int i = 0, j = -1 , len=strlen(str);
  next[0] = -1;
  while(i < len){
    if(j == -1 || str[i] == str[j]){
      i ++; j ++;
      next[i] = j;
    }
    else 
      j = next[j];
  }
}

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

  while(gets(str))
  {
    int cnt=0;
    int len=strlen(str);
    get_next();
    for(int i=len;i>=0;)
    {
      ans[cnt++]=i;
      i=next[i];
    }

    for(int i=cnt-2;i>=0;--i)
      printf("%d%c",ans[i],(i==0)?'\n':' ');
  }

  return 0;
}
