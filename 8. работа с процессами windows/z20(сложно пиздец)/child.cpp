#include <iostream>
#include <windows.h>
#include <conio.h>
int main(int argc, char* argv[]){
    const char* inputFile = "C:\\Users\\andre\\source\\repos\\ekz\\z20\\process_input.txt";
    const char* outputFile = "C:\\Users\\andre\\source\\repos\\ekz\\z20\\process_output.txt";
    HANDLE hThread;

    hThread = (HANDLE)atoi(argv[1]);

    FILE *input, *output;
    if ((input = fopen(inputFile, "r")) == NULL){
        perror("ошибка при открытии файла для чтения");
        return 0;
    }

    if ((output = fopen(outputFile, "w")) == NULL){
        perror("ошибка при открытии файла для записи");
        return 0;
    }

    int num;
    fscanf(input, "%d", &num);
    fclose(input);
    std::cout << num << " + 10 = ";
    num += 10;
    std::cout << num << std::endl;
    
    fprintf(output, "%d", num);
    fclose(output);

    CloseHandle(hThread);

    return 0;
}