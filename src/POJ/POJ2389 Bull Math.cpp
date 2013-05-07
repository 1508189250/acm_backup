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

//一种比较简单的大数乘法函数，a为被乘数，ca为被乘数的长度
//b为乘数，cb为乘数的长度，c为积保存的数组，返回值为积的长度
int multiply(char* a,int ca,char* b,int cb,char * c)  
{  
  int i,j,* s;  
  s=(int*)malloc(sizeof(int)*(ca+cb));  
  for (i=0;i<ca+cb;i++)  
    s[i]=0;  
  for (i=0;i<ca;i++)  
    for (j=0;j<cb;j++)  
      s[i+j+1]+=(a[i]-'0')*(b[j]-'0');//i+j+1的目的就是为了防止最高位进位而产生错误  
  for (i=ca+cb-1;i>=0;i--)  
    if (s[i]>=10)  
    {  
      s[i-1]+=s[i]/10;  
      s[i]%=10;  
    }  
    i=0;  
    while (s[i]==0)  
      i++;//去除前导0  
    for (j=0;i<ca+cb;i++,j++)  
      c[j]=s[i]+'0';
    c[j]='\0';
    free(s);  
    return j;
}  

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

  int n,ncase=1;
  //   scanf("%d",&ncase);
  char str1[MAX],str2[MAX],ans[2*MAX];

  gets(str1);
  gets(str2);

  multiply(str1,strlen(str1),str2,strlen(str2),ans);
  
  puts(ans);

  return 0;
}
