/*******************************************************************************
 * Author : Neo Fung
 * Email : neosfung@gmail.com
 * Last modified : 2011-07-07 20:03
 * Filename : ZOJ1666.cpp
 * Description : Square Coins
 * *****************************************************************************/
// ZOJ1666.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <fstream>

#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>

using namespace std;

int main(void)
{
	//ifstream cin("data.txt");

	int num[301]={0};
	int coins[18];
	int temp;
	num[0]=1;
	for(int i=1;i<=17;++i)
	{
		coins[i]=i*i;
	}

	for(int i=1;i<=17;++i)
		for(int j=coins[i];j<301;j++)
			num[j] +=num[j-coins[i]];
	
	while(cin>>temp && temp)
		cout<<num[temp]<<endl;


	return 0;
}
