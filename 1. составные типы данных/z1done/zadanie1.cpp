#include <iostream>

struct Student
{
    char name[255];
    int age;
    float grade;
};

void sort(const char *inputFile, const char *outputFile);

int main()
{
    const char *input = "C:\\Users\\andre\\source\\repos\\ekz\\z1\\students.txt";
    const char *output = "C:\\Users\\andre\\source\\repos\\ekz\\z1\\sorted_students.txt";
    sort(input, output);

    return 0;
}

void sort(const char *inputFile, const char *outputFile)
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

    Student stu[100];
    int count = 0;

    while (fscanf(input, "%s %d %f", stu[count].name, &stu[count].age, &stu[count].grade) == 3)
    {
        count++;
    }

    for (int i = 0; i < count - 1; i++)
    {
        for (int j = 0; j < count - i - 1; j++)
        {
            if (stu[j].grade < stu[j + 1].grade){
                Student temp = stu[j];
                stu[j] = stu[j + 1];
                stu[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < count; i++)
    {
        printf("%s, %d, %.2f\n", stu[i].name, stu[i].age, stu[i].grade);
        fprintf(output, "%s, %d, %.2f\n", stu[i].name, stu[i].age, stu[i].grade);
    }

    fclose(input);
    fclose(output);
}
