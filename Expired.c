#include "Expired.h"
#include "addNewMedicine.h"
#include <time.h>
#include <stdio.h>
#include <string.h>
int leapYear(int in)
{
    for(int i=1; i<in-1; i++)
    {
        if(i%400==0)
        {
            //leap Year
            return 1;
        }
        else if(i%4==0&&i% 100 !=0)
        {
            return 1;
            //leap Year
        }
        else
        {
            return 0;
            // non leap year
        }
    }
}
int daysCount(int dd,int mm,int yy)
{
    int n2=0;
    for(int i=1; i<yy-1; i++)
    {
        if(leapYear(i)==1)
        {
            n2+=366;
        }
        else
        {
            n2+=365;
        }
    }
    int ly[12]= {31,29,31,30,31,30,31,31,30,31,30,31};
    int nly[12]= {31,28,31,30,31,30,31,31,30,31,30,31};
    if(leapYear(yy)==1)
    {
        for(int i=0; i<mm-1; i++)
        {
            n2 += ly[i];
        }
        n2 += dd;
    }
    else
    {
        for(int i=0; i<mm-1; i++)
        {
            n2 += nly[i];
        }
        n2+=dd;
    }
    return n2;
}

int days(int d1,int m1, int y1,int d2,int m2,int y2)
{

    int d=daysCount(d2,m2,y2)-daysCount(d1,m1,y1);

    return d;
}

void expiredTable(){
    gotoxy(26,3);
    printf("EXPIRY REMAINING DAYS");
    gotoxy(25,5);
    for(int i=1; i<=23; i++)
    {
        printf("%c",223);
    }
     gotoxy(2,6);
    for(int i=1; i<=75; i++)
    {
        printf("%c",196);
    }

    for(int j=0; j<4; j++)
    {
        for(int i=0; i<=60; i+=12)
        {
            gotoxy(17+i,6+j);
            printf("%c",179);
        }
    }
    for(int j=0; j<4; j++)
    {
            gotoxy(2,6+j);
            printf("%c",179);
    }

    gotoxy(8,7);
    printf("Name");
    gotoxy(20,7);
    printf("Address");
    gotoxy(31,7);
    printf("ExpiryDate");
    gotoxy(45,7);
    printf("Price");
    gotoxy(55,7);
    printf("Quantity");
    gotoxy(69,7);
    printf("Days");

    gotoxy(2,9);
    for(int i=1; i<=75; i++)
    {
        printf("%c",196);
    }


}
void ExpiredFile()
{
    int daysRemaining;
    char date1[12];
    int day2, month2, year2;
    int day1, month1, year1;
    char m1[3],y1[5];
    int lineCount=0;
    //Today Date
    time_t now;
    time(&now);
    struct tm *local = localtime(&now);
    day2 = local->tm_mday;        	// get day of month (1 to 31)
    month2 = local->tm_mon + 1;   	// get month of year (0 to 11)
    year2 = local->tm_year + 1900;   // get year since 1900

    FILE *fp;
    FILE *fpex;
    fp=fopen("Medicine.DAT","r");
    fpex=fopen("Expired.DAT","w");
    if(fp==NULL||fpex==NULL)
    {
        gotoxy(10,10);
        printf("List not found OR List is Empty...!");
        Sleep(3000);
        main();
    }
    int i=0;
    while(fscanf(fp,"%s %s %s %f %i %s\n",temp.MedName,temp.expiryDate,temp.manufactureDate,&temp.price,&temp.quantity,temp.racks)!=EOF)
    {
        strncpy(date1,temp.expiryDate,10);

        day1=atoi(date1);
        for(int i=0; i<2; i++)
        {
            m1[i]=date1[i+3];
        }
        month1=atoi(m1);
        for(int i=0; i<4; i++)
        {
            y1[i]=date1[i+6];
        }
        year1=atoi(y1);
        daysRemaining=days(day2,month2,year2,day1,month1,year1);
        if(daysRemaining<0){
            daysRemaining=0;
        }
        fprintf(fpex,"%s %s %d %f %d %s\n",temp.MedName,temp.expiryDate,daysRemaining,temp.price,temp.quantity,temp.racks);
    lineCount++;
    }
    fclose(fpex);
    fclose(fp);
//
    FILE *fpexp;
    //FILE *fpsort;
    fpexp = fopen("Expired.DAT","r");
//    fpsort =fopen("temp.DAT","r");
    int counter=0;
    while(fscanf(fpexp,"%s %s %d %f %d %s\n",temp.MedName,temp.expiryDate,&daysRemaining,&temp.price,&temp.quantity,temp.racks)!=EOF){
        gotoxy(7,10+counter);
        printf("%s",temp.MedName);
        gotoxy(20,10+counter);
        printf("%s",temp.racks);
        gotoxy(30,10+counter);
        printf("%s",temp.expiryDate);
        gotoxy(45,10+counter);
        printf("%.2f",temp.price);
        gotoxy(57,10+counter);
        printf("%d",temp.quantity);
        gotoxy(70,10+counter);
        printf("%d",daysRemaining);
        counter++;
    }
    if(getche())
    {
        main();
    }
}
