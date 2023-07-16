#include<math.h>
#include<stdio.h>
int sum(int s);
int rev(int s);
int digit(int s);
int main()
{
    int n;
    scanf("%d",&n);
    printf("%d\n",sum(n));
    printf("%d\n",rev(n));
    printf("%d\n",digit(n));
}
int sum(int s)
{

    if (s== 0)
        return 0;
    return(s%10+sum(s/10));
}
int rev(int s)
{
    int p=(int)log10(s);
    if(s == 0)
        return 0;
    return ((s%10 * pow(10, p)) + rev(s/10));
}
int digit(int s)
{
    static int count=0;

    if(s>0)
    {
        count++;
        digit(s/10);
    }
    else
        return count;
}

