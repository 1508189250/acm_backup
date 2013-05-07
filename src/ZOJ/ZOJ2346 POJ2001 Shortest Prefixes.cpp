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

#define KINDNUM 26  //��ĸ���ֱ࣬�Ӿ�
int arrNum;

struct TrieNode//���Ľ��ṹ
{
	int count;//������ӱ����ڱ����м�¼�������ý���γɵ��ַ������ֵĴ������ڲ�ͬ���пɼ�¼��ͬ�����ݡ�
	TrieNode *next[KINDNUM];//ָ����ӽ�㣬ע��˴��� ָ������
}trieArray[40000];

void insert(TrieNode *&root,char *word)//����rootΪ���������в��봮word
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
		if(location->next[branch]) location->next[branch]->count++;//������ַ����ڣ���������1
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

int search(TrieNode *&root,char *word)//���ң����������
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
