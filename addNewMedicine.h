#ifndef ADD_NEW_MEDICINE_H_INCLUDED
#define ADD_NEW_MEDICINE_H_INCLUDED

void addNewMedHeading();
void h();
void newMedForm();
void address();
struct medicine
{
    char MedName[40];
    char expiryDate[15];
    char manufactureDate[15];
    float price;
    int packages;
    int medInPackage;
    char racks[5];
};
struct medicine temp;
#endif // ADD_NEW_MEDICINE_H_INCLUDED
