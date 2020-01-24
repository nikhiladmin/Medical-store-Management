#include<stdio.h>
#include "addNewMedicine.h"

void medListHeading()
{
    gotoxy(35,3);
    printf("ACCOUNTS");
    gotoxy(34,5);
    for(int i=1; i<=10; i++)
    {
        printf("%c",223);
    }
}
void table()
{
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
    gotoxy(6,6);
    printf("Name");
    gotoxy(21,6);
    printf("Address");
    gotoxy(35,6);
    printf("ExpiryDate");
    gotoxy(52,6);
    printf("Price");
    gotoxy(67,6);
    printf("Package");

    gotoxy(2,8);
    for(int i=1; i<=75; i++)
    {
        printf("%c",196);
    }
}
void product_list()
{
    system("cls");
    box();
    gotoxy(35,2);
    printf("PRODUCT LIST");
    gotoxy(34,3);
    for(int i=1; i<=14; i++)
    {
        printf("%c",223);
    }
    table();
    FILE *fp;
    fp=fopen("Medicine.dat","r");
    if(fp==NULL)
    {
        gotoxy(10,10);
        printf("List not found OR List is Empty...!");
    }
    int i=0;
    while(fscanf(fp,"%s %s %s %f %i %i %s\n",temp.MedName,temp.expiryDate,temp.manufactureDate,&temp.price,&temp.packages,&temp.medInPackage,temp.racks)!=EOF)
    {
        gotoxy(4,9+i);
        printf("%s",temp.MedName);
        gotoxy(35,9+i);
        printf("%s",temp.expiryDate);
        gotoxy(22,9+i);
        printf("%s",temp.racks);
        gotoxy(52,9+i);
        printf("%.2f",temp.price);
        gotoxy(68,9+i);
        printf("%i",temp.packages);
        i++;
    }
    fclose(fp);
    if(getche()){
        main();
    }
}

int accounts_manu()
{
    int input = 0;
    box();
    main_heading();
    gotoxy(20,8);
    printf("1 . Total Products ");
    gotoxy(20,10);
    printf("2 . Dealer Details ");
    gotoxy(20,12);
    printf("3 . Month Selling ");
    gotoxy(20,14);
    printf("4 . Main Manu ");

    do
    {
        gotoxy(20,20);
        printf("Choose Option : ");
        scanf("%d",&input);
        if(!(input>=1&&input<=4))
        {
            gotoxy(20,21);
            printf("Enter number between 1 to 4");
        }
    }
    while(!(input>=1&&input<=4));
    switch(input)
    {
    case 1:
    {
        product_list();
        break;
    }
    case 2:
    {

        break;
    }
    case 3:
    {

        break;
    }
    case 4:
    {
        main();
        break;
    }
    }
    if(input == 4)
        main();
    return input;
}


