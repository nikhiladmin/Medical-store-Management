#ifndef EXPIRED_H_INCLUDED
#define EXPIRED_H_INCLUDED

int leapYear(int in);
int daysCount(int dd,int mm,int yy);
int days();
void expiredTable();
struct ExpiredDate
{
    char MedName[40];
    char expiryDate[15];
    int daysRemaining;
    float price;
    int quantity;
    char racks[5];
};
struct ExpiredDate ex;

#endif // EXPIRED_H_INCLUDED
