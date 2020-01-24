#include "addNewMedicine.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


void addNewMedHeading()
{
    gotoxy(33,3);
    printf("ADD NEW MEDICINES");
    gotoxy(32,5);
    for(int i=1; i<=19; i++)
    {
        printf("%c",223);
    }
}

void newMedForm(                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          )
{
    gotoxy(12,8);
    printf("Enter Name : ");
    gotoxy(12,11);
    printf("Enter Expiry Date : ");
    gotoxy(12,14);
    printf("Enter Manufacturing Date : ");
    gotoxy(12,17);
    printf("Enter Price : ");
    gotoxy(12,20);
    printf("Enter Number of Package : ");
    gotoxy(12,23);
    printf("Enter Number of Medicine in Package : ");

    gotoxy(26,8);
    scanf("%s",&temp.MedName);
    gotoxy(33,11);
    scanf("%s",&temp.expiryDate);
    gotoxy(40,14);
    scanf("%s",&temp.manufactureDate);
    gotoxy(27,17);
    scanf("%f",&temp.price);
    gotoxy(39,20);
   // fflush(stdin);
    scanf("%d",&temp.packages);
    gotoxy(50,23);
    scanf("%d",&temp.medInPackage);
    gotoxy(12,26);
    address(temp.MedName);
   // printf("%s",temp.racks);
    printf("1. Save      2. Cancel");
    int inp;
    gotoxy(12,29);
    printf("Choose Option : ");
    gotoxy(29,29);
    scanf("%i",&inp);
    if(inp==1)
    {
        FILE *fp;
        fp=fopen("Medicine.DAT","a");
        if(fp==NULL)
        {
            printf("Data not added ...");
        }
        fprintf(fp,"%s %s %s %f %d %d %s\n",temp.MedName,temp.expiryDate,temp.manufactureDate,temp.price,temp.packages,temp.medInPackage,temp.racks);
        fclose(fp);

        char c="y";
        gotoxy(12,31);
        printf("More Entries [Y/N]: ");
        gotoxy(33,31);
        fflush(stdin);
        scanf("%c",&c);

        if(c=='Y'||c=='y')
        {
            system("cls");
            box();
            addNewMedHeading();
            newMedForm();
        }
        else
        {
            main();
        }
    }
    else if(inp==2)
    {
        main();
    }

}

void address(char medicineName[40]){
    char pos=medicineName[0];
    pos=toupper(pos);
    char random = (char)(rand()%5+49);
    char racks[5];
    if(pos>=65&&pos<=72||pos>=97&&pos<=104){
         strcpy(racks,"R");
         strncat(racks,&pos,1);
         strcat(racks,"-");
         strncat(racks,&random,1);
    }else if(pos>=73&&pos<=81||pos>=105&&pos<=113){
         strcpy(racks,"B");
         strncat(racks,&pos,1);
         strcat(racks,"-");
         strncat(racks,&random,1);
    }else if(pos>=82&&pos<=90||pos>=114&&pos<=122){
          strcpy(racks,"L");
         strncat(racks,&pos,1);
         strcat(racks,"-");
         strncat(racks,&random,1);
  }

   strcpy(temp.racks,racks);
}


