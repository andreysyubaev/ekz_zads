#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <conio.h>
#include <windows.h>
#include <ctime>

int main()
{
    srand(time(NULL));
    const char* appNameA = "C:\\Users\\andre\\source\\repos\\ekz\\z20\\child.exe";
    const char* inputFile = "C:\\Users\\andre\\source\\repos\\ekz\\z20\\process_input.txt";


    wchar_t appName[255];
    MultiByteToWideChar(CP_ACP, 0, appNameA, -1, appName, 255);


    STARTUPINFO si;
    PROCESS_INFORMATION pi;

    ZeroMemory(&si, sizeof(STARTUPINFO));
    si.cb = sizeof(STARTUPINFO);

    FILE* input;
    if ((input = fopen(inputFile, "w")) == NULL) {
        perror("ошибка при открытии файла для записи");
        return 0;
    }
    fprintf(input, "%d", 10 + rand() % 100);
    fclose(input);

    if (!CreateProcess(
        NULL,
        appName,
        NULL,
        NULL,
        TRUE,
        CREATE_NEW_CONSOLE,
        NULL,
        NULL,
        &si,
        &pi))
    {
        _cputs("процесс не создан");
        _getch();
        return 0;
    }
    _cputs("процесс создан");

    WaitForSingleObject(pi.hProcess, INFINITE);

    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);

    return 0;
}
