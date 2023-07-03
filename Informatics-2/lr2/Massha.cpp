#include <iostream>

int* RoslyakBessmertna(int arr[]){
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5 - i; j++){
            if(arr[j] < arr[j + 1]){
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    return arr;
}

int main(){
    int arr[5] = {1, 2, 3, 4, 5};

    int *p = RoslyakBessmertna(arr);
    for(int i = 0; i < 5; i++){
        std::cout << p[i] << " ";
    }

    return 0;
}