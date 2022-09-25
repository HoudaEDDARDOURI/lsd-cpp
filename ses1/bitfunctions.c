#include <stdio.h>
#include "bitfunctions.h"

//exercice 1 
void check_msb(int num)
{
    if( ((1 << 7) & num) != 0)
        printf("msb is set");
    else 
        printf("msb is not set");
}

//exercice 2
void print_bits(int byte)
{
    for(int i = 7;i>-1;i--)
    {
        if( (1 & (byte>>i))  == 1) 
            printf("1");
        else
            printf("0");
    }
}
//exercice 4
void print_nth_byte(int n,int m)
{
    if(n < 5 || n > 1)
    {
        int bit = n * 8;
    
        for(int i = bit - 1; i > bit-9 ; i--)
        {
            if( (m & (1<<i)) != 0)
                printf("1");
            else 
                printf("0");
        }
    }
    else 
        exit(EXIT_FAILURE);
}


int main()
{
    int a = 0, b = 0, m = 0,n = 0;
    printf("enter an integer to check if its most significant bit is set or not  : ");
    scanf("%d",&a);
    check_msb(a);
    printf("\n");
    printf("enter an integer to print it in binary : ");
    scanf("%d",&b);
    print_bits(b);
    printf("\n");
    printf("enter an integer m : ");
    scanf("%d",&m);
    printf("enter the byte n you want : ");
    scanf("%d",&n);
    print_nth_byte(n,m);
    printf("\n");
    
    

    return 0;
} 
