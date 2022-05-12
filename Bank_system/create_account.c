
/********************************************************************************************
    AUTHORS:        azza ali
    DATE:           May 11, 2022
    VER:            1.0
    DESCRIPTION:    create new account :
                    In this Feature you will be asked to enter the following parameters
                    - Full Name
                    - Full Address
                    - Age
                    - National ID
                    - Guardian National ID
                    (If Age < 21 you will be asked automatically for Guardian National ID)
                    - Balance
                    Note that (Password, and Bank account ID will be generated automatically)
                    Note also that the account status will be active once it is created                                                           *
**********************************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "AdminList.h"
#include "client_list.h"

ClientAcc CreateBankAccount();
void AccountsInit();
void AdminInit();
void Insert_Name( ClientAcc* Account);
void Insert_Address(ClientAcc* Account);
void Insert_ID(long long int* NationalID);
void Insert_Age(ClientAcc* Account);
void Account_ID(ClientAcc* Account);
void Account_Status(ClientAcc* Account,int closed);
void Balance(ClientAcc* Account);
void Password(ClientAcc* Account);

ClientList list;
AdminList admin_list;

void main()
{
    printf("Welcome\n");
    ClientAcc acc = CreateBankAccount();
}




ClientAcc CreateBankAccount()
{
    ClientAcc acc;
    int count=0;
    Insert_Name(&acc);
    Insert_Address(&acc);
    Insert_ID(&acc.ID);
    Insert_Age(&acc);
    Create_BankAccount(&acc);
    printf("\nYour Bank account ID: %lld ", acc.AccountID);
    Account_Status(&acc,0);
    Balance(&acc);
    Password(&acc);
    printf("\nnYour Password: %lld ", acc.Password);
    return acc;
}

/** 1. Name **/
void Insert_Name( ClientAcc* Account)
{
    printf("Enter Your Full name: ");
    fgets(Account->name , sizeof(Account->name), stdin);
}

/** 2. Address **/
void Insert_Address(ClientAcc* Account)
{
    printf("Enter Your Address: ");
    fgets(Account->Address, sizeof(Account->Address), stdin);
}

/** 3. National ID **/
void Insert_ID(long long int* ID)
{
    int count=0;
    //must be 14 digits
    while (count != 14)
    {
        count=0;
        printf("\nEnter A valid National ID that consists of 14 digits: ");
        //to do solve issue of entering a char
        scanf("%lld", ID);
       long long int n = *ID;
        do {
            n /= 10;
            ++count;
        } while (n != 0);
    }
}

/** 4. Age **/
void Insert_Age(ClientAcc* Account)
{
    printf("Enter Age: ");
    scanf("%d", &Account->Age);
    if (Account->Age <21)
    {
        printf("\nEnter Guardian ID");
        Insert_ID(&Account->GD_ID);
    }
    else
    {
        Account->GD_ID=0;  //age >21 havenot GuardianNationalID
    }
}

/** 5. ClientAcc ID **/
void Create_BankAccount(ClientAcc* Account)
{
    do
     {
        srand(time(0));//seed point
        Account->AccountID = rand() % 10;
     }  while(Account->AccountID == 0);

    for(int i = 1; i < 10; i++)
     {
         Account->AccountID *= 10;
         Account->AccountID += rand() % 10;
     }

}

/** 6. ClientAcc Status **/
void Account_Status(ClientAcc* Account,int st)
{
    if (st ==1)
    {
        strcpy(Account->Status, "Restricted");
    }
    else
    {
        strcpy(Account->Status, "Active");
    }

}

/** 7. ClientAcc Balance **/
void Balance(ClientAcc* Account)
{
    printf("\nAdd Account Balance: ");
    scanf("%lld", &Account->Balance);
}
void Password(ClientAcc* Account)
{
    // 10 digit Random Password
     do
     {
         Account->Password = rand() % 10;
     } while(Account->Password == 0);

     for(int i = 1; i < 10; i++)
     {
         Account->Password *= 10;
         Account->Password += rand() % 10;
     }

}

/** Initiate Clients Accounts **/

void AccountsInit()
{
    ClientAcc client_1, client_2;
    //client 1
    strcpy(client_1.name ,"Azza Ali Omar");
    strcpy(client_1.Address ,"2 m st");
    client_1.ID=32148751239452;
    client_1.Age = 24;
    client_1.GD_ID = 0;
    client_1.AccountID=4128741003;
    strcpy(client_1.Status ,"Active");
    client_1.Balance=500000;
    client_1.Password=9457463210;
    //client 2
    strcpy(client_2.name ,"Rahma Farag");
    strcpy(client_2.Address ,"6 d st");
    client_2.ID=12345678912340;
    client_2.Age = 23;
    client_2.GD_ID = 0;
    client_2.AccountID=1234500891;
    strcpy(client_2.Status ,"Active");
    client_2.Balance=800000;
    client_2.Password=1023450089;

    ClientList_Init(&list);
    // insert clients to the list
    ClientList_Insert(&list,client_1);
    ClientList_Insert(&list,client_2);

}

/** Initiate Admins Accounts **/
void AdminAccInit()
{
    char username[100];
	char password[100];
    //admin 1
    strcpy(username, "doha yehia");
    strcpy(password, "123456789");
    //admin list
    AdminList_Init(&admin_list);
    AdminList_Insert(&admin_list, username, password);
}
