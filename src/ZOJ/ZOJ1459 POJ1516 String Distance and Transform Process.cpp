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
#define MAX 81
using namespace std;

int dp[MAX][MAX],edit[MAX][MAX];
char str_a[MAX],str_b[MAX];

void outpath( int n, int m){  
  int p=0;  
  while(n!=0 || m!=0 ){  

    edit[n][m]?p++:1;  
    switch(edit[n][m]){  
        case 1 : cout<<p<<" Delete "<<n<<endl; break;  
        case 2 : cout<<p<<" Insert "<<n+1<<","<<str_b[m]<<endl;break;  
        case 3 : cout<<p<<" Replace "<<n<<","<<str_b[m]<<endl;break;  
    }  
    switch(edit[n][m]){  
        case 3 :  
        case 0 : n--,m--;break;  
        case 1 : n--; break;  
        case 2 : m--; break;  
    }  
  }  
}  

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

//   int n,ncase=1;
  //   scanf("%d",&ncase);

  while(~scanf("%s %s",str_a+1,str_b+1) )
  {
//     gets(str_b+1);
    int n=strlen(str_a+1);
    int m=strlen(str_b+1);
    edit[0][0]=0;
    for(int i=1;i<=n;i++){  
      dp[i][0]=dp[i-1][0]+1;  
      edit[i][0]=1;  
    }  
    for(int j=1;j<=m;j++){  
      dp[0][j]=dp[0][j-1]+1;  
      edit[0][j]=2;  
    }  
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j)
				if(str_a[i]==str_b[j])
        {
					dp[i][j]=dp[i-1][j-1];
          edit[i][j]=0;
        }

				else
        {
          int deletion = dp[i-1][j] + 1;   
          int insertion = dp[i][j-1] + 1;
          int substitution = dp[i-1][j-1] + 1; 
          dp[i][j]=min(min(insertion,substitution),deletion); 
          if(dp[i][j]==deletion)  
            edit[i][j]=1;  
          if(dp[i][j]==insertion)  
            edit[i][j]=2;  
          if(dp[i][j]==substitution)  
            edit[i][j]=3;          
        }

		printf("%d\n",dp[n][m]);
    outpath(n,m);

  }

  return 0;
}
