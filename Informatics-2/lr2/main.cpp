#include <iostream>
#include <math.h>

using std::cin;
using std::cout;

double min(double* arr, int size){
    double min = arr[0];
    for(int i = 1; i < size; i++){
        if(arr[i] < min){
            min = arr[i];
        }
    }
    return min;
}

double max(double* arr, int size){
    double max = arr[0];
    for(int i = 1; i < size; i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }
    return max;
}


double most_likely(double* arr, int size){
    int* count = new int[size];
    for(int i = 0; i < size; i++){
        count[i] = 0;
    }
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            if(arr[i] == arr[j]){
                count[i]++;
            }
        }
    }
    int max = count[0];
    int index = 0;
    for(int i = 1; i < size; i++){
        if(count[i] > max){
            max = count[i];
            index = i;
        }
    }
    return arr[index];
}


void histogram(double* arr, int size){
    for(int i = 0; i < size; i++){
        cout << "a[" << i << "]=" << arr[i] << " ";
        for(int j = 0; j < arr[i]; j++){
            cout << "*";
        }
        cout << '\n';
    }
}


double linear_search(double* arr, int size, double value){
    for(int i = 0; i < size; i++){
        if(arr[i] == value){
            return i;
        }
    }
    return -1;
}

//double binary_search(double* arr, int size, double value){
//    int left = 0;
//    int right = size - 1;
//    while(left <= right){
//        int mid = (left + right) / 2;
//        if(arr[mid] == value){
//            return mid;
//        }
//        if(arr[mid] < value){
//            left = mid + 1;
//        }else{
//            right = mid - 1;
//        }
//    }
//    return -1;
//}

double insertion_sort(double* arr, int size, int start_index = 0, int end_index = -1){
    if(end_index == -1){
        end_index = size - 1;
    }
    double count = 0;
    for(int i = start_index + 1; i <= end_index; i++){
        double key = arr[i];
        int j = i - 1;
        while(j >= start_index && arr[j] > key){
            arr[j + 1] = arr[j];
            j--;
            count++;
        }
        arr[j + 1] = key;
    }
    return count;
}

double selection_sort(double* arr, int size, int start_index = 0, int end_index = -1){
    if(end_index == -1){
        end_index = size - 1;
    }
    double count = 0;
    for(int i = start_index; i <= end_index; i++){
        int min_index = i;
        for(int j = i + 1; j <= end_index; j++){
            if(arr[j] < arr[min_index]){
                min_index = j;
            }
            count++;
        }
        double temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }
    return count;
}

double bubble_sort(double* arr, int size, int start_index = 0, int end_index = -1){
    if(end_index == -1){
        end_index = size - 1;
    }
    double count = 0;
    for(int i = start_index; i <= end_index; i++){
        for(int j = start_index; j <= end_index - i - 1; j++){
            if(arr[j] > arr[j + 1]){
                double temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
            count++;
        }
    }
    return count;
}

void print_array(double* arr, int size){
    cout << "Масив: ";
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << '\n';
}

double* sort(double* arr, int size, int sort_type, int sort_part, int sort_method){
    int start_index;
    int end_index;
    double* sorted_arr;
    if(sort_part == 2){
        // create double array with size 2, fist element is start index, second is end index
        double* indexes = new double[2];
        indexes[0] = linear_search(arr, size, min(arr, size));
        indexes[1] = linear_search(arr, size, max(arr, size));
        //sort indexes
        insertion_sort(indexes, 2);
        start_index = indexes[0];
        end_index = indexes[1];
        size = end_index - start_index - 1;
        sorted_arr = new double[size];
        // fill sorted array with values from arr in range from start_index to end_index excluding them
        for(int i = 0; i < size; i++){
            sorted_arr[i] = arr[start_index + i + 1];
        }
        //print_array(sorted_arr, size);

    }else{
        sorted_arr = new double[size];
        for(int i = 0; i < size; i++){
            sorted_arr[i] = arr[i];
        }
        start_index = 0;
        end_index = size - 1;
    }
    switch(sort_method){
        case 1:
            insertion_sort(sorted_arr, size);
            break;
        case 2:
            selection_sort(sorted_arr, size);
            break;
        case 3:
            bubble_sort(sorted_arr, size);
            break;
    }
    if(sort_type == 2){
        for(int i = 0; i < size / 2; i++){
            double temp = sorted_arr[i];
            sorted_arr[i] = sorted_arr[size - i - 1];
            sorted_arr[size - i - 1] = temp;
        }
    }


    print_array(sorted_arr, size);
    return sorted_arr;
}

double* sort_wrapper(double* arr, int size){
    cout << "Як сортувати масив: " << '\n';
    cout << "1. За зростанням" << '\n';
    cout << "2. За спаданням" << '\n';
    int sort_type;
    cin >> sort_type;
    cout << "Яку частину масиву сортувати: " << '\n';
    cout << "1. сортувати увесь масив;" << '\n';
    cout << "2. сортувати ту частину масиву, елементи якої знаходяться між мінімальним та максимальним значенням масиву до сортування." << '\n';
    int sort_part;
    cin >> sort_part;
    cout << "Яким алгоритмом сортувати: " << '\n';
    cout << "1. сортування вставкою;" << '\n';
    cout << "2. сортування вибором;" << '\n';
    cout << "3. сортування бульбашкою." << '\n';
    int sort_method;
    cin >> sort_method;
    return sort(arr, size, sort_type, sort_part, sort_method);

}





int main(){
    srand(time(NULL));

    cout << "Кількість елементів масиву для подальшої роботи: ";
    int arr_size;
    cin >> arr_size;
    double* arr = new double[arr_size];
    // randomize array in range 0,50
    for(int i = 0; i < arr_size; i++){
        arr[i] = rand() % 50;
    }


    //
    // print_array(arr, arr_size);
    cout << min(arr, arr_size) << "\n";
    cout << max(arr, arr_size) << "\n";
    cout << most_likely(arr, arr_size) << "\n";
    histogram(arr, arr_size);

    cout << "Введіть значення для пошуку: ";
    double value;
    cin >> value;
    cout << linear_search(arr, arr_size, value) << "\n";
    //cout << binary_search(arr, arr_size, value) << "\n";

    double* sorted_arr = sort_wrapper(arr, arr_size);
    return 0;


}