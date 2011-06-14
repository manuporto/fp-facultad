/* necesito una funci�n que se fije
si el archivo est� vac�o o no */

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


/* Devuelve el tama�o del archivo
si el tama�o es 0, el archivo est� vac�o,
cualquier otro valor no est� vac�o, si el archivo
no est� vac�o hay que poner el puntero del stream
de nuevo al inicio con la funci�n ANSI rewind */
int archivoVacio(FILE *fd){
	int size;
	
	fseek (fp, 0, SEEK_END);
	size = ftell(fp);
	printf("Size of the file in bytes: %lu\n", size);
	return size;
}







