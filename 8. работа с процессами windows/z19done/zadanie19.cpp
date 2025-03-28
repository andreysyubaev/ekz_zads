#include <iostream>
#include <conio.h>
#include <windows.h>

int main()
{
    setlocale(LC_ALL, "Russian");
    char appName[] = "C:\\Windows\\system32\\notepad.exe";

    STARTUPINFO si;
    PROCESS_INFORMATION pi;

    ZeroMemory(&si, sizeof(STARTUPINFO));
    si.cb = sizeof(STARTUPINFO);

    const char *logPath = "C:\\Users\\andre\\source\\repos\\ekz\\z19\\log.txt";
    FILE *log = fopen(logPath, "w");
    if (!log)
    {
        printf("ошибка при открытии файла для записи\n");
        return 0;
    }

    if (!CreateProcess(
            appName,
            NULL,
            NULL,
            NULL,
            FALSE,
            CREATE_NEW_CONSOLE,
            NULL,
            NULL,
            &si,
            &pi))
    {
        _cputs("процесс не создан");
        _cputs("any ket to finish...");
        _getch();

        fprintf(log, "%s\n", "процесс не создан");

        return 0;
    }
    _cputs("процесс создан");
    fprintf(log, "%s\n", "процесс создан");

    WaitForSingleObject(pi.hProcess, 5000);
    TerminateProcess(pi.hProcess, 1);

    CloseHandle(pi.hThread);
    CloseHandle(pi.hProcess);

    fprintf(log, "%s\n", "процесс завершен");
    return 0;
}
