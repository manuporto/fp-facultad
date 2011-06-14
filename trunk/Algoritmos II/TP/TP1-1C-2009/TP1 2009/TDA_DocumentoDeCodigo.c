/******************************************************************************
 *                   Algoritmos y Programación II - 75.41                     *
 *                        Cátedra: Lic. Gustavo Carolo                        *
 *            Facultad de Ingeniería - Universidad de Buenos Aires            *
 ******************************************************************************/

/* TDA Documento de Codigo
 * Archivo: TDA_DocumentoDeCodigo.c
 * version: 1.0.0
 */
#include "memdbg.h"

#include "TDA_DocumentoDeCodigo.h"


/* Tipo de dato */

typedef struct SUBTAG{
        char* nombre; /* apunta al nombre principal de subtag */
        char* descrip; /*Descripción del subtag */
}SUBTAG;



/*----------------------------------------------------------------------------*/

/* Definicion e implementacion de funciones Auxiliares */
/*-----------------------------------------------------*/

/**
@function
@name RemoveLeadingSpaces
@description Recibe una palabra a la que si tiene espacios iniciales se los quita y la devuelve
@return char*
@param palabra:char*
@author Ribotta-Zignego
@see -
*/

char* RemoveLeadingSpaces( char *palabra )
{
    char* temp = palabra;
    int largo = strlen(temp);

    while ((*temp == ' ') || (*temp == '\t')) temp++;
    for (largo; largo && temp[largo-1] == ' '; largo--)
    temp[largo-1] = '\0';

    strcpy(palabra, temp);
    return palabra;
}

/*
Recibe un string y una posición dentro de ese string, y devuelve la cantidad
de letras desde ahi hasta un espacio si es palabra, o hasta fin de linea si
quiere una oración.
*/
/**
@function
@name wordLen
@description recibe un string y una posición dentro de ese string, y devuelve la cant de letras desde ahi hasta un espacio si es palabra o hasta fin de línea si es una oración
@return int
@param stg:char*
@param comiezo:int
@param esPalabra:int
@author Ribotta-Zignego
@see -
*/

int wordLen (char *stg, int comienzo, int esPalabra)
{
    int i=comienzo;
    int len=0, salir=0;

    while (!salir){

        if (esPalabra){
            if (*(stg+i) == ' ' || *(stg+i) == '\0') salir = 1;
            else
            {
                len++;
                i++;
            }
        }
        else
        {
            if (*(stg+i) == '\0') salir = 1;
            else
            {
                len++;
                i++;
            }

        }
    }
    return len;
}

/*
Dado un string, devuelve en la variable "palabra", la primera palabra que encuentra
*/

/**
@function
@name getPrimeraPalabra
@description Dado un string, devuelve en la variable "palabra", la primera palabra que encuentra
@return int
@param linea:char*
@param palabra:char**
@author Ribotta-Zignego
@see -
*/
int getPrimeraPalabra(char* linea, char** palabra)
{
    char* stg2;
    int numLetras, i;
    int esPalabra = 1;

    RemoveLeadingSpaces (linea);
    numLetras = wordLen (linea,0,esPalabra);

    if (numLetras != 0 ) {
        printf("getprimerapalabra  :");
        stg2 = (char*)malloc (sizeof(char) * (numLetras+1));
        for (i=0; i<numLetras;i++) *(stg2+i) = *(linea+i);
        *(stg2+numLetras)='\0';
        *palabra = stg2;
        return 1;
    }

    return -1;
}


/*
Dada una linea, devuelve en la variable "desc", si hay, una segunda palabra
*/
/**
@function
@name getDesc
@description Dada una linea, devuelve todas las palabras despues de la primer palabra en la variable "desc" si es que existen
@return int
@param linea:char*
@param desc:char**
@author Ribotta-Zignego
@see -
*/
int getDesc(char *linea, char **desc){

    int i=0, numLetras,j;
    char* aux;
    int esPalabra = 0;

    while ( (*(linea+i)!=' ') && (*(linea+i)!='\0') ) i++;    /* Ignora la primera palabra */
    if (*(linea+i) == '\0') return -1;

    while ( (*(linea+i) == ' ') && (*(linea+i) != '\0') ) i++;  /* Ignora los espacios */
    if (*(linea+i) == '\0') return -1;

    numLetras = wordLen(linea,i,esPalabra);

    printf("MEMLEAK getdesc?  :");
    aux = (char*)malloc(sizeof(char) * (numLetras+1));

    for (j=0;j<numLetras;j++){
        aux[j] = *(linea+i+j);    /*¡¡¡Cambiamos algo acá con punteros !!!*/
    }
    aux[numLetras] = '\0';   /*¡¡¡Y acá!!!*/

    /*strcpy(*desc, aux);*/

/*    memcpy(*desc,aux,numLetras+1);*/
    *desc=aux;
    return 1;

}


/*
Saca el caracter "c" de "palabra"
*/
/**
@function
@name sacarCaracter
@description busca el caracter 'c' en la variable palabra, si lo encuentra devuelve 1, si no 0
@return int
@param palabra:char*
@param c:char
@author Ribotta-Zignego
@see -
*/
int sacarCaracter (char* palabra, char c){
    int i=0;

    while ((*(palabra+i) != c) && (*(palabra+i) != '\0')) i++;
    if (*(palabra+i) == c)
    {
        *(palabra+i)='\0';
        return 1;  /* Encontró el caracter */
    }
    return 0; /* No encontró el carater */
}




/*
Dado un TAG, arma el V_Array con sus subtags completo
*/
/**
@function
@name armarSubTags
@description recibe una tag a la que le arma el V_Array con sus subtags completo
@return int
@param fd:FILE*
@param auxTag:TAG*
@author Ribotta-Zignego
@see -
*/
int armarSubTags (FILE* fd, TAG* auxTag)
{
    SUBTAG auxSubTag;
    char* linea;
    char* palabra;
    char* desc;
    int salir=0;


    do {
        getString (&linea,fd);
        printf("armarSubTAG intenta get1palabra\n");
        if (getPrimeraPalabra(linea, &palabra) == 1)
        {
            if (*(palabra) != '}')  /* No es fin de subtags */
            {
                if (getDesc(linea, &desc) == 1)
                {
                    auxSubTag.nombre = palabra;
                    auxSubTag.descrip = desc;
                }
                    else
                    {
                        auxSubTag.nombre = palabra;
                        auxSubTag.descrip = palabra;
                    }
                printf("armarSubTag VA_add\n");
                VA_add (&(auxTag->subTags),&auxSubTag);
            }
            else
            {
                salir = 1;
                free(palabra);
                palabra = NULL;
                }
        }

    } while (salir == 0);
    return 0;
}



/*
Vuelca el archivo de configuración en un V_Array
Devuelve -1 si hubo algún error, 1 en otro caso
*/
/**
@function
@name armarConfig
@description Vuelca el archivo de configuración en un V_Array. Devuelve -1 si hubo algún error, 1 en otro caso
@return int
@param tdc:TDC*
@param archConfig:char*
@author Ribotta-Zignego
@see -
*/
int armarConfig(TDC* tdc, char* archConfig)
{
    FILE *fd;
    char *linea;
    char *palabra;
    char *desc;
    TAG auxTag;
    int encontroCar;
    int salir = 0;

    fd = fopen(archConfig,"rt");
    if (!fd ) return -1;

    while (salir==0)
    {
        salir = getString(&linea,fd);
        if (salir == -2) salir=1;
        else
        {
            if (getPrimeraPalabra(linea, &palabra) == 1)
            {
                encontroCar = sacarCaracter (palabra,'{');
                auxTag.nombre = palabra;
                if (encontroCar == 1)
                {
                    auxTag.descrip = palabra;
                }
                else
                {
                    if (getDesc(linea, &desc) == 1)
                    {
                    encontroCar = sacarCaracter(desc,'{');
                    auxTag.descrip = desc;
                    }
                    else auxTag.descrip = palabra;
                }

                if (encontroCar == 0) getString(&linea,fd); /* Si no encontro la llave antes, va a estar en la siguiente linea, y la salteamos */
                VA_create (&(auxTag.subTags), sizeof(SUBTAG));
                armarSubTags (fd, &auxTag);
                printf("va a intentar hacer un add\n");
                VA_add (&(tdc->listaTags),&auxTag);
            }
        }
    }

    fclose(fd);
    return 0;
}

/*
Lee la linea y se fija si tiene tag de apertura (y no es comentario AUTO
monolinea)
*/
/**
@function
@name tieneTagApertura
@description Lee la linea y se fija si tiene un tag de apertura y no es comentario AUTO monolínea
@return int
@param linea:char*
@param numLinea:int*
@author Ribotta-Zignego
@see -
*/
int tieneTagApertura (char *linea, int *numLinea)
{
    char *apertura = "/**";
    char *cierre = "*/";

    if (strstr(linea,apertura) != NULL)
    {
            if (strstr(linea,cierre) != NULL)
            {
                fprintf (stderr,"Leyo un monolinea en la linea %i\n",*numLinea);
                return 0;
            }
            else return 1;
    }
    else return 0;
}

/*
Función que lee el archivo hasta obtener el primer comentario AUTO. Devuelve
1 si lo encontró, y 0 si es el EOF
*/
/**
@function
@name buscarLineaAuto
@description Lee el archivo fdo hasta obtener el primer comentario AUTO. Devuelve 1 si lo encontró, y 0 si es EOF
@return int
@param fdo:FILE*
@param numLinea:int*
@author Ribotta-Zignego
@see -
*/
int buscarLineaAuto (FILE* fdo, int *numLinea)
{
    char* linea;
    int obtuvoLinea;


    do{
        obtuvoLinea = getString (&linea, fdo);
        if (obtuvoLinea != ERROR_OR_EOF)
        {
            (*numLinea)++;
            if (tieneTagApertura (linea,numLinea)) return 1;
        }
    } while (obtuvoLinea != ERROR_OR_EOF);

    return 0;

}

/*
Devuelve 0 si NO es tag
RAMIRO AGREGO ESTO: también devuelve en el parámetro elemTag el elemento
que es si lo encontro!
*/
/**
@function
@name esTag
@description Devuelve 0 si NO es tag.En el parámetro elemTag devuelve el TAG completo si es TAG
@return int
@param tdc:TDC*
@param fdo:FILE*
@param numLinea:int*
@param elemTag:TAG*
@author Ribotta-Zignego
@see -
*/
int esTag (TDC *tdc, FILE *fdo, int *numLinea, TAG *elemTag){

    int cantidadTags,i;
    TAG auxTag;
    char *linea;
    char *lineaux;
    char *lineaux2;  /* Linea sin espacios iniciales */

    printf ("BORRRRAAAAR \n");

    getString (&linea,fdo);
    printf ("BORRRRAAAAR1234 \n");
    (*numLinea)++;
    getPrimeraPalabra (linea,&lineaux);
    lineaux2 = RemoveLeadingSpaces (lineaux);

    printf ("BORRRRAAAAR \n");

    if (strstr(lineaux2,"@") == lineaux2)  /* @ es el primer elemento de la linea*/
    {
        cantidadTags = VA_count (tdc->listaTags);
        for (i=0;i<cantidadTags;i++)
        {
            VA_get_i (tdc->listaTags,i,&auxTag);
            if (strcmp(auxTag.nombre,(lineaux2+1)) == 0)
            {
                printf ("auxTag.nombre: %s\n",auxTag.nombre);
                printf ("Linea Auxiliar: %s\n",lineaux2+1);
                printf ("Es un tag linea %i\n\n\n",*numLinea);
                (*elemTag) = auxTag;
                printf ("elemTag.nombre: %s\n",elemTag->nombre);
                printf ("elemTag.Desc: %s\n",elemTag->descrip);
                free(lineaux2);
                lineaux2 = NULL;
                return 1;
            }
            else
            {
                printf ("auxTag.nombre: %s\n",auxTag.nombre);
                printf ("Linea Auxiliar: %s\n",lineaux2+1);
                printf ("No es un tag linea %i\n\n\n",*numLinea);
            }
        }
        free(lineaux2);
        lineaux2 = NULL;
    }
    else
    {
        free(lineaux2);
        lineaux2 = NULL;
    }
    return 0;
}


/**
@function
@name descartarAuto
@description evita intentar documentar un comentario AUTO con mala sintaxis
@return int
@param fdo:FILE*
@param numLinea:int*
@author Ribotta-Zignego
@see -
*/
int descartarAuto (FILE* fdo, int* numLinea)
{
    char *lineaBasura;
    int salir=0;

    do{
        getString (&lineaBasura, fdo);
        (*numLinea)++;
        printf ("Descartando linea %i\n",*numLinea);
        if (strstr(lineaBasura,"*/") != NULL) salir = 1;
    } while (!salir);

    return 0;
}

/**
@function
@name escribirArchivo
@description Escribe en el archivo, el subtag, y de ser necesario, el nombre del tag
@return int
@param fdd:FILE*
@param elemTag:TAG
@param linea:char*
@param posicion:int
@param escribirTTag:int
@author Ribotta-Zignego
@see Vamos a escribir algo en un see
*/
int escribirArchivo (FILE* fdd, TAG elemTag, char* linea, int posicion, int escribirTTag)
{
    SUBTAG auxSubTag;
    char* lineaux;
    char* lineaux2;

    if (escribirTTag)
    {
        fputs ("\n--- ",fdd);
        fputs (elemTag.descrip,fdd);
        fputs (" ---\n",fdd);
    }

    printf ("-------------Escribiendo archivo\n");
    VA_get_i (elemTag.subTags,posicion,&auxSubTag);

    lineaux = RemoveLeadingSpaces (linea);
    getDesc (lineaux,&lineaux2);
    fputs ("\t",fdd);
    fputs (auxSubTag.descrip,fdd);
    fputs (": ",fdd);
    fputs (lineaux2,fdd);
    fputs ("\n",fdd);

    return 0;
}

/**
@function
@name obtenerSubTags
@description Dado un tag, obtiene los subtags, y tras validarlos los pasa a una funcion para escribir
@return int
@param fdo:FILE*
@param fdd:FILE*
@param numLinea:int*
@param elemTag:TAG
@author Ribotta-Zignego
@see Ver funcion escribirArchivo
*/
int obtenerSubTags (FILE* fdo, FILE*fdd, int *numLinea, TAG elemTag)
{
    int i;
    int escribirTTag=1;
    int salir = 0;
    int encontro;
    char *linea, *lineaux, *lineaux2;
    int cantidadSubTags;
    SUBTAG auxSubTag;

    getString (&linea,fdo);
    (*numLinea)++;
    getPrimeraPalabra (linea,&lineaux);
    lineaux2 = RemoveLeadingSpaces (lineaux);
    cantidadSubTags = VA_count (elemTag.subTags);

    while (strstr(linea,"*/") == NULL)
    {
        encontro = 0;
        if (strstr(lineaux2,"@") == lineaux2)  /* @ es el primer elemento de la linea*/
        {
            i=0;
            while ((i<cantidadSubTags) && (!encontro))
            {
                VA_get_i (elemTag.subTags,i,&auxSubTag);
                if (strcmp (auxSubTag.nombre,(lineaux2+1)) == 0)
                {
                    printf ("-------------Entro a empezar a escribir\n");
                    escribirArchivo (fdd,elemTag,linea,i,escribirTTag);
                    escribirTTag = 0;
                    encontro = 1;
                }
                else
                {
                    fprintf (stderr,"El subtag no está en el V_ARRAY");
                }
            i++;
            }
        }
        else
        {
            fprintf (stderr,"Subtag sin arroba");
        }
        getString (&linea,fdo);
        (*numLinea)++;
        getPrimeraPalabra (linea,&lineaux);
        lineaux2 = RemoveLeadingSpaces (lineaux);
    }
}

/**
@function
@name TDC_Crear
@description Crea un TDA DocumentoDeCodigo asociado a un archivo de código fuente C para su documentación automática
@return int
@param tdc:TDC*
@param archPrograma:char*
@param archConfig:char*
@author Ribotta-Zignego
@see -
*/
int TDC_Crear (TDC* tdc, char* archPrograma, char* archConfig){
    FILE *ptroAux;
    int result;

    ptroAux = fopen(archPrograma,"rt");
    if (!ptroAux ) return -1;

    fclose (ptroAux);

    result=VA_create (&(tdc->listaTags),sizeof(TAG));

    if (result==-1) return -1;
    if (armarConfig(tdc, archConfig) == -1)
    {
        VA_destroy (&(tdc->listaTags));
        return -1;
    }

    tdc->archivoOrigen = archPrograma;
    return 0;
}

/**
@function
@name destruirVSubtags
@description recibe una TAG a la cual le libera cada uno de sus elementos del TAG.subTags que es un V_Array
@return int
@param elemTags:TAG*
@author Ribotta-Zignego
@see -
*/
int destruirVSubTags (TAG *elemTags){

        int j;
        int cantSubtags;
        SUBTAG elemSubTags;

        cantSubtags = VA_count(elemTags->subTags);

        for (j=0;j<cantSubtags;j++){
            VA_get_i (elemTags->subTags,j,&elemSubTags);
            free(elemSubTags.nombre);
            elemSubTags.nombre = NULL;
            free(elemSubTags.descrip);
            elemSubTags.descrip = NULL;
        }
        VA_destroy (&(elemTags->subTags));
        return 0;
}
/*----------------------------------------------------------------------------*/

/**
@function
@name TDC_Cerrar
@description Cierra el tdc
@return int
@param tdc:TDC*
@author Ribotta-Zignego
@see -
*/
int TDC_Cerrar( TDC *tdc)
{
    int cantTags,i;
    TAG elemTags;


    cantTags = VA_count(tdc->listaTags);

    for (i=0;i<cantTags;i++) {
        VA_get_i (tdc->listaTags,i,&elemTags);
        free (elemTags.nombre);
        elemTags.nombre = NULL;
        free (elemTags.descrip);
        elemTags.descrip = NULL;
        destruirVSubTags(&elemTags);
    }

    printf("destruyendo tdc->listaTags\n");
    VA_destroy(&(tdc->listaTags));
    tdc->archivoOrigen=NULL;
    return 0;
}

/**
@function
@name TDC_Documentar
@description recibe el tdc y la ruta a donde estará el archivo resultante de la documentación. Realiza la documentación del archivo fuente.
@return int
@param tdc:TDC*
@param archDoc:char*
@author Ribotta-Zignego
@see -
*/
int TDC_Documentar (TDC* tdc, char* archDoc){

        int numLinea=0; /* Número de linea del archivo a documentar */
        TAG elemTag;
        FILE *fdo, *fdd; /* Origen - Destino*/
        fdo = fopen (tdc->archivoOrigen,"r");
        fdd = fopen (archDoc,"w");

        while ((buscarLineaAuto (fdo,&numLinea)) == 1){
            if (esTag (tdc,fdo,&numLinea,&elemTag))
            {
                printf ("elemTag.nombre: %s\n",elemTag.nombre);
                printf ("elemTag.Desc: %s\n",elemTag.descrip);
                obtenerSubTags (fdo, fdd, &numLinea,elemTag);
                printf ("elemTag.nombre: %s\n",elemTag.nombre);
                printf ("elemTag.Desc: %s\n",elemTag.descrip);
            }
            else
            {
                descartarAuto (fdo,&numLinea);
            }

        }

        printf ("Termino de documentar\n");
        fclose (fdo);
        fclose (fdd);

        return 0;
}



/*
Función que usamos sólo para probar que imprima bien, se va a ir en la entrega
*/
/**
@function
@name TDC_Borrar
@description función interna de prueba. No debería existir
@return int
@param tdc:TDC*
@author Ribotta-Zignego
@see -
*/
int TDC_Borrar (TDC *tdc)
{
    int cantidadTags, cantidadSubTags;
    int i,j;
    TAG elemTag;
    SUBTAG elemSubTag;

    cantidadTags = VA_count (tdc->listaTags);
    for (i=0;i<cantidadTags;i++)
    {
        VA_get_i(tdc->listaTags,i,&elemTag);
        printf ("-------TAG %i-------\n",i);
        printf ("Nombre: %s\nDescrip: %s\n",elemTag.nombre,elemTag.descrip);
        cantidadSubTags = VA_count(elemTag.subTags);
        for (j=0;j<cantidadSubTags;j++)
        {
            printf ("CantidadSubTags: %i\n",cantidadSubTags);
            VA_get_i(elemTag.subTags,j,&elemSubTag);
            printf ("-----SUBTAG %i-----\n",j);
            printf ("Nombre: %s\nDescrip: %s\n",elemSubTag.nombre,elemSubTag.descrip);
        }
    }
printf ("\nTermine de imprimir todo\n");
return 0;
}
