// #include "stdafx.h"
// #define DEBUG

#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <memory.h>

#include <math.h>
#include <algorithm>
#include <numeric>
#include <functional>
#include <limits>
#include <assert.h>
#include <cctype>
#include <map>

using namespace std;
map<string,int> names;
string str[]={"A","A#","B","C","C#","D","D#","E","F","F#","G","G#"};
int major[12],minor[12];

void init()
{
	for(int i=0;i<12;++i)
		names[str[i]]=i;
	names["BB"]=1;
	names["DB"]=4;
	names["EB"]=6;
	names["GB"]=9;
	names["AB"]=11;
	for(int i=0;i<12;++i)
	{
		int num[3]={i,(i+4)%12,(i+7)%12};
		sort(num,num+3);
		major[i]=num[0]+num[1]*100+num[2]*10000;
		int num2[3]={i,(i+3)%12,(i+7)%12};
		sort(num2,num2+3);
		minor[i]=num2[0]+num2[1]*100+num2[2]*10000;
	}
}

int main(void)
{
#ifdef DEBUG  
	freopen("data.txt","r",stdin);  
#endif  
	init();
	string str1,str2,str3;
	string s1,s2,s3;
	while(cin>>s1>>s2>>s3)
	{
		str1=s1,str2=s2,str3=s3;
		transform(str1.begin(),str1.end(),str1.begin(),::toupper);
		transform(str2.begin(),str2.end(),str2.begin(),::toupper);
		transform(str3.begin(),str3.end(),str3.begin(),::toupper);
		int num[3]={names[str1],names[str2],names[str3]};
		sort(num,num+3);
		int temp=num[0]+num[1]*100+num[2]*10000;
		int ind;
		cout<<s1<<' '<<s2<<' '<<s3<<" is ";
		int flag=0;
		for(ind=0;ind<12;++ind)
		{
			if(major[ind]==temp)
			{
				cout<<"a "<<str[ind]<<" Major chord."<<endl;
				flag=1;
				break;
			}
			else if(minor[ind]==temp)
			{
				cout<<"a "<<str[ind]<<" Minor chord."<<endl;
				flag=1;
				break;
			}
		}
		if(flag)
			continue;
		else
			cout<<"unrecognized."<<endl;
	}
	return 0;
}
