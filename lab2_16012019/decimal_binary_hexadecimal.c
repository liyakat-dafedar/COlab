#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
void decimal_to_hexadecimal(int);
void binary_to_hexadecimal(int);
int binary_to_decimal(int);
char hex[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
int main()
{
    int no, choice, n;
    while(1)
    {
        printf("\n1:Decimal to HexaDecimal\n2:Binary to HexaDecimal\n3:HexaDecimal to Decimal\n4:HexaDecimal to Binary\n5:Exit\n\tEnter your choice(1-3):\t");
        scanf("%d",&choice);
        switch(choice)
        	{
	            case 1 : printf("Enter the decimal number\t:");
	                     scanf("%d",&no);
	                     decimal_to_hexadecimal(no);
	                     break;
	            case 2 : printf("Enter the binary no:\t");
	                     scanf("%d",&n);
	                     binary_to_hexadecimal(n);
	                     break;
	            case 3 : exit(0);
	            default : printf("\nEnter valid option:\t");
	                      break;
        	}
    }
    return 0;
}
void decimal_to_hexadecimal(int n)
{
    char ch[10], i, j, rem, temp[10], len;
    i = 0;
    while(n > 0)
    {
        rem = n % 16;
        ch[i] = hex[rem];
        n = n / 16;
        i++;
    }
    ch[i] = '\0';
    len = strlen(ch);
    for(j=0;j<len;j++)
        temp[j] = ch[len - j - 1];

    temp[j] = '\0';
    printf("%s",temp);
}

int binary_to_decimal(int n)
{
    int j, no, i, rem, m;
    int k;
    no = 0;i=0;
    m = n;
    while(n > 0)
    {
        rem = n % 10;
        no += (rem * pow(2,i));
        n = n / 10;
        i++;
    }
    printf("%d ",no);
    if (m == 0)
    return 0;
    else
    return no;
}


void binary_to_hexadecimal(int n)
{
    int i, j, decimal, rem, len, p, count, k;
    char ch[10], temp[10];
    i = 0; count = 0;
    p = n;
    while(p > 0)
    {
        count++;
        p = p / 10;
    }
    if (count != 8)
    {
        while(count != 8)
        {
            p = p * 10;
            while(p > 0)
            {
                count++;
                p = p / 10;
            }
        }
    }
    printf("-%d-",p);
    while(n > 0)
    {
        rem = n % 10000;
        decimal = binary_to_decimal(rem);
        ch[i] = hex[decimal];
        n = n / 10000;
        i++;
    }
    ch[i] = '\0';
    len = strlen(ch);
    for(j=0;j<len;j++)
        temp[j] = ch[len - j - 1];
    temp[j] = '\0';
    printf("\nHexadecimal Equivalent = %s",temp);
}



























