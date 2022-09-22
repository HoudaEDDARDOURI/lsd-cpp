#include <stdio.h>
#include <stdlib.h>

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
    int n = 0, m = 0;
    printf("enter an integer m : ");
    scanf("%d",&m);
    printf("which byte : ");
    scanf("%d",&n);
    // print the binary representation of m
    printf("here's the binary representation of the integer m : \n");
    for(int i = 31; i>-1;i--)
    {
        if( (m & (1<<i)) != 0)
            printf("1");
        else 
            printf("0");
    }
    printf("\n");
    printf("here's the %dth byte of the integer : \n",n);
    print_nth_byte(n,m);
    
    return 0;
}