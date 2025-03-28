#include <iostream>
#include <stdio.h>

#define SQUARE(x) ((x) * (x))
int count = 0;

void Result(const char* inputFileName, const char* outputFileName);

int main(){
    const char* inputFileName = "C:\\Users\\andre\\source\\repos\\ekz\\z7done\\input.txt";
    const char* outputFileName = "C:\\Users\\andre\\source\\repos\\ekz\\z7done\\output.txt";
    Result(inputFileName, outputFileName);

    return 0;
}

void Result(const char* inputFileName, const char* outputFileName){
    FILE *inputFile, *outputFile;
    int number;
    
    if ((inputFile = fopen(inputFileName, "r")) == NULL){
        std::cout << "Ошибка чтения из файла" << std::endl;
        return;
    }

    if ((outputFile = fopen(outputFileName, "w")) == NULL){
        std::cout << "Ошибка записи в файл" << std::endl;
        fclose(inputFile);
        return;
    }

    while (fscanf(inputFile, "%d", &number) == 1){
        int square = SQUARE(number);
        fprintf(outputFile, "%d\n", square);
    }

    fclose(inputFile);
    fclose(outputFile);
}