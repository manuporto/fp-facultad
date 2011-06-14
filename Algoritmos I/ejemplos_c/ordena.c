/****************************************************************************
 * ordena.c
 *
 * Programa de ejemplo de ordenamiento de un arreglo de enteros, mediante
 * el algoritmo de burbujeo. Dicho arreglo podrá cargarse por teclado, o
 * podrá ser generado aleatoriamente (mediante compilación condicional).
 * Algoritmos y Programación I
 * Catedra: Pablo Guarna.
 *
 * Para compilar desde linea de comandos (por ejemplo, con MinGW):
 *		gcc -Wall -ansi ordena.c -o ordena
 *
 ****************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define OK			 0
#define ERROR		-1

#define POR_TECLADO


/* Ordena ascendentemente un arreglo de números aplicando burbujeo */
int ordenaNumeros(int *numeros, int len)
{
	int i,j,aux;

	if ( numeros == NULL )
		return ERROR;

	for (i=0; i<len-1; i++)
		for (j=0; j<len-1-i; j++)
			if ( numeros[j] > numeros [j+1] )
			{
				aux = numeros[j];
				numeros[j] = numeros[j+1];
				numeros[j+1] = aux;
			}

	return OK;
}


int main()
{
	int *numeros, i, len;

#ifdef POR_TECLADO

	/* Se cargan los datos desde teclado */
	printf("Ingrese la cant. de elementos: ");
	scanf("%d", &len);

	numeros = (int *)malloc(len*sizeof(int));

	for (i=0; i<len; i++)
	{
		printf("Ingrese el elemento %d: ", i);
		scanf("%d", numeros+i);
	}

#else

	/* Se inicializa el generador de numeros aleatorios */
	srand( (unsigned)time( NULL ) );

	/* Se carga el arreglo con numeros aleatorios */
	len = 10;
	numeros = (int *)malloc(len*sizeof(int));

	for (i=0; i<len; i++)
		numeros[i] = rand();

#endif


	for (i=0; i<len; i++)
		printf("%d ", numeros[i]);
	printf("\n");

	ordenaNumeros(numeros, len);

	for (i=0; i<len; i++)
		printf("%d ", numeros[i]);
	printf("\n");

	return OK;
}
