#ifndef ADMINLIST_H_INCLUDED
#define ADMINLIST_H_INCLUDED
#endif // ADMINLIST_H_INCLUDED

#include<stdlib.h>
#include<stdio.h>
#include<string.h>

typedef struct Adminnode
{
    char username[100];
	char password[100];
    struct Adminnode * Next;

}AdminNode;



typedef struct AdminList
{
    AdminNode * Head;
    int Size;
}AdminList;


void AdminList_Init(AdminList *pl);
void AdminList_Insert(AdminList *pl, char username[], char password[]);



void AdminList_Init(AdminList *pl)
{
    pl->Head = NULL;
    pl->Size = 0;
}

void AdminList_Insert(AdminList *pl, char username[], char password[])
{
    /*create new node and intialize its data*/
    AdminNode* pn = (AdminNode *)malloc(sizeof(AdminNode));
    strcpy(pn->username, username);
    strcpy(pn->password, password);

    pn->Next = pl->Head;
    pl->Head = pn;
    /*increasing the size of the list*/
    pl->Size++;
}


