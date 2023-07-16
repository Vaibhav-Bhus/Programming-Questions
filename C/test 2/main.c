#include<stdio.h>
#include<string.h>
#define max 100
int main ()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int a[n], b[m],c = 0;
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for(int j = 0; j< m; j++)
        scanf("%d", &b[j]);

    for (int i=1; i<=max; i++)
    {
        int flag = 0;
        for (int j=0; j<n; j++)
            if (i % a[j] != 0)
                flag = 1;
        for (int j=0; j<m; j++)
            if (b[j] % i != 0)
                flag = 1;
        if (flag == 0)
            c++;
    }
    printf("%d\n", c);
    return 0;
}

