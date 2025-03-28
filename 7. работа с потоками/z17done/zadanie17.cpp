#include <iostream>
#include <windows.h>

DWORD WINAPI threadNumbers(LPVOID);
DWORD WINAPI threadOutput(LPVOID);

int nums[255];
int count = 0;

int main(){
    const char* numbers = "C:\\Users\\andre\\source\\repos\\ekz\\z17\\numbers.txt";
    const char* output = "C:\\Users\\andre\\source\\repos\\ekz\\z17\\output.txt";
    HANDLE hThreadNumbers, hThreadOutput;
    DWORD IDThread1, IDThread2;

    hThreadNumbers = CreateThread(
        NULL,
        0,
        threadNumbers,
        NULL,
        0,
        &IDThread1
    );

    if (hThreadNumbers == NULL) return GetLastError();

    WaitForSingleObject(hThreadNumbers, INFINITE);
    CloseHandle(hThreadNumbers);

    hThreadOutput = CreateThread(
        NULL,
        0,
        threadOutput,
        NULL,
        0,
        &IDThread2
    );

    if (hThreadOutput == NULL) return GetLastError();

    WaitForSingleObject(hThreadOutput, INFINITE);
    CloseHandle(hThreadOutput);

    return 0;
}

DWORD WINAPI threadNumbers(LPVOID){
    FILE *numbers;
    if ((numbers = fopen("C:\\Users\\andre\\source\\repos\\ekz\\z17\\numbers.txt", "r")) == NULL){
        printf("ошибка при открытии файла для чтения\n");
        return 0;
    }

    while(fscanf(numbers, "%d", &nums[count]) == 1){
        count++;
    }

    fclose(numbers);
    return 0;
}

DWORD WINAPI threadOutput(LPVOID){
    FILE *output;
    if ((output = fopen("C:\\Users\\andre\\source\\repos\\ekz\\z17\\output.txt", "w")) == NULL){
        printf("ошибка при открытии файла для записи\n");
        return 0;
    }

    for (int i = 0; i < count; i++){
        fprintf(output, "%d\n", nums[i]);
    }

    fclose(output);
    return 0;
}
