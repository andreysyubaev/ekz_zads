#include <iostream>
#include <windows.h>
#include <ctime>

DWORD WINAPI threadRandom_numbers(LPVOID);

int main()
{
    srand(time(NULL));
    HANDLE hThread;
    DWORD IDThread;

    hThread = CreateThread(
        NULL,
        0,
        threadRandom_numbers,
        0,
        NULL,
        &IDThread
    );

    WaitForSingleObject(hThread, INFINITE);
    CloseHandle(hThread);

    return 0;
}

DWORD WINAPI threadRandom_numbers(LPVOID)
{
    FILE *output = fopen("C:\\Users\\andre\\source\\repos\\ekz\\z18\\random_numbers.txt", "w");
    if (!output)
    {
        printf("ошибка при открытии файла для записи\n");
        return 0;
    }

    for (int i = 0; i < 10; i++){
        int n = 100 + rand() % 901;
        printf("%d\n", n);
        fprintf(output, "%d\n", n);
        Sleep(2000);
    }

    fclose(output);
    return 0;
}