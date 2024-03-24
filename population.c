#include <cs50.h>
#include <stdio.h>

int get_start(void);
int get_end(int s);
int get_year(int s, int e);
int main(void)
{
    // TODO: Prompt for start size
    int s = get_start();
    // TODO: Prompt for end size
    int e = get_end(s);
    // TODO: Calculate number of years until we reach threshold
    int y = get_year(s, e);
    // TODO: Print number of years
    printf("Years: %d", y);
}




int get_start(void)
{
    int s ;
    do
    {
        s = get_int("Please enter start size: ");
    }
    while(s<9);
    return s;
}

int get_end(s)
{
    int e;
    do
    {
        e = get_int("Please enter end size: ");
    }
    while(e<s);
    return e;
}

int get_year(s, e)
{
    int year = 0;
    while (s< e)
    {
        int born = s/3;
        int die = s/4;
        int avg = born - die;
        s+=avg;
        year+=1;
    }
    return year;

}