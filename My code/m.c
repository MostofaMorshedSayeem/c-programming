//Wrong code 
//Unoptimized 
//Not what I was looking for 


#include <stdio.h>

int main() {
    int count;
    double sum = 0.0, num;

    printf("Enter the number of values to average: ");
    scanf("%d", &count);

    if (count <= 0) {
        printf("Invalid input. The number of values must be greater than 0.\n");
        return 1;
    }

    for (int i = 0; i < count; i++) {
        printf("Enter number %d: ", i + 1);
        scanf("%lf", &num);
        sum += num;
    }

    printf("The average is: %.2f\n", sum / count);
    return 0;
}
