#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

/* struct medicine
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
*/
//User defined Directive
#include "saleMedicine.h"
#include "addNewMedicine.h"
#include "accounts.h"



COORD coord = {0, 0};
void gotoxy(int x, int y){

 COORD coord;
 coord.X = x;
 coord.Y = y;
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
int main_manu();
void box();
void main_heading();
void todaySelling();


int main()
{
    system("cls");
   int options = main_manu();
   switch(options){
   case 1:{
    system("cls");
    box();
    SaleHeading();
    searchingMed();
    break;
   }
   case 2:{
    system("cls");
    box();
    addNewMedHeading();
    newMedForm();
    break;
   }
   case 3:{
    system("cls");
    box();
    todaySelling();
    break;
   }
   case 4:{
    system("cls");
    box();
    break;
   }
   case 5:{
    system("cls");
    box();
    medListHeading();
    accounts_manu();
    break;
   }
   case 6:{
    break;
   }
   }
    gotoxy(0,36);
   // getch();
    return 0;
}


void todaySelling(){
    gotoxy(33,3);
    printf("TODAY SELLING");
    gotoxy(32,5);
    for(int i=1;i<=15;i++){
        printf("%c",223);
    }

}
int main_manu(){
     int input = 0;
   box();
   main_heading();
    gotoxy(20,8);
   printf("1 . Sale Medicines ");
   gotoxy(20,10);
   printf("2 . Add new Medicines ");
   gotoxy(20,12);
   printf("3 . Today Selling ");
   gotoxy(20,14);
   printf("4 . Expired Medicine(1 month) ");
   gotoxy(20,16);
   printf("5 . Accounts");
   gotoxy(20,18);
   printf("6 . About");

   do{
    gotoxy(20,22);
    printf("Choose Option : ");
    scanf("%d",&input);
    if(!(input>=1&&input<=5)){
        gotoxy(20,23);
        printf("Enter number between 1 to 5");
    }
   }while(!(input>=1&&input<=5));
   return input;
}
void main_heading(){
   gotoxy(27,3);
   printf("MEDICAL STORE MANAGEMENT");
    gotoxy(27,5);
    for(int i=1;i<=24;i++){
        printf("%c",223);
    }
}
void box(){
    gotoxy(0,0);
 printf("%c",201);
    for(int i=2;i<=79;i++)
	{
		printf("%c",205);
	}
    printf("%c",187);
	for(int i=1;i<=35;i++){
        gotoxy(0,i);
        printf("%c",186);
	}
	gotoxy(0,36);
    printf("%c",200);
     for(int i=2;i<=79;i++)
	{
		printf("%c",205);
	}
	printf("%c",188);

	for(int i=1;i<=35;i++)
	{
	    gotoxy(79,i);
		printf("%c",186);
	}
}
