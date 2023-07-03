#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <string>
using namespace std;

class Person {
protected:
    int age;
    string name;
    char sex;
public:
    Person() {
        age = 17;
        name = "Daniel";
        sex = 'm';
    }
    Person(int age, string name, char sex) {
        this->age = age;
        this->name = name;
        this->sex = sex;
    }

    //create copy constructor
    Person(const Person& person){
        this->age = person.age;
        this->name = person.name;
        this->sex = person.sex;
    }


    void setAge(int age) {
        this->age = age;
    }
    void setName(string name) {
        this->name = name;
    }
    void setSex(char sex) {
        this->sex = sex;
    }
    int getAge() {
        return age;
    }
    string getName() {
        return name;
    }
    char getSex() {
        return sex;
    }
    friend ostream& operator <<(ostream& out, const Person& obj);
    friend istream& operator >>(istream& input, Person& obj);

    virtual void print() {
        cout << "Person: " << this->name << this->age << endl;
    }
};

istream& operator>>(istream& input, Person& obj){
    cout << "Name: ";
    input >> obj.name;
    cout << "Age: ";
    input >> obj.age;
    cout << "Sex: ";
    input >> obj.sex;
    return input;
}

ostream& operator<<(ostream& out, const Person& obj){
    out << "Name: " << obj.name << "\nAge: " << obj.age << "\n sex: " << obj.sex << endl;
    return out;
}

class Policeman: public Person {
protected:
    int workExperience;
public:
    Policeman() :Person() {
        workExperience = 10;
    }
    Policeman(int age, string name, char sex, int workExperience)
        :Person(age, name, sex) {
        this->workExperience = workExperience;
    }
    void setWorkExperience(int workExperience) {
        this->workExperience = workExperience;
    }
    int getWorkExperience() {
        return workExperience;
    }
    friend ostream& operator <<(ostream& out, const Policeman& obj);
    friend istream& operator >>(istream& input, Policeman& obj);

    void print() {
        cout << "Policeman: " << this->name << this->age << this->workExperience << endl;
    }
};

ostream& operator<<(ostream& out, const Policeman& obj) { 
    out << "Name: " << obj.name << "\nAge: " << obj.age << "\nSex: " << obj.sex << "\nWork experience: " << obj.workExperience << endl;
    return out;
}

istream& operator>>(istream& input, Policeman& obj) {
    cout << "Name: ";
    input >> obj.name;
    cout << "Age: ";
    input >> obj.age;
    cout << "Sex: ";
    input >> obj.sex;
    cout << "Work experience: ";
    input >> obj.workExperience;
    return input;
}

class Shtraf{
protected:
    string type;
    int amount;
    int price;
public:
    Shtraf() {
        type = "Shtraf";
        amount = 1;
        price = 500;
    }
    Shtraf(string type, int amount, int price) {
        this->type = type;
        this->amount = amount;
        this->price = price;
    }

    void setType() {
        this->type = type;
    }
    void setAmount() {
        this->amount = amount;
    }
    void setPrice() {
        this->price = price;
    }
    string getType() {
        return type;
    }
    int getAmount() {
        return amount;
    }
    int getPrice() {
        return price;
    }
    friend ostream& operator <<(ostream& out, const Shtraf& obj);
    friend istream& operator >>(istream& input, Shtraf& obj);
};

ostream& operator<<(ostream& out, const Shtraf& obj){ 
    out << "Type: " << obj.type << "\nAmount: " << obj.amount << "\nPrice: " << obj.price << endl;
    return out;
}

istream& operator>>(istream& input, Shtraf& obj) { 
    cout << "Type: ";
    cin.ignore(256, '\n');
    getline(cin, obj.type);
    cout << "Amount: ";
    input >> obj.amount;
    cout << "Price: ";
    input >> obj.price;
    return input;
}

struct Node {
    Shtraf data;
    Node* next;
};

class ShtrafInfo{
protected:
    Person person;
    Policeman policeman;
    Node* head; 
public:
    ShtrafInfo() {
        head = NULL; 
    }
    ShtrafInfo(Person person, Policeman policeman) {
        this->person = person;
        this->policeman = policeman;
    }
    void addShtraf(Shtraf d) {
        Node* nd = new Node; 
        nd->data = d;        
        nd->next = NULL;     
        if (head == NULL)     
            head = nd;
        else { 
            Node* current = head;
            while (current->next != NULL)
                current = current->next;
            current->next = nd;
        }
    }
    void print() {
        cout << "You:\n";
        cout << person << endl;
        cout << "Policeman:" << endl;
        cout << policeman << endl;
        Node* current = head;
        while (current != NULL) {
            cout << current->data << endl;
            current = current->next;
        }
    }
};

int lr4(){
    srand(time(NULL));
    string names[10] = {
            "Max",
            "Alexandr",
            "Mariia",
            "Katya",
            "Anna",
            "Olivia",
            "Oliver",
            "Elijah",
            "Liam",
            "Emma",
    };
    char sex[2] = { 'f', 'm' };

    cout << "Congratulations. You are logged in system\nEnter:\n";
    Person you;
    Shtraf shtrafPlan;

    cin >> you;
    cout << "Today policeman on duty is:\n";
    Policeman police(rand() % 40 + 20, names[rand() % 10 + 1], sex[rand() % 2], rand() % 20 + 1);
    ShtrafInfo shtrafInfo(you, police);
    cout << police;
    while (true) {
        cout << "Do you want to pay the shtraf? (1 - yes, 2 - no)\n";
        int choice;
        cin >> choice;
        if (choice == 1) {
            cout << "Enter which shtraf you want to pay: \n";
            cin >> shtrafPlan;
            shtrafInfo.addShtraf(shtrafPlan);
        } else {
            cout << "Do you want to see the information of your shtrafs?\n1 - yes\n2 - no\n";
            cin >> choice;
            if (choice == 1) {
                shtrafInfo.print();
            }
            else
                return 0;
        }
    }
}


class A{public: int one;};
class B : virtual public A{public: int two;}; // virtual
class C : virtual public A{public: int three;}; // virtual
class D : public B,public C{public: int four;};

int calc(int a, int b){
    return a + b;
}

void lr5(){
    //Привести приклад раннього та пізнього зв’язування для Вашої предметної області.
    //Раннє зв'язування
    calc(2,2);


    //Пізнє зв'язування
    Person *worker2;
    Policeman police;

    worker2 = &police;
    worker2->print();

    // Виділити (мінімум 2) абстрактних класи. Зробити деякі з існуючих класів наслідниками цих абстрактних класів.

    // Клас - A (абстрактний)
    // Наслідники - B, C, D

    // Клас - Person (абстрактний)
    // Наслідники - Policeman



    // Описати приклад множинного наслідування між вже існуючими класами або довизначити нові класи для реалізації множинного наслідування.

    // Клас - A
    // Наслідники - B, C

    /*
        A -> поле имя
       / \
      B   C -> опле имя
       \ /
        D
    */


    //  Для одного з класів придумати конструктор копіювання.
    Person person1;
    Person person2(person1);

    // Привести приклад проблеми повторного наслідування, вирішити її за допомогою визначення віртуального базового класу.

    cout << "diamond problem" << endl;
    D c;
    c.one = 1;

}
int main() {
    lr5();
    return 0;
}
