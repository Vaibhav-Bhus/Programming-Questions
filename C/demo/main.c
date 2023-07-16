#include<stdio.h>
#include<conio.h>
#include<string.h>
void main()
{
    char sender[50], receiver[50];
    int i = 0;
    printf("Enter the data to be send : ");
    gets(sender);

    while(i < strlen(sender))
    {
        receiver[i] = sender[i];
        printf("\n\nMessage sent by the sender : ");
        printf("%c", sender[i]);
        printf("\nWait for Acknoledgement(Stop and wait) from receiver. ");
        printf("\nAcknowledgment from receiver : %c", receiver[i]);
        if (sender[i] == receiver[i])
            i++;
        else
            i=i;// If occur any error in Acknowledgment then repeat for same bit
    }
    printf("\n\n\nMESSAGE RECEIVED BY RECEIVER IS : ");
    puts(receiver);
}
