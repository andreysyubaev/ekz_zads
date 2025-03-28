#include <iostream>

void SaveToFile(const char* inputFile, const char* outputFile);

int main(){
    const char* inputFile =     "C:\\Users\\andre\\source\\repos\\ekz\\z10\\fib_input.txt";
    const char* outputFile =    "C:\\Users\\andre\\source\\repos\\ekz\\z10\\fib_output.txt";
    SaveToFile(inputFile, outputFile);

    return 0;
}

int fibonacci(int N){
    if (N == 1 || N == 2)
        return 1;
    return fibonacci(N - 1) + fibonacci(N - 2);
}

void SaveToFile(const char* inputFile, const char* outputFile){
    FILE *input, *output;
    int num;
    if ((input = fopen(inputFile, "r")) == NULL){
        printf("ошибка при открытии файла для чтения\n");
        return;
    }

    if ((output = fopen(outputFile, "w")) == NULL){
        printf("ошибка при открытии файла для записи\n");
        return;
    }

    while(fscanf(input, "%d", &num) == 1){
        for (int i = num; i <= 10; i++){
            //std::cout << fibonacci(i) << std::endl;
            fprintf(output, "%d\n", fibonacci(i));
        }
    }
    fclose(input);
    fclose(output);
}