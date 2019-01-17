#include<stdio.h>
#include<math.h>
#include<stdlib.h>
void decimal_to_binary(int);
void binary_to_decimal(int);
int main()
{
    int no, choice, n;
    while(1)
    {
        printf("\n1:Decimal to binary\n2:Binary to decimal\n3:Exit\n\tEnter your choice(1-3):\t");
        scanf("%d",&choice);
        switch(choice)
        	{
	            case 1 : printf("Enter the decimal number\t:");
	                     scanf("%d",&no);
	                     decimal_to_binary(no);
	                     break;
	            case 2 : printf("Enter the binary no:\t");
	                     scanf("%d",&n);
	                     binary_to_decimal(n);
	                     break;
	            case 3 : exit(0);
	            default : printf("\nEnter valid option:\t");
	                      break;
        	}
    }
    return 0;
}
void decimal_to_binary(int n)
{
    int  j, i, rem, bin, neg, count;
    bin = 0; i=1;
    while( n > 0 )
    {
    	rem = n % 2;
    	bin = bin + (rem * i);
        n = n / 2;
    	i*=10;
    	count++;
    }
    printf("binary Equivalent = %d\n",bin);
}

void binary_to_decimal(int n)
{
    int j, no, i, rem;
    int k;
    no = 0;i=0;
    if (n < 0)
        n *= -1;
    while(n > 0)
    {
        rem = n % 10;
        no += (rem * pow(2,i));
        n = n / 10;
        i++;
    }
    printf("\nThe equivalent decimal no = %d",no);
}






























/*
*#git123@?
*/
