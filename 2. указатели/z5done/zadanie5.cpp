#include <iostream>

void longest_word(const char *inputFile, const char *outputFile);

int main()
{
    const char *input = "C:\\Users\\andre\\source\\repos\\ekz\\z5\\input.txt";
    const char *output = "C:\\Users\\andre\\source\\repos\\ekz\\z5\\longest_word.txt";
    longest_word(input, output);
    return 0;
}

void longest_word(const char *inputFile, const char *outputFile)
{
    FILE *input, *output;

    if ((input = fopen(inputFile, "r")) == NULL)
    {
        printf("ошибка при открытии файла для чтения\n");
        return;
    }

    if ((output = fopen(outputFile, "w")) == NULL)
    {
        printf("ошибка при открытии файла для записи\n");
        return;
    }

    char word[255];
    char longest[255];
    int maxLength = 0;
    while (fscanf(input, "%255s", word) == 1)
    {
        char *ptr = word;
        int length = 0;

        while (*ptr != '\0')
        {
            length++;
            ptr++;
        }

        if (length > maxLength)
        {
            maxLength = length;
            char *src = word;
            char *dst = longest;
            while (*src != '\0')
            {
                *dst = *src;
                src++;
                dst++;
            }
            *dst = '\0';
        }
    }

    if (maxLength > 0)
    {
        char *ptr = longest;
        while (*ptr != '\0')
        {
            fputc(*ptr, output);
            ptr++;
        }
    }

    fclose(input);
    fclose(output);
}