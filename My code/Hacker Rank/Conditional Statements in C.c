#include <stdio.h>

int main()
{

    int number;
    scanf("%d", &number);

    if (number >= 1 && number < 2)
    {
        puts("one");
    }
    else if (number >= 2 && number < 3)
    {
        puts("two");
    }
    else if (number >= 3 && number < 4)
    {
        puts("three");
    }
    else if (number >= 4 && number < 5)
    {
        puts("four");
    }
    else if (number >= 5 && number < 6)
    {
        puts("five");
    }
    else if (number >= 6 && number < 7)
    {
        puts("six");
    }
    else if (number >= 7 && number < 8)
    {
        puts("seven");
    }
    else if (number >= 8 && number < 9)
    {
        puts("eight");
    }
    else if (number >= 9 && number < 10)
    {
        puts("nine");
    }
    else
    {
        puts("Greater than 9");
    }

    return 0;
}