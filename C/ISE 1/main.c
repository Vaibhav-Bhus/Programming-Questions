#include<stdio.h>
#define max 100
void dectbin(int n);
int main ()
{
	int a[max],n,i,c,b[max];
	scanf ("%d",&n);
	for (i=0; n>0; i++)
	{
		a[i]=n%2;
		n=n/2;
	}

	for(i=i-1; i>=0; i--)
	    printf("%d",a[i]);
	return 0;
}
void dectobin(int n)
{
	int a[max],i,j,k,c=0,b[i];
	while(n!=0);
	{
		a[i]=n%2;
		n=n/2;
		c++;
	}
    printf("%d",c);
    int ex;
	ex=c;
	for(k=0;c>0;k++)
	{
		b[i]=c%2;
		c=c/2;
	}
	for(i=0;i>=0;i++)
        printf("%d",b[i]);
	int temp[ex],carry,z;
	z=ex;
	for(i=c;i>=0;i--)
	{
		if((a[i]+b[i]+carry)==0)
		{
			temp[z]=0;
			carry=0;
			z--;
		}
		if((a[i]+b[i]+carry)==1)
		{
			temp[z]=1;
			carry=0;
			z--;
		}
		if((a[i]+b[i]+carry)==2)
		{
			temp[z]=0;
			carry=1;
			z--;
		}
		if((a[i]+b[i]+carry)>2)
		{
			temp[z]=1;
			carry=1;
			z--;
		}
	}
	for(i=z;i>=0;i--)
        printf("%d",temp[i]);
}
