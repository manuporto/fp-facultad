#include<stdio.h>

int suma (int*a);
int resta(int*a);

int resta(int*a)
{
            *a=*a-3;
}


int suma(int*a)
{
           *a=*a+1;
           resta(a);
}

main ()
{
     int a;
     int* pint;
     pint=&a;
     
     printf("ingrese un valor para a:");
     scanf("%d",&a);
     
     
     printf("puntero pint=%d\n",*pint);
     
     suma(pint);
     printf("despues de suma:\n");
     printf("puntero pint=%d\n",*pint);
     /*resta(pint);
     printf("despues de resta:\n");
     printf("puntero pint=%d\n",*pint);*/
     system("PAUSE");
     
}


