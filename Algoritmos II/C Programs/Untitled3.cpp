#include <stdio.h>

#define MAX 20

int main(void)
{
int i;
// float x = 100000000.0f, y; // precision simple
double x = 100000000.0, y; // precision doble

y = x; // Ambos arrancan con un valor de 100 millones

for (i = 0; i < MAX; i++)
{
// Ciclo que le sumo a x 20 veces un 1 
x = x + 1.0f; //1.0f es para que trabaje con flotantes
printf("%2d) x = %20.0f\n",i+1,x); //Imprimo sin decimales
}

// A y le sumo 20, deberia quedar con el mismo valor de x
y = y + 20.0f; 

printf("\n Si le sumo 20 directamente %10.0f\n\n",y);
getchar();
}
