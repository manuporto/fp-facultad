/*
Modificado por Ribotta Mariano y Zignego Ramiro
*/

#include "getString.h"

#include "memdbg.h"


int getString(char** result, FILE* fd)
{
    size_t size = 0, length = 0;
    char* buff = NULL;
    char* temp = NULL;
    char* ret = NULL;
    unsigned int i = 0;
    /* Continuo leyendo hasta \n o EOF . */

   do
    {
        size += NUMCARACTERES;
        temp = (char*) realloc( buff, (sizeof(char) * size) - 1 );
        if( !temp)
        {
            free(buff);
            return ERROR_NOT_MEMORY;/*return -1;*/
        }
        buff = temp;
        /*Leo los proximos caracteres*/
        ret = fgets(buff + (size - NUMCARACTERES -i) , NUMCARACTERES, fd);
        if (!feof(fd)){ length = strlen(ret);}
        i++;
    }while((!feof(fd))&&(ret[length-1]!='\n'));


    /* EOF o error. */
    if( (length==0 && feof(fd)) || ferror(fd))
    {
        free(buff);
        return ERROR_OR_EOF;/*return -2;*/
    }
    /* Remuevo el \n final. */
    if( ret[length-1]=='\n')
        ret[length-1]=0;
    /* Guardo el resultado. */
    *result = buff;
    return RES_OK;
}
