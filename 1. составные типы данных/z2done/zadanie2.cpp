#include <iostream>
#include <cstring>

void Weekday(const char *inputFile, const char *outputFile);

int main()
{
    const char *input = "days.txt";
    const char *output = "weekend_days.txt";
    Weekday(input, output);
    return 0;
}

void Weekday(const char *inputFile, const char *outputFile)
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

    char c[256];
    while (fscanf(input, "%255s", c) == 1)
    {
        if (strcmp(c, "суббота") == 0 || strcmp(c, "воскресенье") == 0)
        {
            printf("%s - выходной\n", c);
            fprintf(output, "%s - выходной\n", c);
        }
        else
        {
            printf("%s - обычный день\n", c);
            fprintf(output, "%s - обычный день\n", c);
        }
    }

    fclose(input);
    fclose(output);
}