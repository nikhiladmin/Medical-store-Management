#include "saleMedicine.h"
#include "addNewMedicine.h"
#include <ctype.h>
#include <string.h>
#include <stdio.h>


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
    while(i<strlen(medicine))
    {
        if(97<=medicine[i]&&medicine[i]<=122)
        {
            medicine[i]=toupper(medicine[i]);
        }
        i++;
    }

    FILE *fp;
    fp=fopen("Medicine.DAT","r");
    if(fp==NULL)
    {
        printf("Data not found ");
    }
    while(fscanf(fp,"%s %s %s %f %i %i\n",temp.MedName,temp.expiryDate,temp.manufactureDate,&temp.price,&temp.packages,&temp.medInPackage)!=EOF)
    {
        char t[40];
        strcpy(t,temp.MedName);

        int i=0;
        while(i<strlen(t))
        {
            if(97<=t[i]&&t[i]<=122)
            {
                t[i]=toupper(t[i]);
            }
            i++;
        }

        if(strcmp(t,medicine))
        {
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
            printf("Package");

            gotoxy(2,12);
            for(int i=1; i<=75; i++)
            {
                printf("%c",196);
            }
            gotoxy(4,14);
            printf("%s",temp.MedName);
            gotoxy(33,14);
            printf("%s",temp.expiryDate);
            //gotoxy(18,8+i);
            // printf("%s",temp.manufactureDate);
            gotoxy(49,14);
            printf("%.2f",temp.price);
            gotoxy(65,14);
            printf("%i",temp.packages);
        }

    }
    fclose(fp);
}

