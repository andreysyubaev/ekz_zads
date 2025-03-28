#include <iostream>
#include <cstring>

void replace(const char* inputFile, const char* outputFile);

int main(){
    const char* input = "C:\\Users\\andre\\source\\repos\\ekz\\z18\\input.txt";
    const char* output = "C:\\Users\\andre\\source\\repos\\ekz\\z18\\output.txt";
    replace(input, output);
    return 0;
}

void replace(const char* inputFile, const char* outputFile){
    FILE *input, *output;
    if ((input = fopen(inputFile, "r")) == NULL){
        perror("ошибка при открытии файла для чтения");
        return;
    }

    if ((output = fopen(outputFile, "w")) == NULL){
        perror("ошибка при открытии файла для записи");
        return;
    }

    char c[255];
    int i = 0, j = 0;
    while (fgets(c, sizeof(c), input)){
        char* pos = strstr(c, "C++");
        char* start = c;

        while(pos){
            *pos = '\0';
            fputs(start, output);
            fputs("C plus plus", output);

            start = pos + 3;
            pos = strstr(c, "C++");
        }
        fputs(start, output);
    }

    fclose(input);
    fclose(output);
}