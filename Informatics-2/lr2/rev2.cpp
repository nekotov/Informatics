#include <iostream>
#include <cmath>

// Дембицький
using std::cin;
using std::cout;

bool b_k, b_g;
int *duplicate_arr;

int min(const int *arr, int size) {
    int min = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

int max(const int *arr, int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}


int most_likely(int *arr, int size) {
    int *count = new int[size];
    for (int i = 0; i < size; i++) {
        count[i] = 0;
    }
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (arr[i] == arr[j]) {
                count[i]++;
            }
        }
    }
    int max = count[0];
    int index = 0;
    for (int i = 1; i < size; i++) {
        if (count[i] > max) {
            max = count[i];
            index = i;
        }
    }
    return arr[index];
}


void histogram(int *arr, int size, char symbol = '*') {
    for (int i = 0; i < size; i++) {
        cout << "a[" << i << "]=" << arr[i] << " ";
        for (int j = 0; j < arr[i]; j++) {
            cout << symbol;
        }
        cout << '\n';
    }
}


int linear_search(const int *arr, int size, int value) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            return i;
        }
    }
    return -1;
}

int binary_search(const int *arr, int size, int value) {
    int start = 0;
    int end = size - 1;
    while (start <= end) {
        int mid = (start + end) / 2;
        if (arr[mid] == value) {
            return mid;
        } else if (arr[mid] < value) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return -1;
}

int binarySearch(int arr[], int l, int r, int x) {
    if (r >= l) {
        int mid = l + (r - l) / 2;

        if (arr[mid] == x)
            return mid;

        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);

        return binarySearch(arr, mid + 1, r, x);
    }

    return -1;
}

int insertion_sort(int *arr, int size, int start_index = 0, int end_index = -1) {
    if (end_index == -1) {
        end_index = size - 1;
    }
    int count = 0;
    for (int i = start_index + 1; i <= end_index; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= start_index && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
            count++;
        }
        arr[j + 1] = key;
    }
    return count;
}

int selection_sort(int *arr, int size, int start_index = 0, int end_index = -1) {
    if (end_index == -1) {
        end_index = size - 1;
    }
    int count = 0;
    for (int i = start_index; i <= end_index; i++) {
        int min_index = i;
        for (int j = i + 1; j <= end_index; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
            count++;
        }
        int temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }
    return count;
}

int bubble_sort(int *arr, int size, int start_index = 0, int end_index = -1) {
    if (end_index == -1) {
        end_index = size - 1;
    }
    int count = 0;
    for (int i = start_index; i <= end_index; i++) {
        for (int j = start_index; j <= end_index - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
            count++;
        }
    }
    return count;
}

void print_array(int *arr, int size) {
    cout << "Масив: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << '\n';
}

int *sort(int *arr, int size, int sort_type, int sort_part, int st = 0, int end = 0) {
    int start_index;
    int end_index;
    int *sorted_arr;
//    if(sort_part == 2){
//        int* indexes = new int[2];
//        indexes[0] = linear_search(arr, size, min(arr, size));
//        indexes[1] = linear_search(arr, size, max(arr, size));
//        insertion_sort(indexes, 2);
//        start_index = indexes[0];
//        end_index = indexes[1];
//        size = end_index - start_index - 1;
//        sorted_arr = new int[size];
//        for(int i = 0; i < size; i++){
//            sorted_arr[i] = arr[start_index + i + 1];
//        }
//        //print_array(sorted_arr, size);
//
//    }else{
//        sorted_arr = new int[size];
//        for(int i = 0; i < size; i++){
//            sorted_arr[i] = arr[i];
//        }
//        start_index = 0;
//        end_index = size - 1;
//    }

    switch (sort_part) {
        case 1: {
            sorted_arr = new int[size];
            for (int i = 0; i < size; i++) {
                sorted_arr[i] = arr[i];
            }
            start_index = 0;
            end_index = size - 1;
            //print_array(sorted_arr, size);
            break;
        }
        case 2: {
            int *indexes = new int[2];
            indexes[0] = linear_search(duplicate_arr, size, min(duplicate_arr, size));
            indexes[1] = linear_search(duplicate_arr, size, max(duplicate_arr, size));
            insertion_sort(indexes, 2);
            start_index = indexes[0];
            end_index = indexes[1];
            size = end_index - start_index - 1;
            sorted_arr = new int[size];
            for (int i = 0; i < size; i++) {
                sorted_arr[i] = duplicate_arr[start_index + i + 1];
            }
            if (b_k) {
                if (b_g)
                    bubble_sort(sorted_arr, size);
                else {
                    selection_sort(sorted_arr, size);
                }
            } else {
                if (b_g)
                    insertion_sort(sorted_arr, size);
                else {
                    bubble_sort(sorted_arr, size);
                }
            }
            //print_array(sorted_arr, size);
            break;
        }
        case 3: {
            size = end - st + 1;
            sorted_arr = new int[size];
            for (int i = 0; i < size; i++) {
                sorted_arr[i] = arr[st + i];
            }
            //print_array(sorted_arr, size);
            break;
        }
    }


    if (sort_type == 2) {
        for (int i = 0; i < size / 2; i++) {
            int temp = sorted_arr[i];
            sorted_arr[i] = sorted_arr[size - i - 1];
            sorted_arr[size - i - 1] = temp;
        }
    }


    print_array(sorted_arr, size);
    return sorted_arr;
}

int *sort_wrapper(int *arr, int size) {
    cout << "Як сортувати масив: " << '\n';
    cout << "1. За зростанням" << '\n';
    cout << "2. За спаданням" << '\n';
    int sort_type;
    cin >> sort_type;
    cout << "Яку частину масиву сортувати: " << '\n';
    cout << "1. сортувати увесь масив;" << '\n';
    cout
            << "2. сортувати ту частину масиву, елементи якої знаходяться між мінімальним та максимальним значенням масиву до сортування."
            << '\n';
    // Сортувати масив в частині між порядковими номерами, що задаються
    //користувачем
    cout << "3. сортувати ту частину масиву, що задається користувачем." << '\n';
    int sort_part;
    cin >> sort_part;
    if (sort_part == 3) {
        cout << "Введіть початковий індекс: ";
        int start_index;
        cin >> start_index;
        cout << "Введіть кінцевий індекс: ";
        int end_index;
        cin >> end_index;
        return sort(arr, size, sort_type, sort_part, start_index, end_index);
    }
//    cout << "Яким алгоритмом сортувати: " << '\n';
//    cout << "1. сортування вставкою;" << '\n';
//    cout << "2. сортування вибором;" << '\n';
//    cout << "3. сортування бульбашкою." << '\n';
//    int sort_method;
//    cin >> sort_method;
    return sort(arr, size, sort_type, sort_part);

}


int main() {
    srand(time(NULL));
    cout << "Введіть кількість букв в прізвищі: ";
    int k;
    cin >> k;
    cout << "Введіть кількість голосних букв: ";
    int g;
    cin >> g;
    cout << "Введіть кількість елементів масиву: ";
    int size;
    cin >> size;
    int *arr = new int[size];
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % (4 * k);
    }
    print_array(arr, size);

    //Якщо К- парне виведення найменшого елементу масиву (елемент з найменшим
    //  значенням);
    //Якщо К- непарне виведення найбільшого елементу масиву (елемент з найбільшим
    //значенням);

    if (k % 2 == 0) {
        b_k = true;
        cout << "Найменший елемент масиву: " << min(arr, size) << '\n';
    } else {
        b_k = false;
        cout << "Найбільший елемент масиву: " << max(arr, size) << '\n';
    }

    // Вивід всіх значень елементів масиву і відображення гістограми за їхніми
    //значеннями за допомогою символу: якщо Г – парне символ «+», якщо Г – непарне символ «|»
    //Навпроти кожного виведеного на екран значення відображається кількість символів рівна значенню елемента, наприклад:
    //a[0]=1 *
    //a[1]=5 *****
    //a[2]=3 ***

    if (g % 2 == 0) {
        b_g = true;
        histogram(arr, size, '+');
    } else {
        b_g = false;
        histogram(arr, size, '|');
    }

    // Пошук заданого користувачем значення елементу масиву по алгоритму якщо Г- парне - лінійний пошук
    //якщо Г- непарне - двійковий пошук;

    if (g % 2 == 0) {
        cout << "Введіть число, яке потрібно знайти: ";
        int number;
        cin >> number;
        cout << "Знайдено на позиції: " << linear_search(arr, size, number) << '\n';
    } else {
        cout << "Введіть число, яке потрібно знайти: ";
        int number;
        cin >> number;
        // create copy of array then sort copy selection_sort
        int *sorted_arr = new int[size];
        for (int i = 0; i < size; i++) {
            sorted_arr[i] = arr[i];
        }
        selection_sort(sorted_arr, size);
        print_array(sorted_arr, size);
        cout << "Знайдено на позиції: " << binarySearch(sorted_arr, 0, size, number) << '\n';
    }

    // Вивід індексів елементів масиву :
    //Кількість елементів масиву(для яких буде виведено ) – Г Якщо К – парне дані елементи мають найбільші значення Якщо К – непарне дані елементи мають найменше значення

    if (g % 2 == 0) {
        int *inverse_arr = new int[size];
        cout << "Найбільші значення: " << '\n';
        for (int i = 0; i < g; i++) {
            // create sorted array
            int *sorted_arr = new int[size];
            for (int i = 0; i < size; i++) {
                sorted_arr[i] = arr[i];
            }
            selection_sort(sorted_arr, size);
            // inverse array

            for (int i = 0; i < size; i++) {
                inverse_arr[i] = sorted_arr[size - i - 1];
            }

        }
        print_array(inverse_arr, g);
    } else {
        int *sorted_arr = new int[size];
        cout << "Найменші значення: " << '\n';
        for (int i = 0; i < g; i++) {
            // create sorted array

            for (int i = 0; i < size; i++) {
                sorted_arr[i] = arr[i];
            }
            selection_sort(sorted_arr, size);


        }
        print_array(sorted_arr, g);
    }

    // duplicate array
    duplicate_arr = new int[size];
    for (int i = 0; i < size; i++) {
        duplicate_arr[i] = arr[i];
    }

    if (b_k) {
        if (b_g) {
            cout << "Бульбашкове сортування" << '\n';
            bubble_sort(arr, size);
            print_array(arr, size);
        } else {
            cout << "Сортування вибором" << '\n';
            selection_sort(arr, size);
            print_array(arr, size);
        }
    } else {
        if (b_g) {
            cout << "Сортування вставками" << '\n';
            insertion_sort(arr, size);
            print_array(arr, size);
        } else {
            cout << "Бульбашкове вибором" << '\n';
            bubble_sort(arr, size);
            print_array(arr, size);
        }
    }

    sort_wrapper(arr, size);


}