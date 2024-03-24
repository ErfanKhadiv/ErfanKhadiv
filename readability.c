#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int words_count(string text);
int letters_count(string text);
int sentances_count(string text);

int main(void)
{
    // prompt the user for text
    string text = get_string("Please enter your text: ");

    // counting words
    float words = words_count(text);
    // counting letters
    int letters = letters_count(text);
    // counting sentances
    int sentances = sentances_count(text);

    // l and s
    float L = letters / words * 100;
    float S = sentances / words * 100;

    // index
    float index = 0.0588 * L - 0.296 * S - 15.8;
    int result = round(index);

    // print the result
    if (result < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (result > 1 && result < 16)
    {
        printf("Grade %i\n", result);
    }
    else
    {
        printf("Grade 16+\n");
    }
}

int words_count(string x)
{
    int n = strlen(x);
    char space = ' ';
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (x[i] == space)
        {
            count++;
        }
    }
    int words = count + 1;
    return words;
}

int letters_count(string y)
{
    int n = strlen(y);
    char space = ' ';
    char e = 39;
    int count = n;
    for (int i = 0; i < n; i++)
    {
        if (y[i] == space || y[i] == '.' || y[i] == ',' || y[i] == '!' || y[i] == '?' || y[i] == e)
        {
            count--;
        }
    }
    return count;
}

int sentances_count(string z)
{
    int n = strlen(z);
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (z[i] == '.' || z[i] == '!' || z[i] == '?')
        {
            count++;
        }
    }
    return count;
}
