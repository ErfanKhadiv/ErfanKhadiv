#include <cs50.h>
#include <stdio.h>

int steps(int N, int c);

int main(void)
{
    int n;
    do
    {
        n = get_int("n: ");
    }
    while(n < 1);

    int count = 0;
    printf("%i steps\n", steps(n, count));
}

int steps(int N, int c)
{
    if (N == 1)
    {
        return c;
    }
    else if (N%2 == 0)
    {
        c = c + 1;
        return steps(N/2, c);
    }
    else
    {
        c = c + 1;
        return steps(3 * N + 1, c);
    }
}
