#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void two_s_complement(char[],char[],int);
void add(char [], char []);
/*int decimal_binary(int);*/
int main()
{
    int choice,n;
    char bin1[10], bin2[10];

    while(1)
    {
        printf("\n1.Addition\n2.Subtraction\n3.Exit");
        printf("choose your option(1-3):\t");
        scanf("%d",&choice);
    switch(choice)
    {
        case 1: printf("Enter the number of bits(including the sign bit):\t");
                scanf("%d",&n);
                printf("Enter the first binary number:\t");
                scanf("%s",bin1);
                printf("Enter the second binary number:\t");
                scanf("%s",bin2);
                two_s_complement(bin1,bin2,0);
                break;
        case 2: printf("Enter the number of bits(including the sign bit):\t");
                scanf("%d",&n);
                printf("Enter the first binary number:\t");
                scanf("%s",bin1);
                printf("Enter the second binary number:\t");
                scanf("%s",bin2);
                two_s_complement(bin1,bin2,1);
                break;
        case 3: exit(0);
        default:printf("Invalid Entry");
    }
    }
    return 0;
}
void two_s_complement(char bin1[],char bin2[],int operation)
{
    int n1, n2, i, len, f, pos, carry, n;
    f = 0;  carry = 0;
    if (bin1[0] == '1')
    {
        len = strlen(bin1);
        for(i=len-1;i>=0;i--)
        {
            if (bin1[i] == '1')
            {
                f = 1;
                pos = i;
                break;
            }
        }
    for(i=pos-1;i>=0;i--)
    {
        if (bin1[i] == '0')
            bin1[i] = '1';
        else
            bin1[i] = '0';
    }
    }
    f = 0;
    if (operation == 1 || bin2[0] == '1')
    {
        len = strlen(bin2);
        for(i=len-1;i>=0;i--)
        {
            if (bin2[i] == '1')
            {
                f = 1;
                pos = i;
                break;
            }
        }
    for(i=pos-1;i>=0;i--)
    {
        if (bin2[i] == '0')
            bin2[i] = '1';
        else
            bin2[i] = '0';
    }
    }

    add(bin1,bin2);
    printf("\nbin1:%s",bin1);
    printf("\nbin2:%s\n",bin2);



}
void add(char bin1[], char bin2[])
{
    char bin3[50];    int len,i,carry;
    len = strlen(bin1);
    for(i=len-1;i>=0;i--)
    {
        if (bin1[i] == '1' && bin2[i] == '1')
        {
            if (carry == 1)
            {
                bin3[i] = '1';
                carry = 1;
            }
            else
            {
                bin3[i] = '0';
                carry = 1;
            }
        }
        else if ((bin1[i] == '0' && bin2[i]=='1') || (bin2[i] == '0' && bin1[i]=='1'))
        {
            if (carry == 1)
            {
                bin3[i] = '0';
                carry = 1;
            }
            else
            {
                bin3[i] = '1';
                carry = 0;
            }
        }
        else
        {
            if (carry == 1)
            {
                bin3[i] = '1';
                carry = 0;
            }
            else
            {
                bin3[i] = '0';
                carry = 0;
            }
        }
    }
    printf("%c",bin3[0]);
    bin3[len] = '\0';
       printf("\nbin3:%s",bin3);
}
