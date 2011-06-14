/******************************************************************************
 *                   Algoritmos y Programación II - 75.41                     *
 *                        Cátedra: Lic. Gustavo Carolo                        *
 *            Facultad de Ingeniería - Universidad de Buenos Aires            *
 ******************************************************************************/

/**
@title
@name Documentador de Codigo
@description Version 1.0 del documentador de codigo
*/

/*
#include "memdbg.h" Este include no se usa en el TP, es sólo para testearlo
*/

#include "TDA_DocumentoDeCodigo.h"

/* Tipo de dato */
typedef struct TAG{
        char *nombre; /* apunta al nombre principal de tag */
        char *descrip; /* Descripción del subtag */
        V_Array subTags; /* contiene los subTags */
}TAG;


typedef struct SUBTAG{
        char* nombre; /* apunta al nombre principal de subtag */
        char* descrip; /*Descripción del subtag */
}SUBTAG;


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

/**
@function
@name wordLen
@description Recibe un string y una posición dentro de ese string, y devuelve la cantidad de letras desde ahi hasta un espacio si es palabra o hasta fin de línea si es una oración
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
        stg2 = (char*)malloc (sizeof(char) * (numLetras+1));
        for (i=0; i<numLetras;i++) *(stg2+i) = *(linea+i);
        *(stg2+numLetras)='\0';
        *palabra = stg2;
        return 1;
    }
    return -1;
}


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

    aux = (char*)malloc(sizeof(char) * (numLetras+1));

    for (j=0;j<numLetras;j++){
        aux[j] = *(linea+i+j);
    }
    aux[numLetras] = '\0';

    *desc=aux;
    return 1;

}


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
                VA_add (&(auxTag->subTags),&auxSubTag);
            }
            else
            {
                salir = 1;
                free(palabra);
                palabra = NULL;
                }
        free (linea);
        linea = NULL;
        }

    } while (salir == 0);
    return 0;
}


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
    if (!fd )
    {
        fprintf (stderr,ERR_CONFIG);
        return -1;
    }

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
                    else
                    {
                        auxTag.descrip = palabra;
                    }
                }

                if (encontroCar == 0)
                {
                    free (linea);
                    linea = NULL;
                    getString(&linea,fd); /* Si no encontro la llave antes, va a estar en la siguiente linea, y la salteamos */
                }
                VA_create (&(auxTag.subTags), sizeof(SUBTAG));
                armarSubTags (fd, &auxTag);
                VA_add (&(tdc->listaTags),&auxTag);
            }
        }
        free (linea);
        linea = NULL;
    }

    fclose(fd);
    return 0;
}

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
    char *apertura = TAG_APERTURA;
    char *cierre = TAG_CIERRE;

    if (strstr(linea,apertura) != NULL)
    {
            if (strstr(linea,cierre) != NULL)
            {
                fprintf (stderr,ERR_DESCRIP,*numLinea,ERR_MONO);
                return 0;
            }
            else return 1;
    }
    else return 0;
}

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
            if (tieneTagApertura (linea,numLinea)) {
                free (linea);
                linea = NULL;
                return 1;
            }
        }
        free (linea);
        linea = NULL;
    } while (obtuvoLinea != ERROR_OR_EOF);

    return 0;
}

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
    int encontro = 0;
    TAG auxTag;
    char *linea;
    char *lineaux;
    char *lineaux2;

    getString (&linea,fdo);
    (*numLinea)++;
    getPrimeraPalabra (linea,&lineaux);
    lineaux2 = RemoveLeadingSpaces (lineaux);

    if (strstr(lineaux2,"@") == lineaux2)  /* @ es el primer elemento de la linea*/
    {
        cantidadTags = VA_count (tdc->listaTags);

        i=0;
        while ((i<cantidadTags) && (!encontro))
        {
            VA_get_i (tdc->listaTags,i,&auxTag);
            if (strcmp(auxTag.nombre,(lineaux2+1)) == 0)
            {
                (*elemTag) = auxTag;
                free(lineaux2);
                lineaux2 = NULL;
                encontro = 1;
            }
            i++;
        }
        if (encontro) fprintf (stderr,ERR_DESCRIP,*numLinea,ERR_NOTAG);

    }
    else fprintf (stderr,ERR_DESCRIP,*numLinea,ERR_LINEAVACIA);

    free (linea);
    linea = NULL;
    free(lineaux2);
    lineaux2 = NULL;

    if (encontro) return 1;

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
        if (strstr(lineaBasura,TAG_CIERRE) != NULL) salir = 1;
        free (lineaBasura);
        lineaBasura = NULL;
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

    VA_get_i (elemTag.subTags,posicion,&auxSubTag);

    lineaux = RemoveLeadingSpaces (linea);
    getDesc (lineaux,&lineaux2);
    fputs ("\t",fdd);
    fputs (auxSubTag.descrip,fdd);
    fputs (": ",fdd);
    fputs (lineaux2,fdd);
    fputs ("\n",fdd);
    free (lineaux2);
    lineaux2 = NULL;

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
    int escribirTTag = 1;
    int encontro;
    char *linea, *lineaux, *lineaux2;
    int cantidadSubTags;
    SUBTAG auxSubTag;

    getString (&linea,fdo);
    (*numLinea)++;
    getPrimeraPalabra (linea,&lineaux);
    lineaux2 = RemoveLeadingSpaces (lineaux);
    cantidadSubTags = VA_count (elemTag.subTags);

    while (strstr(linea,TAG_CIERRE) == NULL)
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
                    escribirArchivo (fdd,elemTag,linea,i,escribirTTag);
                    escribirTTag = 0;
                    encontro = 1;
                }
            i++;
            }
        }
        else
        {
            fprintf (stderr,ERR_DESCRIP,*numLinea,ERR_SINTAXIS);
        }

        if (!encontro) fprintf (stderr,ERR_DESCRIP,*numLinea,ERR_NOSUBTAG);
        free (linea);
        linea = NULL;
        free (lineaux);
        lineaux = NULL;
        getString (&linea,fdo);
        (*numLinea)++;
        getPrimeraPalabra (linea,&lineaux);
        lineaux2 = RemoveLeadingSpaces (lineaux);
    }
    free (linea);
    linea = NULL;
    free (lineaux);
    lineaux = NULL;
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
            if (elemSubTags.nombre == elemSubTags.descrip) /* Si los dos apuntan al mismo string, libera solo uno */
            {
                free(elemSubTags.nombre);
                elemSubTags.nombre = NULL;
            }
            else
            {
                free(elemSubTags.nombre);
                elemSubTags.nombre = NULL;
                free(elemSubTags.descrip);
                elemSubTags.descrip = NULL;
            }
        }
        VA_destroy (&(elemTags->subTags));
        return 0;
}

/**
@function
@name listado
@description función interna de prueba. No debería existir
@return int
@param tdc:TDC*
@author Ribotta-Zignego
@see -
*/
int listado (TDC *tdc)
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
    if (!ptroAux )
    {
        fprintf (stderr,ERR_FUENTE);
        return -1;
    }

    fclose (ptroAux);

    result=VA_create (&(tdc->listaTags),sizeof(TAG));

    if (result==-1)
    {
        fprintf (stderr,ERR_MEM);
        return -1;
    }
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

        if (elemTags.nombre == elemTags.descrip) /* Si los dos apuntan al mismo string, libera solo uno */
        {
            free (elemTags.nombre);
            elemTags.nombre = NULL;
        }
        else
        {
            free (elemTags.nombre);
            elemTags.nombre = NULL;
            free (elemTags.descrip);
            elemTags.descrip = NULL;
        }
        destruirVSubTags(&elemTags);
    }

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
                obtenerSubTags (fdo, fdd, &numLinea,elemTag);
            }
            else
            {
                fprintf (stderr,ERR_DESCRIP,numLinea,ERR_DESCARTADO);
                descartarAuto (fdo,&numLinea);
            }

        }

        printf ("Termino de documentar...\n");
        fclose (fdo);
        fclose (fdd);

        return 0;
}

/**
@footer
@name Documentador de Codigo
@author Grupo 1
@copyright Todos los izquierdos reservados.
*/
