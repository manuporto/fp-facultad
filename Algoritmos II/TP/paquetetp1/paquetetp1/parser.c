#include <string.h>
#include <stdio.h>
#include "parser.h"
#define maxlinea 100
//#include "archivo.h"



typedef struct parser{
               char config[3];  //0-sep 1-esc 2-coment
               char* linea;
              // char* campo;//creo q no es necesario
              // int num; //numero campos de la linea, creo q tampoco se necesita
               FILE *log;
               FILE *pars;  
                     }TDA_Parser;
               
int limpiaescape (char* a)

{
  char* punt;
  char c ='/';
  
  while ((punt=strchr(a,c))!=NULL)
  {
   *punt=' ';
   *(++punt)=' '; 
  
  }
   
}

int limpialinea (char* s,char *llimpia)
{
   
   char aux2[maxlinea]; //copia linea
   memcpy(aux2,s,maxlinea);
   char* p;
   p=aux2;
   char aux[maxlinea]="";
   char* punt;
   char* punt2;
   int encontro=0;
   
   p=aux2;
   limpiaescape (p);
   
   char c = '*';
   punt=aux2;
   punt2=aux2;
   while ((punt2!=NULL) && (encontro==0))
   {
   punt2=strchr(++punt2,c);
   if (*(punt2-1)!='/')
   {
    encontro=1;
    strcpy(aux2,strncpy(aux, aux2, (punt2-punt)));
   }
   }
   strcpy(llimpia,aux2);
   //strcpy(s,strncpy(aux, s, (punt2-punt))); 
   getchar();
}




int parserCrear(TDA_Parser* tda,char* arch_par,char* arch_conf,char* arch_log)
{
    char linea[50];    //para guardar la linea tomada de archivo
    FILE *ar;    //archivo de configuracion
    char* punt;  // para moverse dentro de la linea
    char* encontro;   //para definir escape, coment y sep
    
     tda->log=fopen(arch_log,"a+");   //creo logfile
     if(!tda->log) 
         return 0;
     
                   
       
    //Archivo_Abrir(tda->log,arch_log,"w+");
    
     tda->pars=fopen(arch_par,"r");    //abro archiv a parsear
     if(!tda->pars) 
     {
       fputs("parserCrear: Error <ruta de archivo a parsear inexistente>",tda->log); 
       return 0;
     }                 
    //Archivo_Abrir(archconfig,arch_conf,"r");
     ar=fopen(arch_conf,"r");      //abro archiv de conf
     if(!ar) 
     {
       fputs("parserCrear: Error <ruta de archivo de configuracion inexistente>",tda->log); 
       return 0;
     }
     else    
     {
       encontro=NULL;
       while (!feof(ar))         //cargo datos de archiv de conf en tda
       {
             fgets(linea,50,ar);
             if ((encontro=strstr(linea,"SEPARADOR"))!=NULL)
                  {
                       punt=strchr(linea,':');
                       tda->config[0]=*(++punt);
                       //printf("%c",*(++punt));
                  }    
             if ((encontro=strstr(linea,"ESCAPEADOR"))!=NULL)
                  {
                       punt=strchr(linea,':');
                       tda->config[1]=*(++punt);
                       //printf("%c",*(++punt));
                  }     
             if ((encontro=strstr(linea,"COMENTARIOS"))!=NULL)
                  {
                       punt=strchr(linea,':');
                       tda->config[2]=*(++punt);
                       //printf("%c",*(++punt));
                  }    
       }
       fputs("parserCrear: Parser creado exitosamente",tda->log); 
       fclose(ar);
     /*  fclose(tda->log);
       fclose(tda->pars);*/
       
       return 1;
      
       
      } 
        
} 
       
      

int parserDestruir(TDA_Parser* tda)
{
           int i;
           for(i=0;i<3;++i) 
             tda->config[i]=0;
           tda->pars;  
           free(tda->linea);
           tda->linea=NULL;
           fputs("parserDestruir: Parser destruido",tda->log); 
           tda->log=NULL;
           return 1;
}

int parserSiguiente(TDA_Parser* tda)
{
      tda->linea=(char*)malloc(sizeof(maxlinea));
      if (fgets(tda->linea,maxlinea,tda->pars)==NULL)
      {
           fputs("parserSiguiente: Error <No se pudo obetener linea>",tda->log);  
           return 0;
      }
      else
      {
           fputs("parserSiguiente: Linea leida exitosamente",tda->log);  
           return 1;
      }     
}         
         
int parserCantCampos(TDA_Parser*tda)
{
      char* llimpia;
      char lineaaux[maxlinea];
      llimpia=lineaaux;
      limpialinea(tda->linea,llimpia);
}      


int main(){}          
