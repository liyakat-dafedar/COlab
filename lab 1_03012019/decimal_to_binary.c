#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int a[10], i;
void decimal_to_binary(int);
void binary_to_decimal();
int main()
{
    int no, choice, decimal;

    decimal = no;
    while(1)
    {
        printf("\n1:Decimal to binary\n2:binary to decimal\n\tEnter your choice(1-2):\t");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("Enter the decimal number\t:");
                    scanf("%d",&no);
                    decimal_to_binary(no);
                    break;
            case 2: printf("Enter the binary number(enter 2 to stop):\n");
                    binary_to_decimal();
                    break;
            case 3: exit(0);
            default : printf("\nEnter valid option");
                    break;;
        }
    }
    return 0;
}
void decimal_to_binary(int n)
{
    int  j;
    for(i=0;n > 0;i++,n=n/2)
    {
        a[i] = n %2;
    }
    a[i] = 2;

    for(j=i-1;j>=0;j--)
    {
        printf("%d",a[j]);
    }
    printf("\n");
}

void binary_to_decimal()
{
    int j, no, n;
    int k;
    no = 0;
    printf("Enter the binary no:\t");
    scanf("%d",&n);
    while(n)
    {
        no += (n%10) * pow(2,i);
        n = n / 10;
        i++;
    }

    printf("\nThe equivalent decimal no = %d",no);

}






























/*
*#git123@?
*/
