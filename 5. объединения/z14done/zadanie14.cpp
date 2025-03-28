#include <iostream>
#include <stdio.h>
#include <stdint.h>  

union Data
{
    uint32_t uint32;
    char c[4];
};

void Result(const char* inputFileName, const char* outputFileName);

int main(){
    const char* inputFileName = "C:\\Users\\andre\\source\\repos\\ekz\\z14\\ip_input.txt";
    const char* outputFileName = "C:\\Users\\andre\\source\\repos\\ekz\\z14\\ip_output.txt";
    Result(inputFileName, outputFileName);

    return 0;
}

void Result(const char* inputFileName, const char* outputFileName){
    FILE *inputFile, *outputFile;
    Data data;
    
    if ((inputFile = fopen(inputFileName, "r")) == NULL){
        std::cout << "Ошибка чтения из файла" << std::endl;
        return;
    }

    if ((outputFile = fopen(outputFileName, "w")) == NULL){
        std::cout << "Ошибка записи в файл" << std::endl;
        fclose(inputFile);
        return;
    }

    int a, b, c, d;
    if (fscanf(inputFile, "%d.%d.%d.%d", &a, &b, &c, &d)){

        data.uint32 = (a << 24) | (b << 16) | (c << 8) | d;
        
        fprintf(outputFile, "uint32_t: %u\n", data.uint32);
        fprintf(outputFile, "char[4]: %d.%d.%d.%d\n", (unsigned char)data.c[0], (unsigned char)data.c[1], (unsigned char)data.c[2], (unsigned char)data.c[3]);

        std::cout << "Произошла запись." << std::endl;
    }
    else{
        std::cout << "Ошибка чтения IP-адреса из файла" << std::endl;
    }


    fclose(inputFile);
    fclose(outputFile);
}