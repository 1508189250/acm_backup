/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2011-09-12 11:10
 # Filename: ZOJ1109 Language of FatMouse.cpp
 # Description : 
 ******************************************************************************/
// ZOJ1109 Language of FatMouse.cpp : Defines the entry point for the console application.
//

// #include "stdafx.h"



#include <stdio.h>
#include <stdlib.h>
#include <memory>
#include <string>
#include <string.h>

using namespace std;

struct node 
{
	char key[50],value[50];
	struct node *left,*right;
}*Head;
void insert(const char *elem,const char *value,struct node * & p)
{
	if( p == NULL)
	{
		p = (struct node*)malloc(sizeof(struct node));
		strcpy(p->key,elem);
		strcpy(p->value,value);
		p->left = p->right = NULL;
		return ;
	}
	if( strcmp(elem,p->key)>0 )
		insert(elem,value,p->right);
	else 
		insert(elem,value,p->left);
}

void find(const char *key,struct node *&p)
{
	if(p==NULL)
		printf("eh\n");
	else if(strcmp(key,p->key)==0)
		printf("%s\n",p->value);
	else if(strcmp(key,p->key)>0)
		find(key,p->right);
	else
		find(key,p->left);
}

int main(void)
{
	char str[100],key[50],value[50];

	while(gets(str) && strlen(str))
	{
		sscanf(str,"%s%s",value,key);
		insert(key,value,Head);
	}

	while(scanf("%s",key)!=EOF)
	{
		find(key,Head);
	} 
	Head=NULL;
	return 0;
}

