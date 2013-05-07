/*******************************************************************************
 * Author : Neo Fung
 * Email : neosfung@gmail.com
 * Last modified : 2011-07-05 21:47
 * Filename : ZOJ2358.cpp
 * Description : 
 * *****************************************************************************/
// ZOJ2358.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

//#include <fstream>
#include <iostream>
//#include <stdio.h>

using namespace std;

int main(int argc, char* argv[])
{
	//ifstream cin("data.txt");
	long  n;
	//scanf("%l",&n);
	cin>>n;
	//long  *factorials = new long  [10];
	long factorials[10];
	factorials[0]=factorials[1]=1;
	for(int i = 2;i<10;++i)
		factorials[i] = factorials[i-1]* i;

	while(n>=0)
	{
		if(!n ) cout << "NO"<<endl;
		else
		{
			for(int i =9;i>=0 , n>0;--i)
			{
				if(factorials[i] <= n)
					n=n-factorials[i];
			}
			if(!n) cout<<"YES"<<endl;
			else cout<<"NO"<<endl;
		}
		cin>>n;
	}

	//delete []factorials;
	return 0;
}

