#include "validation.h"

void nameValidation(char a[])
{
    int x=0;
    while((a[x]=_getch())!='\r'&&x<40)
    {
        if((a[x]>=65&&a[x]<=90)||(a[x]>=97&&a[x]<=122)||a[x]==' ')
        {
            printf("%c",a[x]);
            x++;
        }
        else if(a[x]==8 && x>0)
		{
			printf("%c%c%c",8,32,8);
			x--;
		}
    }
    a[x]='\0';
}
void dateValidation(char a[])
{
    int x=0;
    while(x<10)
    {
        a[x]=_getch();
        if((a[x]>=48&&a[x]<=57))
        {
            printf("%c",a[x]);
            x++;
        }
        else if(a[x]==8 && x>0)
		{
			printf("%c%c%c",8,32,8);
			x--;
		}

         if(x==2||x==5)
        {
            a[x]='/';
            printf("%c",a[x]);
            x++;
        }
    }
}

void numberValidation(char a[]){
    int x=0;
    while(x<10){
        a[x]=_getch();
        if((a[x]>=48&&a[x]<=57))
        {
            printf("%c",a[x]);
            x++;
        }
        else if(a[x]==8 && x>0)
		{
			printf("%c%c%c",8,32,8);
			x--;
		}
    }
}

void addressValidation(char a[]){
    int x=0;
     while((a[x]=_getch())!='\r'&&x<30)
    {
        if((a[x]>=65&&a[x]<=90)||(a[x]>=97&&a[x]<=122)||a[x]==' '||a[x]==','||a[x]=='-'||(a[x]>=48&&a[x]<=57))
        {
            if(a[x]==' '){
                a[x]=',';
            }
            printf("%c",a[x]);
            x++;
        }
        else if(a[x]==8 && x>0)
		{
			printf("%c%c%c",8,32,8);
			x--;
		}
    }
    a[x]='\0';

}
