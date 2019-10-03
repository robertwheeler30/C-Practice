#include <stdio.h>
#include <string.h>

int
main(void)
{
    float value1, value2, sum, difference,product,quotient;
    printf("Enter value1: ");
    scanf("%f", &value1);
    printf("Enter value2: ");
    scanf("%f", &value2);

    sum = value1 + value2;

    printf("%.3e",sum);
    
}