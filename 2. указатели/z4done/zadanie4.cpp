#include <iostream>

int* arr = nullptr;
int count = 0;

void Numbers(char fileName[256]);
void Sort();
void SaveToFile(char saveFile[256]);

int main(){
    char fileName[256] = "C:\\Users\\andre\\source\\repos\\ekz\\z4done\\numbers.txt";
    char saveFile[256] = "C:\\Users\\andre\\source\\repos\\ekz\\z4done\\sorted_numbers.txt";
    Numbers(fileName);

    std::cout << "числа из файла" << std::endl;
    for (int i = 0; i < count; ++i){
        std::cout << arr[i] << std::endl;
    }

    Sort();

    SaveToFile(saveFile);

    delete[] arr;
    return 0;
}

void Numbers(char fileName[256]) {
    FILE *file = fopen(fileName, "r");
    if (file == NULL) {
        printf("Не удалось открыть файл для чтения\n");
        return;
    }
    int number;
    while (fscanf(file, "%d", &number) == 1)
        count++;
    fclose(file);

    arr = new int[count];
    file = fopen(fileName, "r");
    if (file == NULL) {
        std::cerr << "Не удалось открыть файл для чтения" << std::endl;
        delete[] arr;
        return;
    }

    for (int i = 0; i < count; ++i) {
        fscanf(file, "%d", &arr[i]);
    }

    fclose(file);
}

void Sort(){
    for (int i = 0; i < count - 1; ++i){
        for (int j = 0; j < count - i - 1; ++j){
            if (arr[j] > arr[j + 1]){
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void SaveToFile(char saveFile[256]){
    FILE *file;
    file = fopen(saveFile, "w");
    if (file == NULL) {
        std::cerr << "Не удалось открыть файл для записи" << std::endl;
        return;
    }
    for (int i = 0; i < count; ++i){
        fprintf(file, "%d\n", arr[i]);
    }
    fclose(file);
    printf("Отсортированные числа записаны в файл\n");
}