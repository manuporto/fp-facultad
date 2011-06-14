#include <stdio.h>
#include <string.h>

int main()
{
   int i; 
   char s[100] = "Hola, /,amigos/, como /,estan/  trolos*oracion/  idiota";
   char aux[100]="";
   char* punt;
   char* punt2;
   char c = '*';
   punt=s;
   

   c='/';
  while ((punt2=strchr(s,c))!=NULL)
  {
  /* for(i=0;i<100;i++)
                      aux[i]=0; */
    
   *punt2=' ';
   *(++punt2)=' '; 
   /*strncpy(aux, s, (punt2-punt));
     
   strcat(aux,(punt2+2));
   strcpy(s,aux);*/
  
  }
   
   printf("FINAL=%s\n",s);
   getchar();
   return 0;
}



