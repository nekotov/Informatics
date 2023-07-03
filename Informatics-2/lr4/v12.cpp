#include <iostream>

using namespace std;

class Worker{
    string name;
    string state;
    int age;
    int salary;

    public:
    Worker(string name, string state, int age, int salary){
        this->name = name;
        this->state = state;
        this->age = age;
        this->salary = salary;
    }

    Worker(){
        this->name = "Rabotaga";
        this->state = "unemployed";
        this->age = 24;
        this->salary = 2000;
    }

    void work(){
        cout << "I`m " << this->name << " and I`m " << this->state << endl;
        cout << "I'm working" << endl;
    }

    void set_name(string name){
        this->name = name;
    }

    void set_state(string state){
        this->state = state;
    }

    void set_age(int age){
        this->age = age;
    }

    void set_salary(int salary){
        this->salary = salary;
    }

    string get_name(){
        return this->name;
    }

    int get_age(){
        return this->age;
    }

    string get_state(){
        return this->state;
    }

    int get_salary(){
        return this->salary;
    }
};

class Cashier : public Worker{
    int cash;


    public:
    Cashier(int cash, int salary){
        this->set_state("cashier");
        this->cash = cash;
        this->set_salary(salary);
    }

    Cashier(){
        Cashier(0, 2000);
    }

    void set_cash(int cash){
        this->cash = cash;
    }

    void add_cash(int cash){
        this->set_cash(this->get_cash() + cash);
    }

    int get_cash(){
        return this->cash;
    }

};

class Owner : public Worker{
    int money;

    public:
    Owner(int money, int salary){
        this->set_state("owner");
        this->money = money;
        this->set_salary(salary);
    }

    Owner(){
        Owner(0, 10000);
    }

    void set_money(int money){
        this->money = money;
    }

    void add_money(int money){
        this->set_money(this->get_money() + money);
    }

    int get_money(){
        return this->money;
    }
};

class Cook : public Worker{
    int dishes;

    public:
    Cook(int dishes, int salary){
        this->set_state("cook");
        this->dishes = dishes;
        this->set_salary(salary);
    }

    Cook(){
        Cook(0, 3000);
    }

    void set_dishes(int dishes){
        this->dishes = dishes;
    }

    void add_dishes(int dishes){
        this->set_dishes(this->get_dishes() + dishes);
    }

    int get_dishes(){
        return this->dishes;
    }
};

class Waiter : public Worker{
    int tips;

    public:
    Waiter(int tips, int salary){
        this->set_state("waiter");
        this->tips = tips;
        this->set_salary(salary);
    }

    Waiter(){
        Waiter(0, 2000);
    }

    void set_tips(int tips){
        this->tips = tips;
    }

    void add_tips(int tips){
        this->set_tips(this->get_tips() + tips);
    }

    int get_tips(){
        return this->tips;
    }
};

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


int main(){

    // за замовчанням
    Worker worker;
    Cashier cashier;
    Owner owner;
    Cook cook;
    Waiter waiter;
    Building building;

    // з параметрами
    Worker worker1("Vasya", "unemployed", 24, 2000);
    Cashier cashier1(1000, 2000);
    Owner owner1(10000, 10000);
    Cook cook1(100, 3000);
    Waiter waiter1(100, 2000);
    Building building1(1000, 2, 5, 10, 10);

    // зміна параметрів
    cashier1.set_cash(2000);
    owner1.set_money(20000);
    cook1.set_dishes(200);
    waiter1.set_tips(200);

    // вивід
    cout << "Worker: " << endl;
    cout << "Name: " << worker1.get_name() << endl;
    cout << "Age: " << worker1.get_age() << endl;
    cout << "State: " << worker1.get_state() << endl;
    cout << "Salary: " << worker1.get_salary() << endl;

    cout << "Cashier: " << cashier1.get_cash() << endl;
    cout << "Owner: " << owner1.get_money() << endl;
    cout << "Cook: " << cook1.get_dishes() << endl;
    cout << "Waiter: " << waiter1.get_tips() << endl;
    cout << "Building: " << endl;
    cout << "Area: " << building1.get_area() << endl;
    cout << "Floors: " << building1.get_floors() << endl;
    cout << "Rooms: " << building1.get_rooms() << endl;
    cout << "Windows: " << building1.get_windows() << endl;
    cout << "Doors: " << building1.get_doors() << endl;

    // виклик методів
    cashier1.work();
    owner1.work();
    cook1.work();
    waiter1.work();



    return 0;
}