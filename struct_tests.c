#include <stdlib.h>
#include <stdio.h>

typedef struct{
    char name[99];
    char gender;
    int age;
}user_t;

int main(int argc, char const *argv[])
{
    user_t bob = {"Bobby Wheeler",'M',19};

    printf("Name: %s\nSex: %c\nAge: %d\n", bob.name,bob.gender,bob.age);

    return 0;
}

