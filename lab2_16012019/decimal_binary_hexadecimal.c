#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
void decimal_to_hexadecimal(int);
void binary_to_hexadecimal(char []);
void hexadecimal_to_decimal(char []);
void hexadecimal_to_binary(char []);
int binary_to_decimal(char []);
char hex[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
int main()
{
    int no, choice;
    char n[40];
    while(1)
    {
        printf("\n1:Decimal to HexaDecimal\n2:Binary to HexaDecimal\n3:HexaDecimal to Decimal\n4:HexaDecimal to Binary\n5:Exit\n\tEnter your choice(1-5):\t");
        scanf("%d",&choice);
        switch(choice)
        	{
	            case 1 : printf("Enter the decimal number\t:");
	                     scanf("%d",&no);
	                     decimal_to_hexadecimal(no);
	                     break;
	            case 2 : printf("Enter the binary no:\t");
                         scanf("%s",&n);
	                     printf("HexaDecimal Equivalent = ");
	                     binary_to_hexadecimal(n);
	                     break;
	            case 3 : printf("Enter the HexaDecimal number\t:");
	                     scanf("%s",&n);
	                     hexadecimal_to_decimal(n);
	                     break;
	            case 4 : printf("Enter the HexaDecimal no:\t");
                         scanf("%s",&n);
	                     hexadecimal_to_binary(n);
	                     break;
	            case 5 : exit(0);
	            default : printf("\nEnter valid option:\t");
	                      break;
        	}
    }
    return 0;
}
void decimal_to_hexadecimal(int n)
{
    char ch[10], temp[10];
    int  i, j, rem, len;
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
    printf("HexaDecimal Equivalent = %s",temp);
}

int binary_to_decimal(char bin[])
{
    int j, no, i;
    no = 0;i=0;
    for(j=3;j>=0;j--,i++)
    {
        no += ((bin[j]-'0') * pow(2,i));
    }
    return no;
}


void binary_to_hexadecimal(char bin[])
{
    int i,j, decimal, count, lenb, norm;
    char temp[40], normb[40];
    i = 0; count = 0; norm = 16;
    lenb = strlen(bin);
    // can normalize only 16 bits
    for (j = 0; j < norm - lenb; ++j)
    {
    	normb[j] = '0';
    }
    normb[j] = '\0';
    strcat(normb,bin);
    printf("#-%s-#\n",normb );
    for (i = 0; i < norm;i++)
    {
    	temp[count] = normb[i];
    	++count;
    	if (count % 4 == 0)
    	{
    		temp[4] = '\0';
    		decimal = binary_to_decimal(temp);
    		printf("%c ",hex[decimal] );
    		count = 0;
    	}
    }

}

void hexadecimal_to_decimal(char dec[])
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
        no += ( n[j]* pow(16,i));
    }
    printf("Decimal Equivalent = %d\n",no );
}


void hexadecimal_to_binary(char [])
{
	
}