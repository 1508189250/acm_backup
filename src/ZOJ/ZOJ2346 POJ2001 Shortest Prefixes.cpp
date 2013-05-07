// ZOJ2346 POJ2001 Shortest Prefixes.cpp : Defines the entry point for the console application.
//

// #include "stdafx.h"
// #define DEBUG


#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <memory.h>

using namespace std;

#define KINDNUM 26  //字母种类，直接就
int arrNum;

struct TrieNode//树的结点结构
{
	int count;//这个附加变量在本题中记录遍历到该结点形成的字符串出现的次数，在不同题中可记录不同的内容。
	TrieNode *next[KINDNUM];//指向儿子结点，注意此处是 指针数组
}trieArray[40000];

void insert(TrieNode *&root,char *word)//向以root为根结点的树中插入串word
{
	TrieNode *location=root;
	int i=0,branch=0;

	if(location==NULL) 
	{
		location=&trieArray[arrNum++];
		location->count=0;
		for(int i=0;i<KINDNUM;++i)
			location->next[i]=NULL;
		root=location;
	}
	location->count++;

	while(word[i])
	{
		branch=word[i]-'a';
		if(location->next[branch]) location->next[branch]->count++;//如果该字符存在，串数量加1
		else 
		{
			location->next[branch]=&trieArray[arrNum++];
			location->next[branch]->count=0;
			for(int i=0;i<KINDNUM;++i)
				location->next[branch]->next[i]=NULL;
		}
		location->next[branch]->count++;
		i++;
		location=location->next[branch];
	}
}

int search(TrieNode *&root,char *word)//查找，与插入类似
{
	TrieNode *location=root;
	int i=0,branch=0;

	if(location==NULL) return 0;

	while(word[i])
	{
		branch=word[i]-'a';
		location->next[branch]->count--;
		if(location->next[branch]->count==0)
			return i+1;
		i++;
		location=location->next[branch];
	}
	return i;
}

char str[1010][25];

int main(void)
{
#ifdef DEBUG  
	freopen("data.txt","r",stdin);  
#endif  
	int ncases;;

	scanf("%d",&ncases);
	getchar();
	getchar();

	while(ncases--)
	{
		TrieNode *tHead=NULL;
		char output[25];
		int n=0;
		arrNum=0;

		while(gets(str[n]) && strlen(str[n]))
		{
			insert(tHead,str[n]);
			++n;
		}

		for(int i=0;i<n;++i)
		{
			int temp=search(tHead,str[i]);
			strncpy(output,str[i],temp);
			output[temp]='\0';
			printf("%s %s\n",str[i],output);
		}
		if(ncases) printf("\n");
	}

	return 0;
}
