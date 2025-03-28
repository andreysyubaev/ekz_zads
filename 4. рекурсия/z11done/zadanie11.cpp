#include <iostream>

void Result(const char *inputFile, const char *outputFile);
void Recursion(char *c, int left, int right);

int main()
{
    const char *input = "C:\\Users\\andre\\source\\repos\\ekz\\z11\\input.txt";
    const char *output = "C:\\Users\\andre\\source\\repos\\ekz\\z11\\reversed.txt";
    Result(input, output);

    return 0;
}

void Recursion(char *c, int left, int right)
{
    if (left >= right)
        return;

    char temp = c[left];
    c[left] = c[right];
    c[right] = temp;

    Recursion(c, left + 1, right - 1);
}

void Result(const char *inputFile, const char *outputFile)
{
    FILE *input, *output;
    char c[256];
    int length = 0;

    if ((input = fopen(inputFile, "r")) == NULL)
    {
        printf("ошибка при открытии файла для чтения\n");
        fclose(input);
        return;
    }

    if ((output = fopen(outputFile, "w")) == NULL)
    {
        printf("ошибка при открытии файла для записи\n");
        fclose(output);
        return;
    }

    if (fgets(c, sizeof(c), input))
    {
        while (c[length] != '\0' && c[length] != '\n')
        {
            length++;
        }
        Recursion(c, 0, length - 1);
        fputs(c, output);
    }

    fclose(input);
    fclose(output);
}