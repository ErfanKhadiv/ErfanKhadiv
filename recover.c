#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // Check Input
    if (argc != 2)
    {
        printf("Usage: ./recover card\n");
        return 1;
    }

    char *filename = argv[1];

    // Open memory card
    FILE *card = fopen(filename, "r");

    // Create a buffer for a block of data
    uint8_t buffer[512];

    FILE *img = NULL;
    char file[8];

    // While there's still data left to read from the memory card
    int files_count = 0;
    while (fread(&buffer, 1, 512, card) == 512)
    {
        // Create JPEGs from the data
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
        {
            if (files_count > 0)
            {
                fclose(img);
            }

            sprintf(file, "%03i.jpg", files_count);
            img = fopen(file, "a");
            fwrite(&buffer, 512, 1, img);
            files_count += 1;
        }
        else if (files_count > 0)
        {
            fwrite(&buffer, 512, 1, img);
        }
    }

    fclose(img);
    fclose(card);
}
