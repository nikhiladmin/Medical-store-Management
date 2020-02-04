#include "saleMedicine.h"
#include "addNewMedicine.h"
#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <assert.h>

void SaleHeading()
{
    gotoxy(33,3);
    printf("SALE MEDICINE");
    gotoxy(32,5);
    for(int i=1; i<=15; i++)
    {
        printf("%c",223);
    }
}

void searchingMed()
{
    gotoxy(7,7);
    printf("Enter Medicine Name : ");
    char medicine[40];
    scanf("%s",&medicine);
    int i=0;
    strcpy(medicine,strupr(medicine));
    gotoxy(10,5);
    //  printf("%s",medicine);
    FILE *fp;
    fp=fopen("Medicine.DAT","r+");
    if(fp==NULL)
    {
        printf("Data not found ");
    }
    char t[40];
    while(fscanf(fp,"%s %s %s %f %i %s\n",temp.MedName,temp.expiryDate,temp.manufactureDate,&temp.price,&temp.quantity,temp.racks)!=EOF)
    {

        int i=0;
        if(strcmp(strupr(temp.MedName),medicine)== 0)
        {
            strcpy(t,strupr(temp.MedName));
            gotoxy(2,9);
            for(int i=1; i<=75; i++)
            {
                printf("%c",196);
            }
            for(int j=0; j<4; j++)
            {
                for(int i=0; i<=79; i+=15)
                {
                    gotoxy(2+i,9+j);
                    printf("%c",179);
                }
            }
            gotoxy(6,10);
            printf("Name");
            gotoxy(21,10);
            printf("Address");
            gotoxy(35,10);
            printf("ExpiryDate");
            gotoxy(52,10);
            printf("Price");
            gotoxy(67,10);
            printf("Quantity");

            gotoxy(2,12);
            for(int i=1; i<=75; i++)
            {
                printf("%c",196);
            }
            gotoxy(4,14);
            printf("%s",temp.MedName);
            gotoxy(22,14);
            printf("%s",temp.racks);
            gotoxy(35,14);
            printf("%s",temp.expiryDate);
            gotoxy(51,14);
            printf("%.2f",temp.price);
            gotoxy(68,14);
            printf("%i",temp.quantity);
            gotoxy(7,19);
            printf("1 . Sale ");
            gotoxy(7,21);
            printf("2 . Main Menu ");
            gotoxy(7,23);
            printf("Choose option : ");
input:
            gotoxy(24,23);

            char in;
            in=getche();
            switch(in)
            {
            case '1':
            {
                saleMenu();
                break;
            }
            case '2':
            {
                main();
                break;
            }
            default:
            {
                gotoxy(7,24);
                printf("Wrong input ... ");
                goto input;
            }
            }
        }
    }
    if(strcmp(t,medicine)!= 0)
    {
        gotoxy(7,10);
        printf("Medicine Not found.....!");
        gotoxy(7,12);
        printf("Search Again[Y/N] : ");
search:
        gotoxy(27,12);
        char c=getche();
        if(c=='y'||c=='Y')
        {
        system("cls");
        box();
        SaleHeading();
        searchingMed();
        }
        else if(c=='N'||c=='n')
        {
            main();
        }
        else
        {
            gotoxy(50,12);
            printf("Wrong Input !");
            goto search;
        }
    }
    fclose(fp);
}

void bill(char buyerName[40],char MedName[40],int quantity,float price,char datatime[70])
{
    gotoxy(8,12);
    printf("%c",201);
    for(int i=1; i<=60; i++)
    {
        gotoxy(8+i,12);
        printf("%c",205);
    }
    printf("%c",187);
    for(int i=1; i<=18; i++)
    {
        gotoxy(8,12+i);
        printf("%c",186);
    }
    gotoxy(8,30);
    printf("%c",200);
    for(int i=1; i<=60; i++)
    {
        gotoxy(8+i,30);
        printf("%c",205);
    }
    printf("%c",188);
    for(int i=1; i<=17; i++)
    {
        gotoxy(69,12+i);
        printf("%c",186);
    }
    gotoxy(33,14);
    printf("PAYMENT BILL");
    gotoxy(32,15);
    for(int i=1; i<=14; i++)
    {
        printf("%c",196);
    }
    gotoxy(12,17);
    printf("Name : %s",buyerName);
    gotoxy(48,17);
    printf("%s",datatime);
    gotoxy(11,18);
    for(int i=1; i<=56; i++)
    {
        printf("%c",196);
    }
    gotoxy(12,20);
    printf("Medicine    :   %s",MedName);
    gotoxy(12,22);
    printf("Quantity    :   %d",quantity);
    gotoxy(12,24);
    printf("Amount      :   %.2f",price);

}
void saleMenu()
{
    system("cls");
    box();
    gotoxy(36,3);
    printf("SALE");
    gotoxy(35,5);
    for(int i=1; i<=6; i++)
    {
        printf("%c",223);
    }

    gotoxy(8,8);
    printf("Buyer Name : ");
    gotoxy(22,8);
    scanf("%s",&bd.BuyerName);
    gotoxy(8,10);
    printf("Quantity : ");
    gotoxy(20,10);
    scanf("%i",&bd.quantity);
    bd.price=temp.price*bd.quantity;
    strcpy( bd.medicineName,temp.MedName);
    time_t ti = time(NULL);
    struct tm *tm = localtime(&ti);
    assert(strftime(bd.dataTime, sizeof(bd.dataTime), "%c", tm));
    bd.dataTime[8]='-';
    bill(bd.BuyerName,bd.medicineName,bd.quantity,bd.price,bd.dataTime);
Sale:
    gotoxy(12,32);
    printf("Sale Now [Y/N] : ");
    gotoxy(30,32);
    char c=getche();
    if(c=='y'||c=='Y')
    {
        char day[30]="EveryDay/";
        strncat(day,bd.dataTime,8);
        for(int i=11;i<=14;i+=3){
            day[i]='-';
        }
        strcat(day,".DAT");
        FILE *fpw;
        fpw=fopen(day,"a");
        fprintf(fpw,"%s  %s  %d  %.2f  %s\n",bd.BuyerName,bd.medicineName,bd.quantity,bd.price,bd.dataTime);
        fclose(fpw);

        char month[30]="EveryMonth/";
        strncat(month,bd.dataTime,8);
            month[14]='0';
            month[15]='0';
            for(int i=13;i<=16;i+=3){
            month[i]='-';
        }
        strcat(month,".DAT");
        FILE *fpw1;
        fpw1=fopen(month,"a");
        fprintf(fpw1,"%s  %s  %d  %.2f  %s\n",bd.BuyerName,bd.medicineName,bd.quantity,bd.price,bd.dataTime);
        fclose(fpw1);
        gotoxy(12,34);
        printf("Sale Successfully Completed ....");
        Sleep(1000);
        main();
    }
    else if(c=='N'||c=='n')
    {
        main();
    }
    else
    {
        gotoxy(50,32);
        printf("Wrong Input !");
        goto Sale;
    }

}

