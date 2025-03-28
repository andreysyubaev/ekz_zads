#include <iostream>

void result(const char* inputFile, const char* outputFile);

int main(){
    const char* input = "C:\\Users\\andre\\source\\repos\\ekz\\z12\\input.txt";
    const char* output = "C:\\Users\\andre\\source\\repos\\ekz\\z12\\sum_digits.txt";
    result(input, output);
    return 0;
}

int recursion(int n){
    if (n == 0) return 0;
    return n % 10 + recursion(n / 10);
}

void result(const char* inputFile, const char* outputFile){
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

    int n, sum;
    while (fscanf(input, "%d", &n) == 1){
        sum = recursion(n);
    }

    fprintf(output, "%d", sum);

    fclose(input);
    fclose(output);
}