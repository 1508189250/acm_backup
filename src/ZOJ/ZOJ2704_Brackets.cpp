/*******************************************************************************
 * Author : Neo Fung
 * Email : neosfung@gmail.com
 * Last modified : 2011-07-13 10:53
 * Filename : ZOJ2074_Brackets.cpp
 * Description : http://acm.zju.edu.cn/onlinejudge/showProblem.do?problemCode=2704
 * *****************************************************************************/
// ZOJ2074_Brackets.cpp : 定义控制台应用程序的入口点。
//
// 
// #include "stdafx.h"
// #include <fstream>

#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <stack>
#include <deque>
#include <map>
#include <math.h>
#include <algorithm>
#include <numeric>
#include <functional>
#include <locale.h>

using namespace std;

int main(void)
{
	//ifstream cin("data.txt");
	stack<char> mystack;
	deque<char> mydeque;
	char ch;
	char *str=new char[150000];
	char *result = new char[150000];
	//int sum[100]={0};
	int count=0,temp;
	while(cin>>str)
	{
		while(!mystack.empty()) mystack.pop();
		mydeque.clear();
		memset(result,'\0',sizeof(result));
		count=0;
		temp=0;
		for(int i=0;i<strlen(str);++i)
		{
			if(str[i]==')')
			{
				if(mystack.top() == '(')
				{
					mydeque.push_front('(');
					mydeque.push_back(')');
					++temp;
					mystack.pop();
				}
				else
				{
					if(temp>count)
					{
						memset(result,0,sizeof(result));
						for(int j=0;j<2*temp;++j)
						{
							result[j]=mydeque.front();
							mydeque.pop_front();
						}
						count=temp;
					}
				}
			}
			else if (str[i] == ']')
			{
				if(mystack.top() =='[')
				{
					mydeque.push_front('[');
					mydeque.push_back(']');
					++temp;
					mystack.pop();
				}
				else
				{
					if(temp>count)
					{
						memset(result,0,sizeof(result));
						for(int j=0;j<2*temp;++j)
						{
							result[j]=mydeque.front();
							mydeque.pop_front();
						}
						count=temp;
					}
				}
			}
			else
			{
				mystack.push(str[i]);
			}
		}
		for (int i=0;i<2*count;++i)
		{
			cout<<result[i];
		}
		cout<<endl<<endl;
	}

	delete []str;
	delete []result;


	return 0;
}
