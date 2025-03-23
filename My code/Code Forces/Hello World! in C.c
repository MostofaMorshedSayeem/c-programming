#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 100

int main()
{
    char s[MAX_LEN];

    fgets(s , MAX_LEN , stdin);

    printf("Hello, World!\n");
    printf("%s", s);
    return 0;
}