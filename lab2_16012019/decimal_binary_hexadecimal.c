#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
void decimal_to_hexadecimal_octal(int);
void binary_to_hexadecimal_octal(char []);
int octal_hexadecimal_to_decimal(char []);
void octal_hexadecimal_to_binary(char []);
int binary_to_decimal(char []);
int decimal_to_binary(char []);
char hex[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
int base = 16;
int main()
{
    int no, choice;
    char n[40], n1[100];
    while(1)
    {
        printf("\n\n1:Decimal to HexaDecimal\n2:Binary to HexaDecimal\n3:HexaDecimal to Decimal\n4:HexaDecimal to Binary");
        printf("\n\n5:Decimal to Octal\n6:Binary to Octal\n7:Octal to Decimal\n8:Octal to Binary\n9:Exit\n\tEnter your choice(1-5):\t");

        scanf("%d",&choice);

        switch(choice)
        	{
	            case 1 : printf("\nEnter the decimal number\t:");
	                     scanf("%d",&no);
	                     base = 16;
	                     decimal_to_hexadecimal_octal(no);
	                     break;
	            case 2 : printf("\nEnter the binary no:\t");
                         scanf("%s",n);
                         base = 16;
	                     printf("\n\tHexaDecimal Equivalent = ");
	                     binary_to_hexadecimal_octal(n);
	                     break;
	            case 3 : printf("\nEnter the HexaDecimal number\t:");
	                     scanf("%s",n);
	                     base = 16;
	                     printf("\n\tDecimal Equivalent = %d\n",octal_hexadecimal_to_decimal(n));
	                     break;
	            case 4 : printf("\nEnter the HexaDecimal no:\t");
                         scanf("%s",n1);
                         base = 16;
	                     octal_hexadecimal_to_binary(n1);
	                     break;
                case 5 : printf("\nEnter the decimal number\t:");
	                     scanf("%d",&no);
	                     base = 8;
	                     decimal_to_hexadecimal_octal(no);
	                     break;
	            case 6 : printf("\nEnter the binary no:\t");
                         scanf("%s",n);
                         base = 8;
	                     printf("\n\tOctal Equivalent = ");
	                     binary_to_hexadecimal_octal(n);
	                     break;
	            case 7 : printf("\nEnter the Octal number\t:");
	                     scanf("%s",n);
	                     base = 8;
	                     printf("\n\tDecimal Equivalent = %d\n",octal_hexadecimal_to_decimal(n));
	                     break;
	            case 8 : printf("\nEnter the Octal no:\t");
                         scanf("%s",n1);
                         base = 8;
	                     octal_hexadecimal_to_binary(n1);
	                     break;
	            case 9 : exit(0);
	            default : printf("\nEnter valid option:\t");
	                      break;
        	}
    }
    return 0;
}
void decimal_to_hexadecimal_octal(int n)
{
    char ch[10], temp[10];
    int  i, j, rem, len;
    i = 0;
    while(n > 0)
    {
        rem = n % base;
        ch[i] = hex[rem];
        n = n / base;
        i++;
    }
    ch[i] = '\0';
    len = strlen(ch);
    for(j=0;j<len;j++)
        temp[j] = ch[len - j - 1];

    temp[j] = '\0';
    if (base == 16)
    printf("\n\tHexaDecimal Equivalent = %s",temp);
    else
    printf("\n\tOctal Equivalent = %s",temp);
}

int binary_to_decimal(char bin[])
{
    int j, no, i, k;
    no = 0;i=0;
    if (base == 16)
    k = 3;
    else
    k = 2;
    for(j=k;j>=0;j--,i++)
    {
        no += ((bin[j]-'0') * pow(2,i));
    }
    return no;
}


void binary_to_hexadecimal_octal(char bin[])
{
    int i,j, decimal, count, lenb, norm, no;
    char temp[40], normb[40];
    i = 0; count = 0;
    if (base == 16)
    {
        norm = 16;
        no = 4;
    }
    else
    {
        norm = 15;
        no = 3;
    }
    lenb = strlen(bin);
    // can normalize only 16 bits

    norm = lenb + (no - (lenb % no));
    for (j = 0; j < norm - lenb; ++j)
    {
    	normb[j] = '0';
    }
    normb[j] = '\0';
    strcat(normb,bin);
    //printf("#-%s-#\n",normb );
    for (i = 0; i < norm;i++)
    {
    	temp[count] = normb[i];
    	++count;
    	if (count % no == 0)
    	{
    		temp[no] = '\0';
    		decimal = binary_to_decimal(temp);
    		printf("%c ",hex[decimal] );
    		count = 0;
    	}
    }

}

int octal_hexadecimal_to_decimal(char dec[])
{
	int j, no, i, n[40], len;
    no = 0; i = 0; len = strlen(dec);
    for (i = 0; i < len; ++i)
    {
    	if (dec[i] == 'A')
    		n[i] = 10;
    	else if (dec[i] == 'B')
    		n[i] = 11;
    	else if (dec[i] == 'C')
    		n[i] = 12;
    	else if (dec[i] == 'D')
    		n[i] = 13;
    	else if (dec[i] == 'E')
    		n[i] = 14;
    	else if (dec[i] == 'F')
    		n[i] = 15;
    	else
    	{
    			n[i] = (int)dec[i] - 48;
    	}
    }
    i = 0;
    for(j=len-1;j>=0;j--,i++)
    {
        no += ( n[j]* pow(base,i));
    }
    //printf("Decimal Equivalent = %d\n",no );
    return no;
}


void octal_hexadecimal_to_binary(char hexadecimal[])
{
	long unsigned int n, bin, rem, dec;
	n = octal_hexadecimal_to_decimal(hexadecimal);
	printf("-%d-",n);
	bin = 0; dec = 1;
    while(n > 0)
	{
		rem = n % 2;
		bin = bin + (rem * dec);
		//printf("--%ul--",bin);
		dec *= 10;
		n /=2;
	}
	printf("\n\tBinary Equivalent = %d\n",bin );
}
