#include <iostream>

using namespace std;

class Building{
    int area;
    int floors;
    int rooms;
    int windows;
    int doors;

    public:
    Building(int area, int floors, int rooms, int windows, int doors){
        this->area = area;
        this->floors = floors;
        this->rooms = rooms;
        this->windows = windows;
        this->doors = doors;
    }

    Building(){
        this->area = 100;
        this->floors = 1;
        this->rooms = 1;
        this->windows = 1;
        this->doors = 1;
    }

    void set_area(int area){
        this->area = area;
    }

    void set_floors(int floors){
        this->floors = floors;
    }

    void set_rooms(int rooms){
        this->rooms = rooms;
    }

    void set_windows(int windows){
        this->windows = windows;
    }

    void set_doors(int doors){
        this->doors = doors;
    }

    int get_area(){
        return this->area;
    }

    int get_floors(){
        return this->floors;
    }

    int get_rooms(){
        return this->rooms;
    }

    int get_windows(){
        return this->windows;
    }

    int get_doors(){
        return this->doors;
    }

    virtual void print() = 0;
};

class Dormitory : public Building{
    int residents;
    int rooms;

    public:
    Dormitory(int residents, int rooms){
        this->residents = residents;
        this->rooms = rooms;
    }

    Dormitory(){
        this->residents = 100;
        this->rooms = 100;
    }

    void set_residents(int residents){
        this->residents = residents;
    }

    void set_rooms(int rooms){
        this->rooms = rooms;
    }

    int get_residents(){
        return this->residents;
    }

    int get_rooms(){
        return this->rooms;
    }

    void print(){
        cout << "Dormitory:\nResidents: " << residents << "\nRooms: " << rooms << endl;
    }

};

class Campus : public Building{
    int residents;
    int rooms;

    public:
    Campus(int residents, int rooms){
        this->residents = residents;
        this->rooms = rooms;
    }

    Campus(){
        this->residents = 100;
        this->rooms = 100;
    }

    void set_residents(int residents){
        this->residents = residents;
    }

    void set_rooms(int rooms){
        this->rooms = rooms;
    }

    int get_residents(){
        return this->residents;
    }

    int get_rooms(){
        return this->rooms;
    }

    void print(){
        cout << "Campus:\nResidents: " << residents << "\nRooms: " << rooms << endl;
    }
};

class Person{
    int age;
    int height;
    int weight;
    int iq;
    int money;

    public:
    Person(int age, int height, int weight, int iq, int money){
        this->age = age;
        this->height = height;
        this->weight = weight;
        this->iq = iq;
        this->money = money;
    }

    Person(){
        this->age = 18;
        this->height = 180;
        this->weight = 80;
        this->iq = 100;
        this->money = 1000;
    }

    void set_age(int age){
        this->age = age;
    }

    void set_height(int height){
        this->height = height;
    }

    void set_weight(int weight){
        this->weight = weight;
    }

    void set_iq(int iq){
        this->iq = iq;
    }

    void set_money(int money){
        this->money = money;
    }

    int get_age(){
        return this->age;
    }

    int get_height(){
        return this->height;
    }

    int get_weight(){
        return this->weight;
    }

    int get_iq(){
        return this->iq;
    }

    int get_money(){
        return this->money;
    }

    virtual void print() = 0;
};

class Teacher : public Person{
    int salary;
    int iq;

    public:
    Teacher(int salary, int iq){
        this->salary = salary;
        this->iq = iq;
    }

    Teacher(){
        this->salary = 1000;
        this->iq = 100;
    }

    void set_salary(int salary){
        this->salary = salary;
    }

    void set_iq(int iq){
        this->iq = iq;
    }

    int get_salary(){
        return this->salary;
    }

    int get_iq(){
        return this->iq;
    }

    void print(){
        cout << "Teacher" << endl;
        cout << "Salary: " << this->salary << endl;
        cout << "IQ: " << this->iq << endl;
    }
};

class Student : public Person{
    int iq;
    int money;

    public:
    Student(int iq, int money){
        this->iq = iq;
        this->money = money;
    }

    Student(){
        this->iq = 100;
        this->money = 1000;
    }

    void set_iq(int iq){
        this->iq = iq;
    }

    void set_money(int money){
        this->money = money;
    }

    int get_iq(){
        return this->iq;
    }

    int get_money(){
        return this->money;
    }

    void print(){
        cout << "Student" << endl;
        cout << "IQ: " << this->iq << endl;
        cout << "Money: " << this->money << endl;
    }
};

namespace Diamond{
    class First{
    public:
        int one;

        First(){
            this->one = 1;
        }

        // copy constructor
        First(const First& first){
            this->one = first.one;
        }

        ~First(){
            cout << "First destructor" << endl;
        }
    };

    class Second : virtual public First{ // virtual
    public:
        int two;
    };
    class Third : virtual public First{ // virtual
    public:
        int three;
    };
    class Fourth : public Second, public Third{
    public:
        int four;
    };
};

void SayHello(string name) {
    cout << "Hello, " << name << endl;
}

int main(){

    //Привести приклад раннього та пізнього зв’язування для Вашої предметної області.

    // приклад раннього зв'язування
    // виклик методу відбувається відразу після компіляції
    // приклад для SayHello - виклик методу відбувається відразу після компіляції
    SayHello("Max");

    // приклад пізнього зв'язування
    // виклик методу відбувається під час виконання програми
    // приклад для SayHello - виклик методу відбувається під час виконання програми
    string name = "Maxim";
    void (*sayH)(string) = SayHello;
    sayH(name);


    // Виділити (мінімум 2) абстрактних класи. Зробити деякі з існуючих класів наслідниками цих абстрактних класів.
    // class Person - абстрактний клас
    // class Teacher - наслідується від Person
    // class Student - наслідується від Person
    Person *person = new Teacher(1000, 100);
    person->print();
    Person *person2 = new Student(100, 1000);
    person2->print();
    // class Building - абстрактний клас
    // class Campus - наслідується від Building
    // class Dormitory - наслідується від Building
    Building *building = new Campus(100, 100);
    building->print();
    Building *building2 = new Dormitory(100, 100);
    building2->print();

    // Описати приклад множинного наслідування між вже існуючими класами або довизначити нові класи для реалізації множинного наслідування.

    // Diamond::Fourth
    // Diamond::Fourth наслідується від Diamond::Second та Diamond::Third
    Diamond::Fourth *fourth = new Diamond::Fourth();

    // Для одного з класів придумати конструктор копіювання.
    Diamond::First first;
    Diamond::First firstCopy(first);

    // Привести приклад проблеми повторного наслідування, вирішити її за
    //допомогою визначення віртуального базового класу.

    Diamond::Fourth *four = new Diamond::Fourth();
    four->one = 1;
    // це можливо тому, що використовується віртуальне наслідування
    // якщо б не було віртуального наслідування, то була б помилка
    // error: request for member ‘one’ is ambiguous
    // строка 271 та 275

}