#include <stdio.h>


struct{
    union{
        char a,b;
        int c;
    }d;
    int e[5];
}f, *p = &f;

int main()
{
    p->d->c = 10;

    return 0;
}