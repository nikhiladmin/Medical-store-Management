#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <process.h>
#include <assert.h>

//User defined Directive
#include "validation.h"
#include "saleMedicine.h"
#include "addNewMedicine.h"
#include "accounts.h"
#include "Expired.h"



COORD coord = {0, 0};
void gotoxy(int x, int y)
{

    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
char main_manu();
void box();
void main_heading();
void todaySelling();
void frontAnimation();
void about();

int main()
{
    static int i=0;
    if(i==0)
    {
      //  frontAnimation();
        i++;
    }
    system("cls");
    char options = main_manu();
    switch(options)
    {
    case '1':
    {
        system("cls");
        box();
        SaleHeading();
        searchingMed();
        break;
    }
    case '2':
    {
        system("cls");
        box();
        addNewMedHeading();
        newMedForm();
        break;
    }
    case '3':
    {
        system("cls");
        box();
        todaySelling();
        break;
    }
    case '4':
    {
        system("cls");
        box();
        expiredTable();
        ExpiredFile();

        break;
    }
    case '5':
    {
        system("cls");
        box();
        medListHeading();
        accounts_manu();
        break;
    }
    case '6':
    {
        system("cls");
        about();
        break;
    }
    }
    gotoxy(0,36);
    // getch();
    return 0;
}


void todaySelling()
{
    gotoxy(33,3);
    printf("TODAY SELLING");
    gotoxy(32,5);
    for(int i=1; i<=15; i++)
    {
        printf("%c",223);
    }
    gotoxy(2,5);
    for(int i=1; i<=75; i++)
    {
        printf("%c",196);
    }
    for(int j=0; j<4; j++)
    {
        for(int i=0; i<=79; i+=15)
        {
            gotoxy(2+i,5+j);
            printf("%c",179);
        }
    }
    gotoxy(5,6);
    printf("Buyer Name");
    gotoxy(21,6);
    printf("Medicine");
    gotoxy(35,6);
    printf("Quantity");
    gotoxy(52,6);
    printf("Price");
    gotoxy(67,6);
    printf("Date");

    gotoxy(2,8);
    for(int i=1; i<=75; i++)
    {
        printf("%c",196);
    }

    time_t ti = time(NULL);
    struct tm *tm = localtime(&ti);
    assert(strftime(bd.dataTime, sizeof(bd.dataTime), "%c", tm));

    char day[30]="EveryDay/";
    strncat(day,bd.dataTime,8);
    for(int i=11; i<=14; i+=3)
    {
        day[i]='-';
    }

    strcat(day,".DAT");
    FILE *fptoday;
    fptoday=fopen(day,"r");
    if(fptoday==NULL){
            gotoxy(10,10);
        printf("File not found..");
        Sleep(3000);
        main();
    }
    int counter=0;
    while(fscanf(fptoday,"%s  %s  %d  %f  %s\n",bd.BuyerName,bd.medicineName,&bd.quantity,&bd.price,bd.dataTime)!=EOF)
    {
        gotoxy(4,10+counter);
        printf("%s",bd.BuyerName);
        gotoxy(20,10+counter);
        printf("%s",bd.medicineName);
        gotoxy(38,10+counter);
        printf("%d",bd.quantity);
        gotoxy(50,10+counter);
        printf("%.2f",bd.price);
        gotoxy(60,10+counter);
        printf("%s",bd.dataTime);
        counter++;
    }
    fclose(fptoday);
    if(getche()){
        main();
    }
}
char main_manu()
{
    char in;
    box();
    main_heading();
    gotoxy(20,8);
    printf("1 . Sale Medicines ");
    gotoxy(20,10);
    printf("2 . Add new Medicines ");
    gotoxy(20,12);
    printf("3 . Today Selling ");
    gotoxy(20,14);
    printf("4 . Expiry Days Remaining");
    gotoxy(20,16);
    printf("5 . Accounts");
    gotoxy(20,18);
    printf("6 . About");

enter:
    gotoxy(20,22);
    printf("Choose Option : ");
    in=getche();
    if(in=='1'||in=='2'||in=='3'||in=='4'||in=='5'||in=='6')
    {
        return in;
    }
    else
    {
        gotoxy(20,24);
        printf("Wrong Input PRESS [1,2,3,4,5,6]");
        goto enter;
    }
}
void main_heading()
{
    gotoxy(27,3);
    printf("MEDICAL STORE MANAGEMENT");
    gotoxy(27,5);
    for(int i=1; i<=24; i++)
    {
        printf("%c",223);
    }
}
void box()
{
    gotoxy(0,0);
    printf("%c",201);
    for(int i=2; i<=79; i++)
    {
        printf("%c",205);
    }
    printf("%c",187);
    for(int i=1; i<=35; i++)
    {
        gotoxy(0,i);
        printf("%c",186);
    }
    gotoxy(0,36);
    printf("%c",200);
    for(int i=2; i<=79; i++)
    {
        printf("%c",205);
    }
    printf("%c",188);

    for(int i=1; i<=35; i++)
    {
        gotoxy(79,i);
        printf("%c",186);
    }
}

void frontAnimation()
{
    gotoxy(25,8);
//   printf("WELCOME TO MEDICAL STORE");
    for(int i =0; i<25; i++)
    {
        gotoxy(25+i,9);
        printf("%c",219);
        gotoxy(25+i,10);
        printf("%c",219);
        Sleep(i*3);
    }
    for(int i =0; i<13; i++)
    {
        for(int j=0; j<3; j++)
        {
            gotoxy(36+j,4+i);
            printf("%c",219);
            Sleep(i*3);
        }
    }
    gotoxy(25,18);
    char wel[]="WELCOME TO MEDICAL STORE";
    for(int i=0; i<strlen(wel); i++)
    {
        printf("%c",wel[i]);
        Sleep(40);
    }
    Sleep(500);
}
void about(){
box();
gotoxy(34,3);
    char a[]="ABOUT US";
    for(int i=0; i<strlen(a); i++)
    {
        printf("%c",a[i]);
        Sleep(40);
    }

    for(int i=0; i<10; i++)
    {
        gotoxy(42-i,5);
        printf("%c",223);
        Sleep(40);
    }

    gotoxy(9,7);
    printf("My Journey to keep you safe and more comfortable in your work.");
    gotoxy(8,8);
    for(int i=0; i<64; i++)
    {
        printf("%c",196);
    }
    gotoxy(10,10);
    printf("This software allow you to easily manage your Medical store.");
    gotoxy(9,11);
    for(int i=0; i<62; i++)
    {
        printf("%c",196);
    }
    gotoxy(27,13);
    printf("Provide Digital Records");
    gotoxy(26,14);
    for(int i=0; i<26; i++)
    {
        printf("%c",196);
    }
    gotoxy(34,17);
    printf("DEVELOPER");
    gotoxy(33,18);
    for(int i=0; i<11; i++)
    {
        printf("%c",196);
    }
    gotoxy(30,19);
    printf("NIKHIL KUMAR SINGH");

    gotoxy(30,22);
    printf("HOW MAY I HELP YOU");
    gotoxy(29,23);
    for(int i=0; i<20; i++)
    {
        printf("%c",196);
    }
    gotoxy(28,24);
    printf("Contect No - 8349696112");

    gotoxy(34,26);
    printf("THANK YOU");
    gotoxy(33,27);
    for(int i=0; i<11; i++)
    {
        printf("%c",196);
    }

    if(_getch()){
        main();
    }
}
