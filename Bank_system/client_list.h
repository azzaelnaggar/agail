#ifndef CLIENT_LIST_H_INCLUDED
#define CLIENT_LIST_H_INCLUDED

typedef struct Account
{
    char name[80];
    char Address[80];
    long long int ID; //long long int is up to 19 digits
    int Age;
    long long int GD_ID;
    long long int AccountID;
    char Status[10];
    long long int Balance;
    long long int Password;

}ClientAcc;


typedef struct clientnode{ //each node contains a structure with all client data and a pointer to next node
    ClientAcc  Data;
    struct listnode * Next;

}ClientNode;

typedef struct Linkedlist
{
    ClientNode * Head;
    int Size;
}ClientList;


void ClientList_Init(ClientList *p);
void ClientList_Insert(ClientList *p, ClientAcc clientacc);


// init head pointer to null
void ClientList_Init(ClientList *p)
{
    p->Head = NULL;
    p->Size = 0;
}



void ClientList_Insert(ClientList *p, ClientAcc clientacc){
    //create new node and add clientacc struct to Data
    ClientNode* pn = (ClientNode *)malloc(sizeof(ClientNode));
    pn->Data = clientacc;

    pn->Next = p->Head; //new node points to what head points to
    p->Head = pn; //head then points to new node to be top
    // increase number of clients
    p->Size++;
}





#endif // CLIENT_LIST_H_INCLUDED
