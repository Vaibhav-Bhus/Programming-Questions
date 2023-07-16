#include <stdio.h>
long dumb( long x)
{
    if(x<9)
        return (x);
    else
        return (x%9+10*dumb(x/9));
}

int main()
{
     long x;

     do
    {
        if(scanf("%lld",&x)!=EOF)
            printf("%lld ",dumb(x));
        else
            break;
    }while((0<=x<=10^18));
}
