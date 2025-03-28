#include <iostream>

int main()
{
    FILE *file;
    const char* os_info = "C:\\Users\\andre\\source\\repos\\ekz\\z8\\os_info.txt";

    if ((file = fopen(os_info, "w")) == NULL)
    {
        perror("Ошибка чтения из файла");
        return 0;
    }

    #ifdef _WIN32
        fprintf(file, "Windows detected");
    #else
        fprintf(file, "Linux detected");
    #endif

    fclose(file);
    return 0;
}