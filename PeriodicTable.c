#include <stdio.h>
#include <string.h>

typedef struct{
    int atomic_number;
    char name[20],class[20];
    double weight;
    int shells[8];    
}element_t;

void print_element(element_t element)
{
    printf("%d - %s\n",element.atomic_number,element.name);
    printf("Weight: %1.1lf\n", element.weight);
    printf("Class: %s\n",element.class);
    printf("Shells: ");

    for(int i = 0;i < 6;i++)
    {
        printf("%d ",element.shells[i]);
    }

    printf("\n\n");
}

int
main(void)
{
    element_t element;

    printf("Enter atomic #: ");
    scanf("%d",&element.atomic_number);
    printf("Enter Name: ");
    scanf("%s",element.name);
    printf("Enter Class: ");
    scanf("%s",element.class);
    printf("Enter Weight: ");
    scanf("%lf",&element.weight);
    printf("Enter Electron Shell: ");
    scanf("%d %d %d %d %d %d %d",&element.shells[0],&element.shells[1],&element.shells[2],&element.shells[3],&element.shells[4],&element.shells[5],&element.shells[6]);
    printf("\n");
    
    print_element(element);


    return 0;
}