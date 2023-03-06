#include <iostream>

int K = 6;
int G = 2;

int min(int* arr, int size){
    int min = arr[0];
    for(int i = 1; i < size; i++){
        if(arr[i] < min){
            min = arr[i];
        }
    }
    return min;
}

int max(int* arr, int size){
    int max = arr[0];
    for(int i = 1; i < size; i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }
    return max;
}

void histogram(int* arr, int size){
    for(int i = 0; i < size; i++){
        std::cout << "a[" << i << "]=" << arr[i] << " ";
        for(int j = 0; j < arr[i]; j++){
            std::cout << "+";
        }
        std::cout << '\n';
    }
}

int linear_search(int* arr, int size, int value){
    for(int i = 0; i < size; i++){
        if(arr[i] == value){
            return i;
        }
    }
    return -1;
}

void bouble_sort(int* arr, int size){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size - 1; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}


int* sort(int* arr, int size){

    std::cout << "Як сортувати масив:\n";
    std::cout << "1. Сортувати по спаданню\n";
    std::cout << "2. Сортувати за зростанням\n";
    int sort_type;
    std::cin >> sort_type;

    std::cout << "Яку частину масиву сортувати:\n";
    std::cout << "1. Сортувати увесь масив\n";
    std::cout << "2. Сортувати ту частину масиву, елементи якої знаходяться між мінімальним та максимальним значенням масиву до сортування. Решта масиву залишається.\n";
    std::cout << "3. Сортувати масив в частині між порядковими номерами, що задаються користувачем\n";

    int sort_part;
    std::cin >> sort_part;

    int* new_arr = new int[size];
    for(int i = 0; i < size; i++){
        new_arr[i] = arr[i];
    }

    if(sort_part == 2){
        int minimal = min(arr, size);
        int maximum = max(arr, size);
        int start = linear_search(new_arr, size, minimal);
        int end = linear_search(new_arr, size, maximum);
        size = end - start + 1;
        for (int i = 0; i < size; i++){
            new_arr[i] = arr[start + i];
        }
    }else if(sort_part == 3){
        int start;
        std::cout << "Введіть початковий індекс: ";
        std::cin >> start;
        int end;
        std::cout << "Введіть кінцевий індекс: ";
        std::cin >> end;
        size = end - start + 1;
        for (int i = 0; i < size; i++){
            new_arr[i] = arr[start + i];
        }
    }

    bouble_sort(new_arr, size);

    if(sort_type == 1){
        int* reversed_arr = new int[size];
        for(int i = 0; i < size; i++){
            reversed_arr[i] = new_arr[size - i - 1];
        }
        return reversed_arr;
    }

    std::cout << "\nСортований масив: ";
    for(int i = 0; i < size; i++){
        std::cout << new_arr[i] << " ";
    }
    return new_arr;

}


int main(){
    #ifdef _WIN32
        setlocale(LC_ALL, "Russian");
        SetConsoleOutputCP(866);
    #endif

    srand(time(NULL));
    int arr_size;
    std::cout << "Кількість елементів масиву для подальшої роботи: ";
    std::cin >> arr_size;
    int* arr = new int[arr_size];
    for(int i = 0; i < arr_size; i++){
        arr[i] = rand() % (4*K);
    }

    std::cout << "Масив: ";
    for(int i = 0; i < arr_size; i++){
        std::cout << arr[i] << " ";
    }

    std::cout << "\nМінімальне значення: " << min(arr, arr_size);

    std::cout << "\nГістограма: \n";
    histogram(arr, arr_size);

    int search_value;
    std::cout << "\nВведіть значення для пошуку: ";
    std::cin >> search_value;
    int index = linear_search(arr, arr_size, search_value);
    if(index == -1){
        std::cout << "Значення не знайдено";
    } else {
        std::cout << "Значення знайдено на позиції " << index;
    }

    int* dupe = new int[arr_size];
    for(int i = 0; i < arr_size; i++){
        dupe[i] = arr[i];
    }

    bouble_sort(dupe, arr_size);

    for(int i = 0; i < arr_size/2; i++){
        int temp = dupe[i];
        dupe[i] = dupe[arr_size - i - 1];
        dupe[arr_size - i - 1] = temp;
    }

    std::cout << "\nПерші " << G << " елементів масиву: ";
    for(int i = 0; i < G; i++){
        std::cout << dupe[i] << " ";
    }

    delete[] dupe;

    int* sorted = sort(arr, arr_size);

    return 0;

}