#include <cs50.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
    string name;
    int vote;
}
candidate;

int main(void)
{
    const int n = get_int("How many candidate are there? " );
    candidate candidates[n];

    for (int j = 0; j < n; j++)
    {
        candidates[j].name = get_string("Enter candidate %i name: ", j + 1);
        candidates[j].vote = get_int("Enter candidate %i votes: ", j + 1);
    }

    // candidates[0].name = "Erphan";
    // candidates[0].vote = 21;

    // candidates[1].name = "Amir";
    // candidates[1].vote = 15;

    // candidates[2].name = "Ali";
    // candidates[2].vote = 20;

    // candidates[3].name = "Pouya";
    // candidates[3].vote = 5;

    int max = 0;
    int index = 0;

    for (int i = 0; i < 4; i++)
    {
        if (candidates[i].vote > max)
        {
            max = candidates[i].vote;
            index = i;
        }
    }
    printf("%s won with %i votes!\n", candidates[index].name, max );
}
