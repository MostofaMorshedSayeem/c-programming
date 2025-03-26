#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main()
{

    char input[10];
    scanf("%5s", input);

    for (int i = 0; i < strlen(input); i++) // if you enter anything except a digit program stops execution 
    {
        if (!isdigit(input[i])) 
        {
            return 1; 
        }
    }

    int number = atoi(input); // requires stdlib // converts string to number
    int sum = 0;

    while (number > 0)
    {
        int last_digit = number % 10;
        sum += last_digit;
        number /= 10;
    }

    printf("%d\n", sum);
    return 0;
}