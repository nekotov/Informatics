#include <iostream>
#include <vector>

using namespace std;

const int K = 11;
const int G = 4;

string sort(string str) {
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
    return sort(left) + str[pivot] + sort(right);
}

bool isStrInStr(string str, string str2) {
    for (int i = 0; i < str2.length(); i++) {
        for (int j = 0; j < str.length(); j++) {
            if (str.find(str2[i]) == string::npos) {
                return false;
            }
        }
    }
    return true;
}

string RepSame(string str, string str2) {
    for (int i = 0; i < str2.length(); i++) {
        for (int j = 0; j < str.length(); j++) {
            if (str[j] == str2[i]) {
                str[j] = '#';
            }
        }
    }
    return str;
}

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
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    if (j +1 >= size - i) {
                        cout << arr[i][j] << " ";
                        out.push_back(arr[i][j]);
                    } else {
                        cout << "  ";
                    }
                }
                cout << endl;
            }
            break;
        case 1:

            for(int row = 0; row < size; row++){
                for (int col = 0; col < size; col++){


                    if(col-row >=0 && size-row > col+1){
                        cout << "?" << " ";
                    }else if(row-col>0 ){
                        cout << "?" << " ";
                    }else{
                        out.push_back(arr[row][col]);
                        cout << arr[row][col] << " ";
                    }
                }
                cout << "\n";
            }
            break;

        default:
            cout << "Error" << endl;
            exit(-1);

    }
    sort(out.begin(), out.end());
    return out;

}

int main(){
    srand(time(NULL));


    std::string Stroka = "";

    cout << "1. тільки з літер" << endl;
    cout << "2. з будь-яких символів" << endl;
    int choice;
    cin >> choice;
    cout << "Size: ";
    int size;
    cin >> size;
    if (choice == 1){
        for (int i = 0; i < size; i++) {
            Stroka += rand() % 26 + 'a';
        }
    } else if (choice == 2) {
        for (int i = 0; i < size; i++) {
            Stroka += rand() % 255;
        }

    } else {
        cout << "Error" << endl;
        return 0;
    }

    cout << "Stroka 1: " << Stroka << endl;

    cout << "Stroka 2: ";
    string Stroka2;
    cin >> Stroka2;

    Stroka = sort(Stroka);

    cout << "Contains the same? " << (isStrInStr(Stroka, Stroka2) ? "yes" : "no") << endl;
    cout << "Replaced the same: " << RepSame(Stroka, Stroka2) << endl;
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