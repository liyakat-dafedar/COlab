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
        printf("\n1:Decimal to binary\n2:binary to decimal\n3:Exit\n\tEnter your choice(1-3):\t");
        scanf("%d",&choice);
        switch(choice)
        	{
	            case 1 : printf("Enter the decimal number\t:");
	                     scanf("%d",&no);
	                     decimal_to_binary(no);
	                     break;
	            case 2 : printf("Enter the binary number(enter 2 to stop):\n");
	                     printf("Enter the binary no:\t");
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
    int  j, i, a[10], rem, bin;
    bin = 0; i=1;
    if (n < 0)
        n *= -1;
    // n = (int)m
    // m = m - n;
    while( n > 0 )
    {
    	rem = n % 2;
    	bin = bin + (rem * i);
        n = n / 2;
    	i*=10;
    }
    printf("binary Equivalent = %d\n",bin);
    // if (m != 0)
    // {
    //     int binf, j;
    //     j = 1; binf = 0;
    //     while( int(m) != 1 )
    //     {
    //         m = m * 2;
    //         binf = binf + (j * int(m));
    //         j = j * 10;
    //     }
    // }
}

void binary_to_decimal(int n)
{
    int no ,i , rem;
    no = 0; i=0;
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
