#include <iostream>

void Result(const char* matrix_sizeFile, const char* matrix_dataFile, const char* transposed_matrixFile);

int main(){
    const char* matrix_size =       "C:\\Users\\andre\\source\\repos\\ekz\\z6\\matrix_size.txt";
    const char* matrix_data =       "C:\\Users\\andre\\source\\repos\\ekz\\z6\\matrix_data.txt";
    const char* transposed_matrix = "C:\\Users\\andre\\source\\repos\\ekz\\z6\\transposed_matrix.txt";
    Result(matrix_size, matrix_data, transposed_matrix);
    return 0;
}

void Result(const char* matrix_sizeFile, const char* matrix_dataFile, const char* transposed_matrixFile){
    FILE *matrix_size, *matrix_data, *transposed_matrix;

    if ((matrix_size = fopen(matrix_sizeFile, "r")) == NULL)
    {
        perror("ошибка при открытии файла для чтения matrix_size\n");
        return;
    }

    if ((matrix_data = fopen(matrix_dataFile, "r")) == NULL)
    {
        perror("ошибка при открытии файла для чтения matrix_data\n");
        return;
    }

    if ((transposed_matrix = fopen(transposed_matrixFile, "w")) == NULL)
    {
        perror("ошибка при открытии файла для записи transposed_matrix\n");
        return;
    }

    int n, m;

    fscanf(matrix_size, "%d %d", &n, &m);
    std::cout << "n = " << n << std::endl << "m = " << m << std::endl;

    fclose(matrix_size);

    // выделение памяти
    int** arr = new int*[n];
    for (int i = 0; i < n; ++i) {
        arr[i] = new int[m];
    }

    // заполнение числами
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j){
            fscanf(matrix_data, "%d", &arr[i][j]);
        }
    }

    fclose(matrix_data);

    // запись
    for (int j = 0; j < m; ++j){
        for (int i = 0; i < n; ++i){
           fprintf(transposed_matrix, "%d ", arr[i][j]);
        }
        fprintf(transposed_matrix, "\n");
    }

    fclose(transposed_matrix);

    // освобождение памяти
    for (int i = 0; i < n; ++i){
        delete[] arr[i];
    }
    delete[] arr;

}