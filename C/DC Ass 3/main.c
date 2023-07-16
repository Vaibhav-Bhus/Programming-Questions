#include <stdio.h>
#include <string.h>
void main()
{
    int k,j;
    for(k=0;k<=10;k+=2)
    {
        for(j=1;j!=k;j=j+1)
        {
            printf("\nHello");
            break;
        }
    }
}
