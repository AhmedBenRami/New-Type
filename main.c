#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int width;
    int height;
} Header;
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("%s", (argc < 2) ? "Usage: ./a.exe filename.alpa" : "Too many arguments");
        return 1;
    }
    else
    {
        int len = strlen(argv[1]);
        char extension[6];
        for (int i = 0; i < 5; i++)
        {
            extension[i] = argv[1][len + i - 5];
        }
        extension[5] = 0;
        if (strcmp(extension, ".alpa"))
        {
            printf("This program only support type file of .alpa");
            return 2;
        }
    }
    FILE *image = fopen(argv[1], "rb");
    if (image == NULL)
    {
        printf("Could not open the file, please check if the file does exist or try later");
        return 3;
    }
    Header header;
    fread(&header, sizeof(header), 1, image);

    char buffer;
    int pos = 1;
    while (fread(&buffer, sizeof(char), sizeof(buffer), image))
    {
        // pos += 1;
        if (pos == header.width)
        {
            printf("\n");
            pos = 1;
        }
        // int position = ftell(image) - sizeof(header);
        // if (position % header.width == 1) // 1 because it reads before it calculate position
        // {
        //     printf("\n");
        // }

        printf("%c", (buffer) ? 220 : ' ');
        pos += 1;
    }

    fclose(image);
    return 0;
}
// can i print a pixel?