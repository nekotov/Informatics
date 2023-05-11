#include <iostream>
#include <vector>
using namespace std;
int K = 10; // Просоленко
int G = 4; // о о е о


//Визначити:
//• ЧиміститьпочатковийрядокStrokaвсісимволизStroka2;
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
//• замінити всі символи в початковому рядку Stroka рівні символам з
//Stroka2на символ #;
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
//• визначитискількиразівStroka2зустрічаєтьсявпочатковомурядкуStroka.
int count_same(const string& str, const string& str2) {
    int count = 0;
    for (int i = 0; i < str.length() - str2.length(); i++) {
        if (str.substr(i, str2.length()) == str2) {
            count++;
        }
    }
    return count;
}

string quick_sort(string str) {
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
    return quick_sort(left) + str[pivot] + quick_sort(right);
}


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

vector<int> cube_part(int **arr, int n, int cases) {
    vector<int> result;
    switch (cases) {
        case 0:
            for(int row = 0; row < n; row++){
                for (int col = 0; col < n; col++) {
                    if(col <= row){
                        result.push_back(arr[row][col]);

                        cout << arr[row][col] << " ";
                    }else{
                        cout << "#" << " ";
                    }
                }
                cout << "\n";
            }
            cout << "\n";


            break;
        case 1:
            for(int row = 0; row < n; row++){
                for (int col = 0; col < n; col++){


                    if(col-row >=0 && n-row > col+1){
                        cout << "?" << " ";
                    }else if(row-col>0 ){
                        cout << "?" << " ";
                    }else{
                        result.push_back(arr[row][col]);
                        cout << arr[row][col] << " ";
                    }
                }
                cout << "\n";
            }

            break;
    }
    return result;
}

int main() {
    srand(time(NULL));
    cout << "\n3.1\n";
    string Stroka2 = "";
    string Stroka1 = "";
    cout << "1. тільки з цифр;\n"
         << "2. з будь-яких символів\n"
         << "Stroka1 type: ";

    int str1_type;
    cin >> str1_type;

    cout << "Enter Stroka1 size: ";
    int str1_size;
    cin >> str1_size;
    for (int i = 0; i < str1_size; i++) {
        if(str1_type == 1) {
            Stroka1 += rand() % 10 + '0';
        }
        else if(str1_type == 2) {
            Stroka1 += rand() % 94;
        } else{
            cout << "Wrong input";
            return 0;
        }

    }

    cout << "Stroka1: " << Stroka1 << endl;


    cout << "Enter Stroka2: ";
    cin >> Stroka2;

    Stroka1 = quick_sort(Stroka1);

    cout << "Sorted Stroka2: " << Stroka2 << endl;

    if (CheckStrInStr(Stroka1, Stroka2)) {
        cout << "Stroka2 is in Stroka1" << endl;
    } else {
        cout << "Stroka2 is not in Stroka1" << endl;
    }

    cout << "Stroka1 with replaced symbols: " << endl;
    cout << replace_same(Stroka1, Stroka2) << endl;

    cout << "Count of Stroka2 in Stroka1: " << endl;
    cout << count_same(Stroka1, Stroka2) << endl;

    cout << "\n3.2\n";

    cout << "Enter n: ";
    int n;
    cin >> n;

    int **arr = new int *[n];
    for (int i = 0; i < n; i++) {
        arr[i] = new int[n];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            arr[i][j] = rand() % (K + 15 + 1 + K + 3) + (-K - 3);
        }
    }

    for(int row = 0; row < n; row++){
        for (int col = 0; col < n; col++) {
            cout << arr[row][col] << " ";
        }
        cout << "\n";
    }

    cout << endl;
    vector<int> res1 = cube_part(arr, n, 0);
    cout << endl;
    vector<int> res2 = cube_part(arr, n, 1);
    cout << endl;

    cout << "Min1: " << min(res1.data(), res1.size()) << endl;
    cout << "Max1: " << max(res1.data(), res1.size()) << endl;

    cout << "Min2: " << min(res2.data(), res2.size()) << endl;
    cout << "Max2: " << max(res2.data(), res2.size()) << endl;



}
