#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int convert(string x[]);
string cipher(string p, int k);

int main(int argc, string argv[])
{
    // running with one command-line argument
    if (argc == 1 || argc > 2)
    {
        printf("Usage ./caesar key\n");
        return 1;
    }

    int l = strlen(argv[1]);
    for (int i = 0; i < l; i++)
    {
        if (argv[1][i] >= 'a' && argv[1][i] <= 'z')
        {
            printf("Usage ./caesar key\n");
            return 1;
        }
        else if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
        {
            printf("Usage ./caesar key\n");
            return 1;
        }
    }

    // converting a sring to an int
    int key = convert(argv);
    // prompt user for input
    string plaintext = get_string("plaintext: ");
    // convert plain text to cypertext
    string ciphertext = cipher(plaintext, key);
    // print result
    printf("ciphertext: %s\n", ciphertext);
}

int convert(string x[])
{
    int a = atoi(x[1]);
    return a;
}

string cipher(string p, int k)
{
    int l = strlen(p);
    for (int i = 0; i < l; i++)
    {
        char r = p[i];
        int s = k + r;
        if (r == ' ' || r == '!' || r == '?' || r == ',')
        {
            p[i] = r;
        }
        else if (r > 65 && r < 90)
        {
            if (s > 90)
            {
                p[i] = r + k - 26;
            }
            else
            {
                p[i] = r + k;
            }
        }
        else
        {
            if (s > 122 && s <= 148)
            {
                p[i] = r + k - 26;
            }
            else if (s > 148 && s <= 174)
            {
                p[i] = r + k - 52;
            }
            else if (s >= 176 && s <= 191)
            {
                p[i] = r + k - 78;
            }
            else
            {
                p[i] = r + k;
            }
        }
    }
    return (p);
}
