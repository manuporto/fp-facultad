/* necesito una función que se fije
si el archivo está vacío o no */

/* http://cboard.cprogramming.com/c-programming/104274-detecting-empty-file-situation.html
*/

int main (void)
{
	FILE *fp;
        char *path = "path\\to\\file";
	long size;

	fp = fopen(path, "r");

	if (fp)
	{
		fseek (fp, 0, SEEK_END);
		size = ftell(fp);
		printf("Size of the file in bytes: %lu\n", size);
		fclose(fp);
	}

	return 0;
}


/* Devuelve el tamaño del archivo
si el tamaño es 0, el archivo está vacío,
cualquier otro valor no está vacío, si el archivo
no está vacío hay que poner el puntero del stream
de nuevo al inicio con la función ANSI rewind */
int archivoVacio(FILE *fd){
	int size;
	
	fseek (fp, 0, SEEK_END);
	size = ftell(fp);
	printf("Size of the file in bytes: %lu\n", size);
	return size;
}







