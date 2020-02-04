#ifndef ACCOUNTS_H_INCLUDED
#define ACCOUNTS_H_INCLUDED
void medListHeading();
int accounts_manu();
void product_list();
void medicinetable();
void addDealer();
void dealerDetails();
void dealerTable();
void monthSaling();
struct dealer{
 char name[41];
 char number[11];
 char email[31];
 char address[40]
};
struct dealer temp1;


#endif // ACCOUNTS_H_INCLUDED
