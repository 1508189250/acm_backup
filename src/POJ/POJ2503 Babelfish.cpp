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
#include <map>
#define MAX 100010
using namespace std;

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

	map<string,string> m_map;
	string s_key,s_value, str;

	while(getline(cin,str))
	{
		if(str.empty())
			break;

		size_t pos=str.find(' ');

		m_map.insert(make_pair<string,string>(str.substr(pos+1,str.size()-pos-1),str.substr(0,pos)));
	}

	while(getline(cin,str))
	{
		if(str.empty())
			break;

    map<string,string>::iterator iter=m_map.find(str);
    if(iter==m_map.end())
      cout<<"eh"<<endl;
    else
      cout<<iter->second<<endl;
  }

  return 0;
}
