/****************************************************************************
 * factorial.c
 *
 * Programa de ejemplo de recursividad de funciones.
 * Algoritmos y Programación I
 * Catedra: Pablo Guarna.
 *
 * Para compilar desde linea de comandos (por ejemplo, con MinGW):
 *		gcc -Wall -ansi factorial.c -o factorial
 *
 ****************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define OK			 0
#define ERROR		-1


long factorial(int n)
{
	printf("%p \n", &n);
/*
	if ( n == 0)
		return 1;
	else
		return n * factorial(n-1);
*/
	return n==0 ? 1 : n*factorial(n-1);
}

int main(int argc, char *argv[])
{
	int n;

	if ( argc != 2 )
	{
		printf("Modo de uso: factorial <n> \n");
		return ERROR;
	}

	n = atoi(argv[1]);
	printf("Factorial de %d = %li \n", n, factorial(n));
	
	return OK;
}
