#include <iostream>
#include <time.h>
#include <algorithm>
#include <string.h>
#include <vector>
using namespace std;
int len, len2;
char* Stroka;
char* Stroka2;
char *to_sort;

vector<int> cuber(int** arr, int size, int cube) {
    vector<int> out;
    switch (cube) {
        case 0:
            for(int row = 0; row < size; row++){
                for (int col = 0; col < size; col++) {
                    if(col >= row){
                        cout << "#" << " ";
                    }else{
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

            cout << "\n";

            break;

        default:
            cout << "Error" << endl;
            exit(-1);

    }
    sort(out.begin(), out.end());
    return out;

}
void rand_init(short type) {
    Stroka = new char[len];
    Stroka[len - 1] = '\0';
    switch (type) {
        case 1:
            for (int i = 0; i < len-1; i++) {
                Stroka[i] = rand() % 10 + '0';
            }
            break;
        case 2:
            for (int i = 0; i < len-1; i++) {
                if (rand() % 2) {
                    char a = rand() % ('z' - 'A') + 'A';
                    if (a >= 91 && a <= 96) {
                        a += 7;
                    }
                    Stroka[i] = a;

                }
                else {


                    Stroka[i] = rand()%26;//('я' - 'Ї')+'Ї';
                }

            }
            break;
        case 3:
            for (int i = 0; i < len-1; i++) {
                if (rand() % 2) {
                    if (rand() % 2) {
                        char a = rand() % ('z' - 'A') + 'A';
                        if (a >= 91 && a <= 96) {
                            a += 7;
                        }
                        Stroka[i] = a;

                    }
                    else {


                        Stroka[i] = rand() % 26;//('я' - 'Ї') + 'Ї';
                    }
                }
                else {
                    Stroka[i] = rand() % 10 + '0';
                }
            }
            break;
    }
}
void input_string(short str_var) {
    char a;

    switch (str_var) {
        case 1:

            len = 1;
            Stroka = new char[2];
            a = Stroka[0] = cin.get();
            Stroka[1] = '\0';
            while (true) {
                a = cin.get();
                if( a == '\n') break;
                char* StrokaB = new char[len + 1];
                strcpy(StrokaB, Stroka);
                delete[]Stroka;
                Stroka = new char[++len + 1];
                strcpy(Stroka, StrokaB);
                Stroka[len - 1] = a;
                Stroka[len] = '\0';
                delete[]StrokaB;

            }
            break;
        case 2:
            cin.get();
            len2 = 1;
            Stroka2 = new char[2];
            a = Stroka2[0] = cin.get();
            Stroka2[1] = '\0';
            while (true) {
                a = cin.get();
                if (a == '\n') break;
                char* StrokaB = new char[len2 + 1];
                strcpy(StrokaB, Stroka2);
                delete[]Stroka2;
                Stroka2 = new char[++len2 + 1];
                strcpy(Stroka2, StrokaB);
                Stroka2[len2 - 1] = a;
                Stroka2[len2] = '\0';
                delete[]StrokaB;

            }
            break;
    }
}
int main() {
    setlocale(LC_ALL, "rus");
    short choice;
    srand(time(NULL));
    cout << "Рядок ввести:\n1-Випадково\n2-Вручну"<<endl;
    cin >> choice;
    switch (choice) {
        case 1:
            cout << "Введіть розмір рядка:";
            cin >> len;
            len++;
            short type;
            cout << "Введіть тип:\n1-цифри\n2-букви\n3-всі символи:"; cin >> type;
            rand_init(type);
            cout << Stroka << endl;
            break;
        case 2:
            cin.get();
            input_string(1);
            break;
    }
    input_string(2);
    bool is_all_symb = true;
    for (int i = 0; i < strlen(Stroka2); i++) {
        if (strchr(Stroka, Stroka2[i]) == NULL) is_all_symb = false;
    }

    if (is_all_symb) {
        cout << "Stroka містить всі символи рядка Stroka2\n";
    }
    else {
        cout << "Stroka не містить всі символи рядка Stroka2\n";

    }
    int c = 0;

    char* a;
    to_sort = new char[strlen(Stroka)];
    strcpy(to_sort, Stroka);
    while (a = strstr(Stroka, Stroka2)) {
        for (int i = 0; i < len2; i++)
            a[i] = '#';
        c++;
    }
    int index = strcspn(Stroka, Stroka2);
    while (index < len-1) {
        Stroka[index] = '#';
        index = strcspn(Stroka, Stroka2);
    }
    cout << Stroka << endl;
    cout << "Stroka містить в собі Stroka2 " << c << " раз\n";

    sort(to_sort, to_sort + strlen(to_sort));
    cout << to_sort << endl;

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
            arr[i][j] = rand() % (6 + 15 + 1+6+3) + (-6 - 3);
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

}