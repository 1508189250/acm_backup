// ZOJ3439 Substitution Cipher.cpp : Defines the entry point for the console application.
//

// #include "stdafx.h"


#include <stdio.h>
#include <cctype>
#include <iostream>

using namespace std;

int main(void)
{

	char decode[]={'l','m','p','j','e','o','r','u','a','d','b','c','y','h','w','s','z','x','n','t','f','g','q','v','i','k'};
	char ch;
	while(scanf("%c",&ch)!=EOF)
	{
		if (!isalpha(ch))
		{
			cout<<ch;
			continue;
		}
		else if (ch>='a'&&ch<='z')
		{
			int i;
			for(i=0;i<26;++i)
				if(decode[i]==ch)
					break;
			ch='a'+i;

		}
		else if(ch>='A'&& ch<='Z')
		{
			int i;
			for(i=0;i<26;++i)
				if(decode[i]==(ch+'a'-'A'))
					break;
			ch='A'+i;
		}
		cout<<ch;
	}
	return 0;
}
