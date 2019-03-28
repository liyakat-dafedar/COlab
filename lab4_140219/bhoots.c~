#include<stdio.h>
#include<string.h>
void add(char[], char[]);
void decimal_to_binary(int, char[]);
void bhootsAlgorithm(char[], char[]);
void two_s_complement(char[]);
void sub(char[],char[]);
char shift(char[]);
char twoshift(char[],char[]);
void display(char[],char[]);
int main()
{
    int i,n1,n2,n3,n4;
    char bin1[10], bin2[10],bin3[10],bin4[10], q;
    printf("Enter the first number:");
    scanf("%d",&n1);
    decimal_to_binary(n1,bin1);
    printf("Enter the second number:");
    scanf("%d",&n2);
    //n1=6; n3 = n1*-1;
    //n2=-5;

    if (n1 < 0)
    {
        n3 = -1*n1;
        decimal_to_binary(n3,bin1);

        bin3[0]='0';
        bin3[1] = '\0';
        strcat(bin3,bin1);
        strcpy(bin1,bin3);

        //printf("binary Equivalent(M) = %s\n",bin1);
        two_s_complement(bin1);
        //printf("binary Equivalent(M) = %s\n",bin1);
    }
    else
    {
        decimal_to_binary(n1,bin1);
        bin3[0]='0';
        bin3[1] = '\0';
        strcat(bin3,bin1);
        strcpy(bin1,bin3);
    }
    if (n2 < 0)
    {
        n4 = -1*n2;
        decimal_to_binary(n4,bin2);

        bin4[0]='0';
        bin4[1] = '\0';
        strcat(bin4,bin2);
        strcpy(bin2,bin4);

        //printf("binary Equivalent(M) = %s\n",bin1);
        two_s_complement(bin2);
        printf("binary Equivalent(M) = %s\n",bin2);
    }
    else
    {
        decimal_to_binary(n2,bin2);
        bin4[0]='0';
        bin4[1] = '\0';
        strcat(bin4,bin2);
        strcpy(bin2,bin4);
    }

    printf("binary Equivalent(M) = %s\n",bin1);
    printf("binary Equivalent(Q) = %s\n",bin2);
    //sub(bin3,bin2);
//printf("binary Equivalent3 = %s--\n",bin3);
    bhootsAlgorithm(bin1,bin2);
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
    if (strlen(bin) > len)
        bin[len] = '\0';
}

void bhootsAlgorithm(char M[], char Q[])
{

    char A[5], Qminus1, Q0, Q_[2];
    int count,len, i,k;
    count = strlen(Q);   Qminus1 = '0';  Q0 = Q[count - 1];
    len = count - 1;
    for(i=0;i<count;i++)
        A[i] = '0';

    A[i] = '\0';
    printf("A = %s\tQ = %s\tQ-1=%c\tM= %s\t=>Initialization\n\n",A,Q,Qminus1,M);
    for(i=0;i<=count-1;i++)
    {
        if (Q0 == '1' && Qminus1 == '0')
        {
            sub(A,M);
            printf("[1,0]:A = %s\tQ = %s\tQ-1=%c\tM= %s\t=>A=A-M\n",A,Q,Qminus1,M);
            Qminus1 = twoshift(A,Q);
            printf("[1,0]:A = %s\tQ = %s\tQ-1=%c\tM= %s\t=>Arithmetic right shift\n-7\n",A,Q,Qminus1,M);
            Q0 = Q[3];
        }
        else if (Q0 == '0' && Qminus1 == '1')
        {
            add(A,M);
            //printf("\nSum:%s\n",A);
            printf("[0,1]:A = %s\tQ = %s\tQ-1=%c\tM= %s\t=>A=A+M\n",A,Q,Qminus1,M);
            Qminus1 = twoshift(A,Q);
            printf("[0,1]:A = %s\tQ = %s\tQ-1=%c\tM= %s\t=>Arithmetic right shift\n\n",A,Q,Qminus1,M);
            Q0 = Q[3];
        }
        else if (Q0 ==  Qminus1)
        {
            //printf("[ , ]:A = %s\tQ = %s\tQ-1=%c\tM= %s\n",A,Q,Qminus1,M);
            Qminus1 = twoshift(A,Q);
            printf("[ , ]A = %s\tQ = %s\tQ-1=%c\tM= %s\t=>Arithmetic right shift\n\n",A,Q,Qminus1,M);
            Q0 = Q[3];
        }
    }
    A[i] = '\0';    M[i] = '\0';
    //printf("binary Equivalent1 f= %s\n",A);
    //printf("binary Equivalent2 f= %s\n",M);
    display(A,M);
}

char shift(char arr[])
{
    int i;
    char atemp[20], Qm;
    for(i=0;i<strlen(arr);i++)
        atemp[i] = arr[i];
    Qm = arr[(strlen(arr)-1)];
    atemp[i] = '\0';
    for(i=0;i<strlen(arr)-1;i++)
        arr[i+1] = atemp[i];
    return(Qm);
}

void two_s_complement(char bin[])
{
    int i, len, f, pos;
    f = 0;
    char bin2[20];
    for(i=0;i<strlen(bin);i++)
        bin2[i] = bin[i];

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
    for(i=0;i<strlen(bin);i++)
    {
        bin[i] = bin2[i];
    }
    //add(bin2,bin2);
    //printf("---%s---",bin );
}
void add(char bin1[], char bin2[])
{
    char bin3[50];    int len,i,carry;
    len = strlen(bin1);
    for(i=3;i>=0;i--)
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
 //      printf("\nbin3:%s",bin1);
}


void sub(char bin1[],char bin2[])
{
    char b3[5];
    int i;
    for(i=0;i<5;i++)
        b3[i] = bin2[i];
    b3[i] = '\0';
    two_s_complement(b3);
    add(bin1,b3);
    //printf("bin1 = %s\n",bin1);
}
char twoshift(char a[],char b[])
{
    int i, len;
    char qm, c[4], d[4];
    len = strlen(a);
    qm = a[len-1];
    for (i = 0; i < 3; ++i)
       { c[i] = a[i];   d[i] = b[i];   }
    for (i = 0; i < 3; ++i)
        a[i+1] = c[i];
    b[0] = qm;
    qm = b[len-1];
    for (i = 0; i < 3; ++i)
        b[i+1] = d[i];
    //printf("\nA=%s,B=%s\n",a,b );
    return qm;
}
void display(char a[],char b[])
{
    printf("a=%s,b=%s");
}
