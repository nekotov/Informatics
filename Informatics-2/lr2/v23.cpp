#include <iostream>

int K = 5;
int G = 2;

int min(int *arr, int size) {
    int min = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

int max(int *arr, int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

void histogram(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << "a[" << i << "]=" << arr[i] << " ";
        for (int j = 0; j < arr[i]; j++) {
            std::cout << "*";
        }
        std::cout << '\n';
    }
}

int linear_search(int *arr, int size, int value) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            return i;
        }
    }
    return -1;
}

void selection_sort(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        int min = arr[i];
        int min_index = i;
        for (int j = i; j < size; j++) {
            if (arr[j] < min) {
                min = arr[j];
                min_index = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }
}


int *sort(int *arr, int size) {

    std::cout << "\nкак сортировать?:\n";
    std::cout << "1. спадание\n";
    std::cout << "2. возростание\n";
    int sort_type;
    std::cin >> sort_type;

    std::cout << "какую часть:\n";
    std::cout << "1. Весь\n";
    std::cout << "2. между минимумом и максимумом\n";
    std::cout << "3. указать\n";

    int sort_part;
    std::cin >> sort_part;

    int *new_arr = new int[size];
    for (int i = 0; i < size; i++) {
        new_arr[i] = arr[i];
    }

    if (sort_part == 2) {
        int minimal = min(arr, size);
        int maximum = max(arr, size);
        int start = linear_search(new_arr, size, minimal);
        int end = linear_search(new_arr, size, maximum);
        if (start > end) {
            int temp = start;
            start = end;
            end = temp;
        }
        size = end - start + 1;
        for (int i = 0; i < size; i++) {
            new_arr[i] = arr[start + i];
        }
    } else if (sort_part == 3) {
        int start;
        std::cout << "стартовый индекс: ";
        std::cin >> start;
        int end;
        std::cout << "конечный индекс: ";
        std::cin >> end;
        size = end - start + 1;
        for (int i = 0; i < size; i++) {
            new_arr[i] = arr[start + i];
        }
    }

    selection_sort(new_arr, size);

    if (sort_type == 1) {
        int *reversed_arr = new int[size];
        for (int i = 0; i < size; i++) {
            reversed_arr[i] = new_arr[size - i - 1];
        }
        for (int i = 0; i < size; i++) {
            new_arr[i] = reversed_arr[i];
        }
    }

    std::cout << "\nСор. массив: ";
    for (int i = 0; i < size; i++) {
        std::cout << new_arr[i] << " ";
    }
    return new_arr;

}


int main() {
    srand(time(NULL));
    int arr_size;
    std::cout << "кол-во элементов массива: ";
    std::cin >> arr_size;
    int *arr = new int[arr_size];
    for (int i = 0; i < arr_size; i++) {
        arr[i] = rand() % (4 * K);
    }

    std::cout << "Массив: ";
    for (int i = 0; i < arr_size; i++) {
        std::cout << arr[i] << " ";
    }

    std::cout << "\nmax число: " << max(arr, arr_size);

    std::cout << "\nГистограмма: \n";
    histogram(arr, arr_size);

    int search_value;
    std::cout << "\nЗначение для поиска: ";
    std::cin >> search_value;
    int index = linear_search(arr, arr_size, search_value);
    if (index == -1) {
        std::cout << "не найдено";
    } else {
        std::cout << "на позиции " << index;
    }

    int *dupe = new int[arr_size];
    for (int i = 0; i < arr_size; i++) {
        dupe[i] = arr[i];
    }

    selection_sort(dupe, arr_size);


    std::cout << "\nПервые " << G << " элементов: ";
    for (int i = 0; i < G; i++) {
        std::cout << dupe[i] << " ";
    }

    delete[] dupe;

    int *sorted = sort(arr, arr_size);

    return 0;

}