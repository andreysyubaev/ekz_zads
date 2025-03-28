#include <iostream>
#include <stdio.h>

union Data
{
    int a;
    float b;
    char c[4];
};

void Result(const char *inputFileName, const char *outputFileName);

int main()
{

    const char *inputFileName = "C:\\Users\\andre\\source\\repos\\ekz\\z13\\data_input.txt";
    const char *outputFileName = "C:\\Users\\andre\\source\\repos\\ekz\\z13\\data_output.txt";
    Result(inputFileName, outputFileName);

    return 0;
}

void Result(const char *inputFileName, const char *outputFileName)
{
    FILE *inputFile, *outputFile;
    Data data;

    if ((inputFile = fopen(inputFileName, "r")) == NULL)
    {
        std::cout << "Ошибка чтения из файла" << std::endl;
        return;
    }

    if ((outputFile = fopen(outputFileName, "w")) == NULL)
    {
        std::cout << "Ошибка записи в файл" << std::endl;
        fclose(inputFile);
        return;
    }

    if (fscanf(inputFile, "%d", &data.a) == 1)
    {
        fprintf(outputFile, "int: %d\n", data.a);
        fprintf(outputFile, "float: %f\n", data.b);
        fprintf(outputFile, "char: %d%d%d%d\n", (unsigned char)data.c[0], (unsigned char)data.c[1], (unsigned char)data.c[2], (unsigned char)data.c[3]);
        printf("произошла запись.");
    }
    else
    {
        std::cout << "Ошибка чтения числа из файла" << std::endl;
    }

    fclose(inputFile);
    fclose(outputFile);
}