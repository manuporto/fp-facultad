#include <stdio.h>

int main(void)
{
char string[80];

puts("first test. Enter string: ");
scanf("%[^\t\n]",string);
puts(string);
while(getchar()!=(int)'\n');

puts("\nsecond test. Enter string: ");
scanf("%[ a-zA-Z0-9+*/-]",string);
puts(string);

return 0;
}
