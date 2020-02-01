#ifndef SALEMEDICINE_H_INCLUDED
#define SALEMEDICINE_H_INCLUDED
void SaleHeading();
void searchingMed();
void saleMenu();
void bill(char buyerName[40],char MedName[40],int quantity,float price,char datatime[70]);
struct buyerDetail
{
    char BuyerName[40];
    char medicineName[40];
    int quantity;
    float price;
    char dataTime[70];
};
struct buyerDetail bd;
#endif // SALEMEDICINE_H_INCLUDED
