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
#define MAX 20
using namespace std;

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

	char str[2][MAX];
  int ncase;
  char spaces[11][11] = { 
    "",
    " ", 
    "  ", 
    "   ", 
    "    ",
    "     ",
    "      ",
    "       ",
    "        ",
    "         ",
    "          "
  };

  int cnt=0,round=0;
  scanf("%d",&ncase);

for(int nc=0;nc<ncase;++nc)
{
//   if(nc==0)
//     gets(str[++round%2]);
	while(gets(str[++round%2]))
	{
    int forward = 0 , k=0 , i ;
    while ( gets(str[++k%2]) )
    {
      i = 0;
      while ( str[k%2][i] == str[(k+1)%2][i] && str[k%2][i] )  ++i; 
      forward = ( ++forward > i ?  i : forward ) ;
      printf("%s%s\n",spaces[forward],str[k%2]);
    }
  } 
}



  return 0;
}
