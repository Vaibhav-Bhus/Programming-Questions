#include <stdio.h>
#include <math.h>

int main()
{
    int b=5, s=10;
    b=s+b;
    s=b-s;
    b=b-s;
    printf("%d\n%d",s,b);
}
