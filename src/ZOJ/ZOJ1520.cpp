// ZOJ1520.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


#include <stdio.h>
#include <string>

using namespace std;

bool flag[2001];
int Cap[2001];

int main(int argc, char* argv[]){
	int i , j ;
	int count , sum ;
	int   M , L ,N ;
	while(scanf("%d %d",&M , &L) !=EOF)
	{
		if( M == 0 && L == 0   )
			break ;
		scanf("%d",&N ) ;
		sum = 0 ;
		for( i =1 ;i <= N; i++)
		{
			scanf("%d",&Cap[i] ) ;
			sum += Cap[i] ;
		}
		if(sum > M+L)   
		{
			printf("Impossible to distribute\n") ;
			continue ;
		}

		for( i = 1 ; i<=N ;i++)
		{
			memset(flag , false ,sizeof(flag) );
			int total = 0;
			count = 0;
			for( j =i ; j<= N ;j++)
			{
				if(total+Cap[j] > M )
					continue ;
				flag[j] =true ;
				total += Cap[j] ;
				count ++ ;
			}
			if( sum - total <= L )
				break ;
		}
		if(i > N)
			printf("Impossible to distribute\n");
		else
		{
			printf("%d",count);

			for(i = 1; i <= N;i ++)
				if(flag[i])
					printf(" %d",i) ;
			printf("\n");
		}
	}
	return 0;
}