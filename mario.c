#include <cs50.h>
#include <stdio.h>

int get_height (void);
int main(void)
{
    int x = get_height();
    for(int i=1; i<= x; i++)
    {
        int n = x - i;
        for(int j=1 ; j<= n ; j++)
        {
            printf(" ");
        }

        for(int k=1; k<=i ; k++)
        {
            printf("#");
        }
        printf("\n");
    }

}





int get_height (void)
{
    int x;
    do
    {
        x = get_int("Height: ");
    }
    while(!(x>=1 && x<=8));
    return x;
}