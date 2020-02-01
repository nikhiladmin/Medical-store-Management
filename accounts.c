#include<stdio.h>
#include<assert.h>
#include "addNewMedicine.h"
#include "saleMedicine.h"

struct dealer{
 char name[40];
 char number[11];
 char email[20];
 char address[40]
};
struct dealer temp1;

void medListHeading(){
    gotoxy(35,3);
    printf("ACCOUNTS");
    gotoxy(34,5);
    for(int i=1; i<=10; i++)
    {
        printf("%c",223);
    }
}
void medicinetable(){
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
    printf("Quantity");

    gotoxy(2,8);
    for(int i=1; i<=75; i++)
    {
        printf("%c",196);
    }
}
void product_list(){
    system("cls");
    box();
    gotoxy(35,2);
    printf("PRODUCT LIST");
    gotoxy(34,3);
    for(int i=1; i<=14; i++)
    {
        printf("%c",223);
    }
    medicinetable();
    FILE *fp;
    fp=fopen("Medicine.DAT","r");
    if(fp==NULL)
    {
        gotoxy(10,10);
        printf("List not found OR List is Empty...!");
    }
    int i=0;
    while(fscanf(fp,"%s %s %s %f %i %s\n",temp.MedName,temp.expiryDate,temp.manufactureDate,&temp.price,&temp.quantity,temp.racks)!=EOF)
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
        printf("%i",temp.quantity);
        i++;
    }
    fclose(fp);
    if(getche()){
        main();
    }
}
int accounts_manu(){
    char input;
    box();
    main_heading();
    gotoxy(20,8);
    printf("1 . Total Products ");
    gotoxy(20,10);
    printf("2 . Dealer Details ");
    gotoxy(20,12);
    printf("3 . Add Dealer ");
    gotoxy(20,14);
    printf("4 . Month Selling");
    gotoxy(20,16);
    printf("5 . Main Manu");

       enter:
    gotoxy(20,20);
    printf("Choose Option : ");
    input=getche();
    if(input=='1'||input=='2'||input=='3'||input=='4'||input=='5')
    {
        switch(input)
    {
    case '1':
    {
        product_list();
        break;
    }
    case '2':
    {
        dealerDetails();
        break;
    }
    case '3':
    {
        system("cls");
        box();
        addDealer();
        break;
    }
    case '4':
    {
        system("cls");
        box();
        monthSaling();
        break;
    }
    case '5':
    {
        main();
        break;
    }
    }
    }
    else
    {
        gotoxy(20,21);
        printf("Wrong Input PRESS [1,2,3,4,5]");
        goto enter;
    }

    if(input == '4')
        main();
    return input;
}
void addDealer(){

    gotoxy(33,3);
    printf("ADD NEW MEDICINES");
    gotoxy(32,5);
    for(int i=1; i<=19; i++)
    {
        printf("%c",223);
    }

    gotoxy(12,8);
    printf("Name : ");
    gotoxy(12,11);
    printf("Phone Number : ");
    gotoxy(12,14);
    printf("Email-ID : ");
    gotoxy(12,17);
    printf("Address : ");

    gotoxy(20,8);
    scanf("%s",&temp1.name);
    gotoxy(28,11);
    scanf("%s",&temp1.number);
    gotoxy(24,14);
    scanf("%s",&temp1.email);
    gotoxy(23,17);
    scanf("%s",&temp1.address);
    gotoxy(12,20);

    printf("1. Save      2. Cancel");
    int inp;
    gotoxy(12,22);
    printf("Choose Option : ");
    gotoxy(29,22);
    scanf("%i",&inp);
    if(inp==1)
    {
        FILE *fp;
        fp=fopen("Dealer.DAT","a");
        if(fp==NULL)
        {
            printf("Data not added ...");
        }
        fprintf(fp,"%s %s %s %s\n",temp1.name,temp1.number,temp1.email,temp1.address);
        fclose(fp);

        char c="y";
        gotoxy(12,24);
        printf("More Entries [Y/N]: ");
        gotoxy(33,24);
        fflush(stdin);
        scanf("%c",&c);

        if(c=='Y'||c=='y')
        {
            system("cls");
            box();
            addDealer();
        }
        else
        {
            system("cls");
            accounts_manu();
        }
    }
    else if(inp==2)
    {
        main();
    }

}
void dealerDetails(){
     system("cls");
    box();
    gotoxy(35,2);
    printf("DEALER LIST");
    gotoxy(34,3);
    for(int i=1; i<=14; i++)
    {
        printf("%c",223);
    }
    dealerTable();
    FILE *fp;
    fp=fopen("Dealer.dat","r");
    if(fp==NULL)
    {
        gotoxy(10,10);
        printf("List not found OR List is Empty...!");
    }
    int i=0;
    while(fscanf(fp,"%s %s %s %s\n",temp1.name,temp1.number,temp1.email,temp1.address)!=EOF)
    {
        gotoxy(6,9+i);
        printf("%s",temp1.name);
        gotoxy(21,9+i);
        printf("%s",temp1.number);
        gotoxy(34,9+i);
        printf("%s",temp1.email);
        gotoxy(55,9+i);
        printf("%s",temp1.address);
        i++;
    }
  fclose(fp);
    if(getche()){
        main();
    }
}
void dealerTable(){
     gotoxy(2,5);
    for(int i=1; i<=75; i++)
    {
        printf("%c",196);
    }
    for(int j=0; j<4; j++)
    {
        for(int i=0; i<=48; i+=16)
        {
            gotoxy(2+i,5+j);
            printf("%c",179);
        }
    }
    for(int j=0; j<4; j++){
        gotoxy(77,5+j);
        printf("%c",179);

    }
    gotoxy(5,6);
    printf("Dealer Name");
    gotoxy(23,6);
    printf("Phone No.");
    gotoxy(38,6);
    printf("Email-ID");
    gotoxy(60,6);
    printf("Address");

     gotoxy(2,8);
    for(int i=1; i<=75; i++)
    {
        printf("%c",196);
    }

}
void monthSaling(){
    gotoxy(33,3);
    printf("MONTH SELLING");
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

    char month[30]="EveryMonth/";
     strncat(month,bd.dataTime,8);
            month[14]='0';
            month[15]='0';
            for(int i=13;i<=16;i+=3){
            month[i]='-';
        }
        strcat(month,".DAT");
    FILE *fpmonth;
    fpmonth=fopen(month,"r");
    if(fpmonth==NULL){
            gotoxy(10,10);
        printf("File not found...");
        Sleep(3000);
        main();
    }
    int counter=0;
    while(fscanf(fpmonth,"%s  %s  %d  %f  %s\n",bd.BuyerName,bd.medicineName,&bd.quantity,&bd.price,bd.dataTime)!=EOF)
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
    fclose(fpmonth);
    if(getche()){
        main();
    }

}
