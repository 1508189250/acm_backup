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

//һ�ֱȽϼ򵥵Ĵ����˷�������aΪ��������caΪ�������ĳ���
//bΪ������cbΪ�����ĳ��ȣ�cΪ����������飬����ֵΪ���ĳ���
int multiply(char* a,int ca,char* b,int cb,char * c)  
{  
  int i,j,* s;  
  s=(int*)malloc(sizeof(int)*(ca+cb));  
  for (i=0;i<ca+cb;i++)  
    s[i]=0;  
  for (i=0;i<ca;i++)  
    for (j=0;j<cb;j++)  
      s[i+j+1]+=(a[i]-'0')*(b[j]-'0');//i+j+1��Ŀ�ľ���Ϊ�˷�ֹ���λ��λ����������  
  for (i=ca+cb-1;i>=0;i--)  
    if (s[i]>=10)  
    {  
      s[i-1]+=s[i]/10;  
      s[i]%=10;  
    }  
    i=0;  
    while (s[i]==0)  
      i++;//ȥ��ǰ��0  
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
