#include <stdio.h>

int max_of_four(int a, int b, int c, int d)
{
    int max;

    if (a > b && a > c && a > d)
    {
        max = a;
    }
    else if (b > a && b > c && b > d)
    {
        max = b;
    }
    else if (c > a && c > b && c > d)
    {
        max = c;
    }
    else
    {
        max = d;
    }

    return max;
}

int main()
{
    int a, b, c, d;

    scanf("%d %d %d %d", &a, &b, &c, &d);

    int max = max_of_four(a, b, c, d);
    printf("%d\n", max);

    return 0;
}