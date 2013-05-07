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

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

  char array[]="V W X Y Z A B C D E F G H I J K L M N O P Q R S T U";
  char str[MAX];

  while(gets(str))
  {
    if(str[0]=='E')
      break;
    gets(str);
    int i=0;
    while(str[i])
    {
      if(isalpha(str[i]))
        str[i]=array[(str[i]-'A')*2];
      ++i;
    }
    printf("%s\n",str);
    gets(str);
  }

  return 0;
}


