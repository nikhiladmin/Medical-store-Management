#include "addNewMedicine.h"
#include <stdio.h>
#include <stdlib.h>
struct medicine
{
    char MedName[40];
    char expiryDate[15];
    char manufactureDate[15];
    float price;
    int packages;
    int medInPackage;
    int racks;
};
struct medicine temp;

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
    scanf("%i",&temp.packages);
    gotoxy(50,23);
    scanf("%i",&temp.medInPackage);
    gotoxy(12,26);

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
        fprintf(fp,"%s   %s   %s   %.2f   %i   %i\n",temp.MedName,temp.expiryDate,temp.manufactureDate,temp.price,temp.packages,temp.medInPackage);
        fclose(fp);

        char c;
        gotoxy(12,31);
        printf("More Entries [Y/N]: ");
        gotoxy(33,31);
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


