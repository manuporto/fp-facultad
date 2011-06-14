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

/*
Dada una palabra, le quita los espacios iniciales.
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
            else { salir = 1; free(palabra);}
        }

    } while (salir == 0);
    return 0;
}



/*
Vuelca el archivo de configuración en un V_Array
Devuelve -1 si hubo algún error, 1 en otro caso
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
                return 1;
            }
            else
            {
                printf ("auxTag.nombre: %s\n",auxTag.nombre);
                printf ("Linea Auxiliar: %s\n",lineaux2+1);
                printf ("No es un tag linea %i\n\n\n",*numLinea);
            }
        }
    }
    else return 0;
}

/*
Lsafio
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

int destruirVSubTags (TAG *elemTags){

        int j;
        int cantSubtags;
        SUBTAG elemSubTags;

        cantSubtags = VA_count(elemTags->subTags);

        for (j=0;j<cantSubtags;j++){
            VA_get_i (elemTags->subTags,j,&elemSubTags);
            free(elemSubTags.nombre);
            free(elemSubTags.descrip);
        }
        VA_destroy (&(elemTags->subTags));
        return 0;
}
/*----------------------------------------------------------------------------*/

int TDC_Cerrar( TDC *tdc)
{
    int cantTags,i;
    TAG elemTags;


    cantTags = VA_count(tdc->listaTags);

    for (i=0;i<cantTags;i++) {
        VA_get_i (tdc->listaTags,i,&elemTags);
        free (elemTags.nombre);
        free (elemTags.descrip);
        destruirVSubTags(&elemTags);

    }


    VA_destroy (&(elemTags.subTags));
    tdc->archivoOrigen=NULL;
    return 0;
}


int TDC_Documentar (TDC* tdc, char* archDoc){

        int numLinea=0; /* Número de linea del archivo a documentar */
        TAG elemTag;
        SUBTAG borrarTag;
        FILE *fdo, *fdd; /* Origen - Destino*/
        fdo = fopen (tdc->archivoOrigen,"r");
        fdd = fopen (archDoc,"w");

        while ((buscarLineaAuto (fdo,&numLinea)) == 1){
            if (esTag (tdc,fdo,&numLinea,&elemTag))
            {
                printf ("elemTag.nombre: %s\n",elemTag.nombre);
                printf ("elemTag.Desc: %s\n",elemTag.descrip);
/*                printf ("VA_create da: %i\n",VA_create (&(elemTag.subTags),sizeof(SUBTAG)));*/
               /*obtenerSubTags (tdc);  ACA VAMOS A ALLOCAR MEM */
                printf ("elemTag.nombre: %s\n",elemTag.nombre);
                printf ("elemTag.Desc: %s\n",elemTag.descrip);
                VA_get_i (elemTag.subTags,1,&borrarTag);
                printf ("Ningun idioma: %s\n",borrarTag.descrip);
                printf ("IMPRIMIR EL AUXILIAR EN EL ARCHIVO\n"); /* LIBERAR MEM ALLOCADA */
                /*destruirVSubTags (&elemTag);*/
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
