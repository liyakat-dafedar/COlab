#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void add();
void sub();
/*int decimal_binary(int);*/
int main()
{
    int choice;
    printf("\n1.Addition\n2.Subtraction\n3.Exit");
    printf("choose the a:\t");
    scanf("%d",&choice);
    while(1)
    switch(choice)
    {
        case 1: add();
                break;
        case 2: sub();
                break;
        case 3: exit(0);
        default:printf("Invalid Entry");
    }
    return 0;
}
void add()
{
    int n1, n2, i, len, f, pos;
    f = 0;
    char bin1[10], bin2[10], bin3[10];
    printf("Enter the first binary number:\t");
    scanf("%s",bin1);
    printf("Enter the second binary number:\t");
    scanf("%s",bin2);
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
    if (bin2[0] == '1')
    {
        len = strlen(bin1);
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
    printf("\nbin1:%s",bin1);
    printf("\nbin2:%s\n",bin2);
    len = strlen(bin1);
    for(i=len-1;i>0;i--)
    {
        if (bin1[i] == '1' && bin2[i] == '1')
        {
            printf("\n1+1\n");
        }else
        {
            n1 = (int)bin1[i];
            n2 = (int)bin2[i];
            printf("\n%d--%d\n",n1,n2);
            bin3[i] = (char)(n1 - n2);
        }
    }
       printf("\nbin3:%s",bin3);

}

/*int decimal_binary(int n)
{
    int rem, i, bin;
    i = 1;
    while(n > 0)
    {
        rem = n % 2;
        bin = bin + ( rem * i);
        i = i * 10;
        //bin = bin * i;
        n = n / 2;
    }
    printf(":\t%d",bin);
}*/

void sub()
{

}
