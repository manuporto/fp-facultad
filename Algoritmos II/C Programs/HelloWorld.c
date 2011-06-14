# include <stdio.h>

int main(void)
{

  int numero = 0;
  int numero2 = 0;
  
  printf ("Programita \n");
  printf ("Ingrese un numero: ");
  scanf ("%d", &numero);
  printf ("Ingrese otro numero: ");
  scanf ("%i", &numero2);
  printf ("Suma: %i \n", numero + numero2);
  scanf ("\n");
  return 0;
}
