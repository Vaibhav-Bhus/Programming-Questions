#include <stdio.h>

long long dumb(long long x)
{
    if(x < 9)
        return x;
    else
        return x%9 + 10*dumb(x/9);
}

int main()
{
    long long x;

    while((scanf("%lld", &x))!=(0<=x<=10^18))
      {
          printf("%lld\n", dumb(x));
      }
    return 0;
}
