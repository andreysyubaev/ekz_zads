#include <iostream>

void result(const char *inputFile, const char *outputFile);

int main()
{
    const char *input = "C:\\Users\\andre\\source\\repos\\ekz\\z15\\input.txt";
    const char *output = "C:\\Users\\andre\\source\\repos\\ekz\\z15\\output.txt";
    result(input, output);
    return 0;
}

void result(const char *inputFile, const char *outputFile)
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

    char c[255];
    fgets(c, sizeof(c), input);
    int i = 0, j = 0;
    while (c[i] != '\0') {
        if (c[i] != ' ') {
            c[j++] = c[i];
        }
        i++;
    }
    c[j] = '\0';
    fclose(input);

    fprintf(output, "%s", c);
    fclose(output);
}