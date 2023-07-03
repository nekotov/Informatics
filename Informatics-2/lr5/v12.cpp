#include <iostream>
#include <vector>

using namespace std;

class Worker;
class Building;


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

    virtual void work(){
        cout << "I`m virtual work()" << endl;
        cout << "I'm working" << endl;
    }

    virtual void sayHi() = 0;

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

    void sayHi(){
        cout << "Hi, I`m cashier" << endl;
        cout << "this message was brought to you by virtual method sayHi()" << endl;
    }

    void work(){
        cout << "I`m working from non virtual method" << endl;
        cout << "I`m working, or no?????" << endl;
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

    void sayHi(){
        cout << "Hi, I`m owner" << endl;
        cout << "each related class should overwrite this func" << endl;
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

    void sayHi(){
        cout << "Hi, I`m cook" << endl;
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

    void sayHi(){
        cout << "Hi, I`m waiter" << endl;
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

    // copy constructor
    Building(const Building &b){
        this->area = b.area;
        this->floors = b.floors;
        this->rooms = b.rooms;
        this->windows = b.windows;
        this->doors = b.doors;

        cout << "copy constructor called" << endl;
    }

    virtual void calculate(){
        cout << "first calc" << endl;
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

class House : public Building{
    int residents;


    public:
    House(int residents, int area, int floors, int rooms, int windows, int doors) : Building(area, floors, rooms, windows, doors){
        this->residents = residents;
    }

    House(){
        House(1, 100, 1, 1, 1, 1);
    }

    void calculate(){
        cout << "second calc" << endl;
    }

    void set_residents(int residents){
        this->residents = residents;
    }

    void add_residents(int residents){
        this->set_residents(this->get_residents() + residents);
    }

    int get_residents(){
        return this->residents;
    }
};

class A{public: int _a;};
class B : virtual public A{public: int _b;}; // virtual
class C : virtual public B{public: int _c;}; // virtual
class D : public B,public C{public: int _d;};

void lr5(){
    //Привести приклад раннього та пізнього зв’язування для Вашої предметної області.
    //Раннє зв'язування
    Cook cook;
    cook.work();


    //Пізнє зв'язування
    Worker *worker2;
    Cashier cashier;

    worker2 = &cashier;
    worker2->work();

    // Виділити (мінімум 2) абстрактних класи. Зробити деякі з існуючих класів наслідниками цих абстрактних класів.
    // Абстрактний клас - Worker
    // Наслідники - Cashier, Owner, Cook, Waiter

    // Абстрактний клас - Building
    // Наслідники - House

    Building *building = new House();
    building->calculate();
    House *house = new House();
    house->calculate();

    // Описати приклад множинного наслідування між вже існуючими класами або довизначити нові класи для реалізації множинного наслідування.

    // Клас - Worker
    // Наслідники - Cashier, Owner, Cook, Waiter

    // Клас - Building
    // Наслідники - House


    //  Для одного з класів придумати конструктор копіювання.
    Building *building2 = new Building();
    Building *building3 = new Building(*building2);

    // Привести приклад проблеми повторного наслідування, вирішити її за допомогою визначення віртуального базового класу.

    cout << "diamond problem" << endl;
    D c;
    c._a = 1;




}

int main(){

    vector<Worker*> workers;
    vector<Building*> buildings;


    main:
    cout << "Interactive menu" << endl;
    cout << "1 - lr4" << endl;
    cout << "2 - lr5" << endl;
    cout << "3 - exit" << endl;

    int choice;
    cin >> choice;

    if(choice == 1) {
        cout << "1 - Create" << endl;
        cout << "2 - Show" << endl;
        cout << "3 - Back" << endl;

        cin >> choice;
        if (choice == 1) {
            cout << "1 - Create Worker" << endl;
            cout << "2 - Create Building" << endl;
            cout << "3 - Back" << endl;

            cin >> choice;
            if (choice == 1) {
                cout << "1 - Create Cashier" << endl;
                cout << "2 - Create Owner" << endl;
                cout << "3 - Create Cook" << endl;
                cout << "4 - Create Waiter" << endl;
                cout << "5 - Back" << endl;

                cin >> choice;
                if (choice == 1) {
                    Cashier *cashier = new Cashier();
                    workers.push_back(cashier);
                } else if (choice == 2) {
                    Owner *owner = new Owner();
                    workers.push_back(owner);
                } else if (choice == 3) {
                    Cook *cook = new Cook();
                    workers.push_back(cook);
                } else if (choice == 4) {
                    Waiter *waiter = new Waiter();
                    workers.push_back(waiter);
                } else if (choice == 5) {
                    goto main;
                } else {
                    goto main;
                }
            } else if (choice == 2) {
                cout << "1 - Create House" << endl;
                cout << "2 - Back" << endl;

                cin >> choice;
                if (choice == 1) {
                    House *house = new House();
                    buildings.push_back(house);
                } else if (choice == 2) {
                    goto main;
                } else {
                    goto main;
                }
            } else if (choice == 3) {
                goto main;
            } else {
                goto main;
            }
        }
        else if(choice==2){
            cout << "1 - Show Workers" << endl;
            cout << "2 - Show Buildings" << endl;
            cout << "3 - Back" << endl;

            cin >> choice;
            if(choice == 1){
                for(int i = 0; i < workers.size(); i++){
                    cout << "Worker " << i << endl;
                    workers[i]->work();
                }
            }
            else if(choice == 2){
                for(int i = 0; i < buildings.size(); i++){
                    cout << "Building " << i << endl;
                    buildings[i]->calculate();
                }
            }
            else if(choice == 3){
                goto main;
            }
            else{
                goto main;
            }
        }
        else if(choice == 3){
            goto main;
        }
    }
    else if(choice == 2)
        lr5();
    else if(choice == 3)
        return 0;
    else
        goto main;

    goto main;

    return 0;
}