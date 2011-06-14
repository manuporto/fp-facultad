#include <stdio.h>
#include <string.h>

int main (void)
{
    FILE *text;
    int i;
    char buffer[50];
    
    text = fopen ("archivo.txt","w,t");
    
    if (!text) {
               printf ("No se pudo crear");
               getchar ();
               getchar ();
               return 1;
               }
               
    for (i=0;i<50;i++) {
        sprintf (buffer,"Esta es la línea %d \n",i+1);
        fwrite (buffer, strlen (buffer),1,text);
    }

fclose (text);
return 0;
printf ("No se que paso");
getchar();
}
