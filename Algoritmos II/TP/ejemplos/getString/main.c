#include <stdio.h>
#include <stdlib.h>
#include "getString.h"

int main()
{
    FILE *fd;
    char *temp;


    fd = fopen ("config.txt", "r");
    while (!feof(fd)) {
    getString(&temp,fd);
    printf("%s \n",temp);
    }
    int a;
    scanf("%d",&a);
    fclose(fd);
    return 0;

}
