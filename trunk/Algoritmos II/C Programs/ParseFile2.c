#include <stdio.h>
#include <string.h>

int main (void)
{
    FILE *text;
    FILE *fin;
    char i;
    char buffer[50];
    int seguimos;
    
    text = fopen ("archivo.txt","r,t");
    fin  = fopen ("archivo2.txt","w,t");
    
    if (!text) {
               printf ("No se pudo crear");
               getchar ();
               getchar ();
               return 1;
               }
               
    while ((i=fgetc(text)) != EOF) {
          if (i=='$') {
             seguimos = 0;
             while (!seguimos) {
                   i=fgetc(text);
                   if (i == '\n') seguimos = 1;
             }
          }
          fwrite (&i,sizeof(i),1,fin);
        
        
    }

fclose (text);
fclose (fin);
printf ("Todo bien");
getchar();
return 0;
}
