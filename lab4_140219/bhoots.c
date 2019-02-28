#include<stdio.h>
#include<string.h>

void decimal_to_binary(int, char[]);
void bhootsAlgorithm(char[], char[]);
void two_s_complement(char bin1[],char bin2[],int operation)
char shift(char[]);
int main()
{
    int n1=12, n2=13;
    char bin1[20], bin2[20], q;
    /*printf("Enter the first number:");
    scanf("%d",&n1);*/
    decimal_to_binary(15,bin1);
    /*printf("Enter the second number:");
    scanf("%d",&n2);*/
    decimal_to_binary(9,bin2);

    printf("binary Equivalent1 = %s\n",bin1);
    printf("binary Equivalent2 = %s\n",bin2);
    q = shift(bin1);
    printf("Q-1=%c\n",q);
    q = shift(bin2);
    printf("Q-1=%c",q);
}

void decimal_to_binary(int n, char bin[])
{
    int  j, i, rem, neg, len;
    char btemp[20];
    i=0;
    while( n > 0 )
    {
    	rem = n % 2;
        if (rem == 0)
            btemp[i] = '0';
        else
            btemp[i] = '1';
        n = n / 2;
    	i++;
    }
    btemp[i] = '\0';
    len = strlen(btemp);
    for(i=len-1,j=0;i>=0;i--,j++)
        bin[j] = btemp[i];

}

void bhootsAlgorithm(char M[], char Q[])
{
    char A[20], Qminus1, Q0, len;
    int count, i;
    count = strlen(M);   Qminus1 = '0';  Q0 = Q[count - 1];
    len = count - 1;
    for(i=0;i<strlen(A);i++)
        A[i] = '0';
    for(i=1;i<=count;i++)
    {
        if (Q0 == '1' && Qminus1 == '0')
        {
            sub(A,M);
            Qminus1 = shift(Q);
        }
        else if (Q0 == '0' && Qminus1 == '1')
        {
            sub(A,M);
            Qminus1 = shift(Q);
        }
        else if (Q0 ==  Qminus1)
        {
            Qminus1 = shift(Q);
        }
    }
}

char shift(char arr[])
{
    int i;
    char atemp[20], Qm;
    for(i=0;i<strlen(arr);i++)
        atemp[i] = arr[i];
    atemp[i] = '\0';    Qm = arr[(strlen(arr) - 1)];
    for(i=0;i<strlen(arr)-1;i++)
        arr[i+1] = atemp[i];
    printf("%s--Qm=%c\n",arr,Qm);
    return(Qm);
}

void two_s_complement(char bin4[],char bin5[])
{
    int n1, n2, i, len, f, pos, carry, n;
    f = 0;  carry = 0;
    char bin1[20], bin2[20];
    for(i=0;i<strlen(bin4);i++)
    {
        bin1[i] = bin4[i];
        bin2[i] = bin4[i];
    }

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
    }
    add(bin1,bin2);
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
    //printf("%c",bin3[0]);
    bin3[len] = '\0';
    for(i=0;i<strlen(bin1);i++)
        bin1[i] = bin3[i];
      // printf("\nbin3:%s",bin3);
}










