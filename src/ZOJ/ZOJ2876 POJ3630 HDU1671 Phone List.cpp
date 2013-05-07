/*******************************************************************************
 * Author : Neo Fung
 * Email : neosfung@gmail.com
 * Last modified : 2011-09-12 19:14
 * Filename : ZOJ2876 POJ3630 HDU1671 Phone List.cpp
 * Description : 
 * *****************************************************************************/
// ZOJ2876 POJ3630 HDU1671 Phone List.cpp : Defines the entry point for the console application.
//

// #include "stdafx.h"
// #define DEBUG


#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <memory.h>

#define KINDNUM 10  //字母种类，直接就
using namespace std;

int arrayIndex;

struct TrieNode//树的结点结构
{
	bool isNum;
	TrieNode *next[KINDNUM];//指向儿子结点，注意此处是 指针数组
}nodeArray[200000];

bool insert(TrieNode *&root,char *word)//向以root为根结点的树中插入串word
{
	TrieNode *location=root;
	int i=0,branch=0;
	if(location==NULL) 
	{
		location=&nodeArray[arrayIndex++];
		location->isNum=false;
		for(int i=0;i<KINDNUM;++i)
			location->next[i]=NULL;
		root=location;
	}

	while(word[i])
	{
		branch=word[i]-'0';
		if(location->next[branch])
		{
			if(location->next[branch]->isNum || !word[i+1])
				return false;
		}
		else {
			location->next[branch]=&nodeArray[arrayIndex++];
			location->next[branch]->isNum=false;
			for(int i=0;i<KINDNUM;++i)
				location->next[branch]->next[i]=NULL;
		}
		i++;
		location=location->next[branch];
	}
	location->isNum=true;
	return true;
}

int main(void)
{
#ifdef DEBUG   
	freopen("data.txt","r",stdin);  
#endif  

	int ncases,n;
	char num[12];
	scanf("%d",&ncases);
	while(ncases--)
	{
		scanf("%d",&n);
		arrayIndex=0;
		TrieNode *head=NULL;
		bool consistent=true;
		getchar();
		while(n--)
		{
			gets(num);
			bool bTemp;
			if(consistent)
				bTemp=insert(head,num);
			if(!bTemp)
				consistent=bTemp;
		}
		if(consistent)
			printf("YES\n");
		else
			printf("NO\n");
	}

	return 0;
}
