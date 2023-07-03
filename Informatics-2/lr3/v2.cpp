#include <iostream>
#include <vector>

using namespace std;

int K = 8;// Безуглий -> 8
int G = 3;// е у и -> 3

// Відсортувати символи в рядку Stroka методом швидкого сортування
string QuickSort(string str) {
    if (str.length() <= 1) {
        return str;
    }
    int pivot = str.length() / 2;
    string left = "";
    string right = "";
    for (int i = 0; i < str.length(); i++) {
        if (i == pivot) {
            continue;
        }
        if (str[i] < str[pivot]) {
            left += str[i];
        } else {
            right += str[i];
        }
    }
    return QuickSort(left) + str[pivot] + QuickSort(right);
}

// Чи містить початковий рядок Stroka всі символи з Stroka2
bool CheckStrInStr(string str, string str2) {
    for (int i = 0; i < str2.length(); i++) {
        for (int j = 0; j < str.length(); j++) {
            if (str.find(str2[i]) == string::npos) {
                return false;
            }
        }
    }
    return true;
}
// замінити всі символи в початковому рядку Stroka рівні символам з
//Stroka2 на символ #;
string replace_same(string str, string str2) {
    for (int i = 0; i < str2.length(); i++) {
        for (int j = 0; j < str.length(); j++) {
            if (str[j] == str2[i]) {
                str[j] = '#';
            }
        }
    }
    return str;
}

// визначити скільки разів Stroka2 зустрічається в початковому рядку Stroka
int count_same(const string& str, const string& str2) {
    int count = 0;
    for (int i = 0; i < str.length() - str2.length(); i++) {
        if (str.substr(i, str2.length()) == str2) {
            count++;
        }
    }
    return count;
}

vector<int> cuber(int** arr, int size, int cube) {
    vector<int> out;
    switch (cube) {
        case 0:
            for(int row = 0; row < size; row++){
                for (int col = 0; col < size; col++) {
                    if(size-row <= col+1){
                        out.push_back(arr[row][col]);

                        cout << arr[row][col] << " ";
                    }
                }
                cout << "\n";
            }
            cout << "\n";


            break;
        case 1:

            for(int row = 0; row < size; row++){
                for (int col = 0; col < size; col++){
                    if(col-row > 0 && size-col > row+1){
                        cout << "# ";
                    }else if(row-col>0 && col >= size - row){
                        cout << "# ";
                    }else{
                        out.push_back(arr[row][col]);

                        cout << arr[row][col] << " ";

                    }
                }
                cout << "\n";
            }

            cout << "\n";
            break;


    }
    sort(out.begin(), out.end());
    return out;

}

int main(){
    srand(time(NULL));

    std::string Stroka = "";
    cout << "Size: ";
    int size;
    cin >> size;

    cout << "1. тільки з цифр" << endl;
    cout << "2. з будь-яких символів" << endl;
    int choice;
    cin >> choice;
    if (choice == 1){
        // randomly fill wih integers(0-9)
        for (int i = 0; i < size; i++) {
            Stroka += rand() % 10 + '0';
        }
    } else if (choice == 2) {

        // randomly fill wih chars
        for (int i = 0; i < size; i++) {
            Stroka += rand() % 26 + 'a';
        }

    } else {
        cout << "Error" << endl;
        return 0;
    }

    cout << "Stroka: " << Stroka << endl;

    cout << "Stroka 2: ";
    string Stroka2;
    cin >> Stroka2;

    Stroka = QuickSort(Stroka);

    cout << "Contains the same? " << (CheckStrInStr(Stroka, Stroka2) ? "ok" : "no") << endl;
    cout << "Replaced the same: " << replace_same(Stroka, Stroka2) << endl;
    cout << "Counted the same: " << count_same(Stroka, Stroka2) << endl;

    cout << "\n\n\n";

    cout << "Size of cube: ";
    int size2;
    cin >> size2;

    int **arr = new int*[size2];
    for (int i = 0; i < size2; i++) {
        arr[i] = new int[size2];
    }

    for (int i = 0; i < size2; i++) {
        for (int j = 0; j < size2; j++) {
            arr[i][j] = rand() % (K + 15 + 1+K+3) + (-K - 3);
        }
    }

    // Вивести масив на екран
    for (int i = 0; i < size2; i++) {
        for (int j = 0; j < size2; j++) {
            if(arr[i][j] >=0 && arr[i][j] < 10)
                cout << " ";
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    cout << "First " << endl;
    vector<int> out = cuber(arr, size2, 0);
    cout << "min: " << out[0] << " max: " << out[out.size() - 1] << "\n";

    cout << "Second " << endl;
    out = cuber(arr, size2, 1);
    cout << "min: " << out[0] << " max: " << out[out.size() - 1] << "\n";

    return 0;
}