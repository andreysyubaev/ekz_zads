#include <iostream>
#include <ctime>

class Car
{
public:
    char name[255];
    int year;
    int probeg;
};

void plusProbeg(const char *inputFIle, const char *outputFIle);

int main()
{
    srand(time(NULL));
    const char *input = "C:\\Users\\andre\\source\\repos\\ekz\\z3\\cars.txt";
    const char *output = "C:\\Users\\andre\\source\\repos\\ekz\\z3\\updated_cars.txt";
    plusProbeg(input, output);

    return 0;
}

void plusProbeg(const char *inputFile, const char *outputFile)
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

    Car car[100];
    int count = 0;

    while (fscanf(input, "%s %d %d", car[count].name, &car[count].year, &car[count].probeg) == 3)
    {
        count++;
    }

    for (int i = 0; i < count; i++)
    {
        int n = 100 + rand() % 901;
        car[i].probeg += n;
        fprintf(output, "%s, %d, %d\n", car[i].name, car[i].year, car[i].probeg);
    }

    fclose(input);
    fclose(output);
}