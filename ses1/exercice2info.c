#include <stdio.h>

int main()
{
    
    int x = 0 ;
    printf("enter a number :");
    scanf("%d",&x);
    print_bits(x);
    return 0;
}
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
