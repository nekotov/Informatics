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
};

int main(){
    /*// Создание объекта класса Building
    Building building1(100, 1, 1, 1, 1);
    // Создание объекта класса Dormitory
    Dormitory dormitory1(100, 100);
    // Создание объекта класса Campus
    Campus campus1(100, 100);
    // Создание объекта класса Person
    Person person1(18, 180, 80, 100, 1000);
    // Создание объекта класса Teacher
    Teacher teacher1(1000, 100);
    // Создание объекта класса Student
    Student student1(100, 1000);

    // Создание объекта по умолчанию класса Building
    Building building2;
    // Создание объекта по умолчанию класса Dormitory
    Dormitory dormitory2;
    // Создание объекта по умолчанию класса Campus
    Campus campus2;
    // Создание объекта по умолчанию класса Person
    Person person2;
    // Создание объекта по умолчанию класса Teacher
    Teacher teacher2;
    // Создание объекта по умолчанию класса Student
    Student student2;

    // Вывод значений полей объекта класса Building
    cout << "Building1: " << endl;
    cout << "Area: " << building1.get_area() << endl;
    cout << "Floors: " << building1.get_floors() << endl;
    cout << "Rooms: " << building1.get_rooms() << endl;
    cout << "Windows: " << building1.get_windows() << endl;
    cout << "Doors: " << building1.get_doors() << endl;
    cout << endl;
    // Редактирование значений полей объекта класса Building
    building1.set_area(200);
    building1.set_floors(2);
    building1.set_rooms(2);
    building1.set_windows(2);
    building1.set_doors(2);
    // Вывод значений полей объекта класса Building
    cout << "Building1 edited: " << endl;
    cout << "Area: " << building1.get_area() << endl;
    cout << "Floors: " << building1.get_floors() << endl;
    cout << "Rooms: " << building1.get_rooms() << endl;
    cout << "Windows: " << building1.get_windows() << endl;
    cout << "Doors: " << building1.get_doors() << endl;
    cout << endl;

    // Вывод значений полей объекта класса Dormitory
    cout << "Dormitory1: " << endl;
    cout << "Residents: " << dormitory1.get_residents() << endl;
    cout << "Rooms: " << dormitory1.get_rooms() << endl;
    cout << endl;
    // Редактирование значений полей объекта класса Dormitory
    dormitory1.set_residents(200);
    dormitory1.set_rooms(200);
    // Вывод значений полей объекта класса Dormitory
    cout << "Dormitory1 edited: " << endl;
    cout << "Residents: " << dormitory1.get_residents() << endl;
    cout << "Rooms: " << dormitory1.get_rooms() << endl;
    cout << endl;

    // Вывод значений полей объекта класса Campus
    cout << "Campus1: " << endl;
    cout << "Residents: " << campus1.get_residents() << endl;
    cout << "Rooms: " << campus1.get_rooms() << endl;
    cout << endl;

    // Вывод значений полей объекта класса Person
    cout << "Person1: " << endl;
    cout << "Age: " << person1.get_age() << endl;
    cout << "Height: " << person1.get_height() << endl;
    cout << "Weight: " << person1.get_weight() << endl;
    cout << "IQ: " << person1.get_iq() << endl;
    cout << "Money: " << person1.get_money() << endl;
    cout << endl;

    // Вывод значений полей объекта класса Teacher
    cout << "Teacher1: " << endl;
    cout << "Salary: " << teacher1.get_salary() << endl;
    cout << "IQ: " << teacher1.get_iq() << endl;
    cout << endl;

    // Вывод значений полей объекта класса Student
    cout << "Student1: " << endl;
    cout << "IQ: " << student1.get_iq() << endl;
    cout << "Money: " << student1.get_money() << endl;
    cout << endl;

    // Вывод значений полей объекта класса Building
    cout << "Building2: " << endl;
    cout << "Area: " << building2.get_area() << endl;
    cout << "Floors: " << building2.get_floors() << endl;
    cout << "Rooms: " << building2.get_rooms() << endl;
    cout << "Windows: " << building2.get_windows() << endl;
    cout << "Doors: " << building2.get_doors() << endl;
    cout << endl;

    // Вывод значений полей объекта класса Dormitory
    cout << "Dormitory2: " << endl;
    cout << "Residents: " << dormitory2.get_residents() << endl;
    cout << "Rooms: " << dormitory2.get_rooms() << endl;
    cout << endl;

    // Вывод значений полей объекта класса Campus
    cout << "Campus2: " << endl;
    cout << "Residents: " << campus2.get_residents() << endl;
    cout << "Rooms: " << campus2.get_rooms() << endl;
    cout << endl;

    // Вывод значений полей объекта класса Person
    cout << "Person2: " << endl;
    cout << "Age: " << person2.get_age() << endl;
    cout << "Height: " << person2.get_height() << endl;
    cout << "Weight: " << person2.get_weight() << endl;
    cout << "IQ: " << person2.get_iq() << endl;
    cout << "Money: " << person2.get_money() << endl;
    cout << endl;

    // Вывод значений полей объекта класса Teacher
    cout << "Teacher2: " << endl;
    cout << "Salary: " << teacher2.get_salary() << endl;
    cout << "IQ: " << teacher2.get_iq() << endl;
    cout << endl;

    // Вывод значений полей объекта класса Student
    cout << "Student2: " << endl;
    cout << "IQ: " << student2.get_iq() << endl;
    cout << "Money: " << student2.get_money() << endl;
    cout << endl;

*/

}