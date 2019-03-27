#include<stdio.h>
#include<string.h>
#include<math.h>
void add(char[], char[]);
void decimal_to_binary(int, char[]);
void bhootsAlgorithm(char[], char[]);
void two_s_complement(char[]);
void sub(char[],char[]);
char shift(char[]);
char twoshift(char[],char[]);
void display(char[],char[]);
void normalize(char[],char[]);
int main()
{
    int n1,n2;
    char bin1[20], bin2[20],bin3[20],bin4[20], q;
    printf("\tEnter the first number: ");
    scanf("%d",&n1);
    decimal_to_binary(n1,bin1);
    printf("\tEnter the second number: ");
    scanf("%d",&n2);
    if (n1==0 || n2==0)
    {
        printf("\tThe equivalent decimal no = 0\n");
        return 0;
    }
    decimal_to_binary(n1<0?(-1*n1):n1,bin1);
    decimal_to_binary(n2<0?(-1*n2):n2,bin2);
    normalize(bin1,bin2);
    if (n1<0) two_s_complement(bin1);
    if (n2<0) two_s_complement(bin2);
    bhootsAlgorithm(bin1,bin2);
}
void decimal_to_binary(int n, char bin[])
{
    int  j, i, rem, len;
    char btemp[20]; i=0;
    while( n > 0 )
    {
    	rem = n % 2;
        if (rem == 0)   btemp[i] = '0';
        else    btemp[i] = '1';
        n = n / 2;
    	i++;
    }
    btemp[i] = '\0';    len = strlen(btemp);
    for(i=len-1,j=0;i>=0;i--,j++)
        bin[j] = btemp[i];
    if (strlen(bin) > len)
        bin[len] = '\0';
}

void bhootsAlgorithm(char M[], char Q[])
{
    char A[20], Qminus1, Q0;
    int count,len, i,k;
    count = strlen(Q);  len = count - 1;
    Qminus1 = '0';  Q0 = Q[len];
    for(i=0;i<count;i++)
        A[i] = '0';
    A[i] = '\0';
    printf("\n     \tA = %s\tQ = %s\tQ-1=%c\tM= %s\t=>Initialization\n\n",A,Q,Qminus1,M);
    for(i=0;i<=count-1;i++)
    {
        if (Q0 == '1' && Qminus1 == '0')
        {
            sub(A,M);
            printf("[1,0]:\tA = %s\tQ = %s\tQ-1=%c\tM= %s\t=>A=A-M\n",A,Q,Qminus1,M);
            Qminus1 = twoshift(A,Q);
            printf("[1,0]:\tA = %s\tQ = %s\tQ-1=%c\tM= %s\t=>Arithmetic right shift\n",A,Q,Qminus1,M);
            Q0 = Q[len];
        }
        else if (Q0 == '0' && Qminus1 == '1')
        {
            add(A,M);
            printf("[0,1]:\tA = %s\tQ = %s\tQ-1=%c\tM= %s\t=>A=A+M\n",A,Q,Qminus1,M);
            Qminus1 = twoshift(A,Q);
            printf("[0,1]:\tA = %s\tQ = %s\tQ-1=%c\tM= %s\t=>Arithmetic right shift\n\n",A,Q,Qminus1,M);
            Q0 = Q[len];
        }
        else if (Q0 ==  Qminus1)
        {
            Qminus1 = twoshift(A,Q);
            printf("[%c,%c]:\tA = %s\tQ = %s\tQ-1=%c\tM= %s\t=>Arithmetic right shift\n\n",Q0,Qminus1,A,Q,Qminus1,M);
            Q0 = Q[len];
        }
    }
    A[i] = '\0';    M[i] = '\0';
    display(A,Q);
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
        if (bin2[i] == '0')     bin2[i] = '1';
        else    bin2[i] = '0';
    }
    for(i=0;i<strlen(bin);i++)
        bin[i] = bin2[i];
}
void add(char bin1[], char bin2[])
{
    char bin3[50];    int len,i,carry;
    len = strlen(bin1);
    for(i=strlen(bin1)-1;i>=0;i--)
    {
        if (bin1[i] == '1' && bin2[i] == '1')
        {
            if (carry == 1)
            {   bin3[i] = '1';  carry = 1;  }
            else
            {   bin3[i] = '0';  carry = 1;  }
        }
        else if ((bin1[i] == '0' && bin2[i]=='1') || (bin2[i] == '0' && bin1[i]=='1'))
        {
            if (carry == 1)
            {   bin3[i] = '0';  carry = 1;  }
            else
            {   bin3[i] = '1';  carry = 0;  }
        }
        else
        {
            if (carry == 1)
            {   bin3[i] = '1';  carry = 0;  }
            else
            {   bin3[i] = '0';  carry = 0;  }
        }
    }
    bin3[len] = '\0';
    for(i=0;i<strlen(bin1);i++)
        bin1[i] = bin3[i];
}
void sub(char bin1[],char bin2[])
{
    char b3[30];
    int i;
    for(i=0;i<strlen(bin1);i++)
        b3[i] = bin2[i];
    b3[i] = '\0';
    two_s_complement(b3);
    printf("",b3);
    add(bin1,b3);
}
char twoshift(char a[],char b[])
{
    int i, len;
    char qm, c[20], d[20];
    len = strlen(a) - 1;    qm = a[len];
    for (i = 0; i < len; ++i)
       { c[i] = a[i];   d[i] = b[i];   }
    for (i = 0; i < len; ++i)
        a[i+1] = c[i];
    b[0] = qm;  qm = b[len];
    for (i = 0; i < len; ++i)
        b[i+1] = d[i];
    return qm;
}
void display(char a[],char b[])
{
    int no, i, rem, j;
    no = 0; strcat(a,b); i=strlen(a)-1; j=0;
    while(i>=0)
    {
        no += (((int)(a[i]-48)) * pow(2,j));
        i--;    j++;
    }
    printf("\tThe equivalent decimal no = %d\n",no);
}
void normalize(char a[], char b[])
{
    int len1, len2, i, len;
    char c[20], n1[2],n2[2];
    n1[0] = '0'; n1[1] = '\0';
    n2[0] = '0'; n2[1] = '\0';
    strcat(n1,a);   strcpy(a,n1);
    strcat(n2,b);   strcpy(b,n2);
    len1 = strlen(a);   len2 = strlen(b);
    if (len1 == len2)   return;
    else
    {
        len = (len1<len2)?(len2-len1):(len1-len2);
        if (len1 < len2)
        {
            for(i=0;i<len;i++)
                c[i] = '0';
            c[i] = '\0';
            strcat(c,a);    strcpy(a,c);
        }
        else
        {
            for(i=0;i<len;i++)
                c[i] = '0';
            c[i] = '\0';
            strcat(c,b);    strcpy(a,b);
        }
    }
}
