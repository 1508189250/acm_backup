/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2011-10-04 19:17
 # Filename: ZOJ1808 POJ1056 HDU1305 Immediate Decodability.cpp
 # Description : 
 ******************************************************************************/
//  #include "stdafx.h"
//  #define DEBUG

#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <memory.h>
using namespace std;
#define KINDNUM 2
#define MAX	20000

struct TrieNode
{
	bool isNum;
	TrieNode *next[KINDNUM];
}node[MAX],*head;
int nodeInd;

bool insert(TrieNode *&root,char *num)
{
	TrieNode *location=root;
	int i=0,branch=0;
	if(location==NULL)
	{
		location=&node[nodeInd++];
		location->isNum=false;
		for (int j=0;j<KINDNUM;++j)
			location->next[j]=NULL;
		root=location;
	}

	while(num[i])
	{
		branch=num[i]-'0';
		if(location->next[branch] &&
				(!num[i+1] || location->next[branch]->isNum))
			return false;
		else if(!(location->next[branch]))
		{
			location->next[branch]=&node[nodeInd++];
			location->next[branch]->isNum=false;
			for (int j=0;j<KINDNUM;++j)
				location->next[branch]->next[j]=NULL;
		}
		++i;
		location=location->next[branch];
		if(!num[i])
			location->isNum=true;
	}
	return true;
}

int main(void)
{
#ifdef DEBUG  
	freopen("data.txt","r",stdin);  
#endif  
	char str[15];
	int ncase=1;
	while(gets(str) && strlen(str)!=0)
	{
		nodeInd=0;
		head=NULL;
		if(str[0]=='9') break;
		printf("Set %d ",ncase++);
		bool ans=insert(head,str);
		while(gets(str) && str[0]!='9')
		{
			if(ans)
				ans= ans&&insert(head,str);
		}
		if(ans)
			printf("is immediately decodable\n");
		else
			printf("is not immediately decodable\n");
	}

	return 0;
}
