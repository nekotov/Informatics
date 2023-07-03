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
        name = "Dan";
        sex = 'm';
    }
    Person(int age, string name, char sex) {
        this->age = age;
        this->name = name;
        this->sex = sex;
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
        cout << this->name << this->age << endl;
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

class Vakhter: public Person {
protected:
    int workExperience;
public:
    Vakhter() :Person() {
        workExperience = 10;
    }
    Vakhter(int age, string name, char sex, int workExperience)
        :Person(age, name, sex) {
        this->workExperience = workExperience;
    }
    void setWorkExperience(int workExperience) {
        this->workExperience = workExperience;
    }
    int getWorkExperience() {
        return workExperience;
    }
    friend ostream& operator <<(ostream& out, const Vakhter& obj);
    friend istream& operator >>(istream& input, Vakhter& obj);

    void print(){
        cout << this->name << this->workExperience << endl;
    }
};

ostream& operator<<(ostream& out, const Vakhter& obj) { 
    out << "Name: " << obj.name << "\nAge: " << obj.age << "\nSex: " << obj.sex << "\nWork experience: " << obj.workExperience << endl;
    return out;
}

istream& operator>>(istream& input, Vakhter& obj) {
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

class Room{
protected:
    int number;
    int places;
    int floor;
public:
    Room() {
        number = 12;
        places = 2;
        floor = 1;
    }
    Room(int number, int places, int floor) {
        this->number = number;
        this->places = places;
        this->floor = floor;
    }

    void setNumber() {
        this->number = number;
    }
    void setPlaces() {
        this->places = places;
    }
    void setFloor() {
        this->floor = floor;
    }
    int getNumber() {
        return number;
    }
    int getPlaces() {
        return places;
    }
    int getFloor() {
        return floor;
    }
    friend ostream& operator <<(ostream& out, const Room& obj);
    friend istream& operator >>(istream& input, Room& obj);
};

ostream& operator<<(ostream& out, const Room& obj){ 
    out << "Number: " << obj.number << "\nPlaces: " << obj.places << "\nFloor: " << obj.floor << endl;
    return out;
}

istream& operator>>(istream& input, Room& obj) { 
    cout << "Number: ";
    input >> obj.number;
    cout << "Places: ";
    input >> obj.places;
    cout << "Floor: ";
    input >> obj.floor;
    return input;
}

struct Node {
    Room data;
    Node* next;
};

class RoomInfo{
protected:
    Person person;
    Vakhter vakhter;
    Node* head; 
public:
    RoomInfo() {
        head = NULL; 
    }
    RoomInfo(Person person, Vakhter vakhter) {
        this->person = person;
        this->vakhter = vakhter;
    }
    void addRoom(Room d) {
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
        cout << "Vakhter:" << endl;
        cout << vakhter << endl;
        Node* current = head;
        while (current != NULL) {
            cout << current->data << endl;
            current = current->next;
        }
    }
};

class Building {
protected:
    int floors;
    int rooms;
    int places;
public:
Building() {
        floors = 1;
        rooms = 1;
        places = 1;
    }
    Building(int floors, int rooms, int places) {
        this->floors = floors;
        this->rooms = rooms;
        this->places = places;
    }
    void setFloors(int floors) {
        this->floors = floors;
    }
    void setRooms(int rooms) {
        this->rooms = rooms;
    }
    void setPlaces(int places) {
        this->places = places;
    }
    int getFloors() {
        return floors;
    }
    int getRooms() {
        return rooms;
    }
    int getPlaces() {
        return places;
    }
    virtual void print() = 0;
};

class SmallHouse : public Building {
public:
    SmallHouse() :Building() {}
    SmallHouse(int floors, int rooms, int places) :Building(floors, rooms, places) {}
    void print() {
        cout << "Small house:\nFloors: " << floors << "\nRooms: " << rooms << "\nPlaces: " << places << endl;
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

void lr4(){
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
    Room roomPlan;

    cin >> you;
    cout << "Today vakhter is: \n";
    Vakhter vakhta(rand() % 40 + 20, names[rand() % 10 + 1], sex[rand() % 2], rand() % 20 + 1);
    RoomInfo roomInfo(you, vakhta);
    cout << vakhta;
    while (true) {
        cout << "Do you want to get the room? (1 - yes, 2 - no)\n";
        int choice;
        cin >> choice;
        if (choice == 1) {
            cout << "Enter which room you want to take: \n";
            cin >> roomPlan;
            roomInfo.addRoom(roomPlan);
        } else {
            cout << "Do you want to see the information of your rooms?\n1 - yes\n2 - no\n";
            cin >> choice;
            if (choice == 1) {
                roomInfo.print();
            }
            else
                return;
        }
    }
}

void SayHello(string name) {
    cout << "Hello, " << name << endl;
}

void lr5(){
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
    // class Building - абстрактний клас
    // class SmallHouse - наслідується від Building
    Building *building = new SmallHouse(1, 1, 1);
    building->print();

    // class Person - абстрактний клас
    // class Vakhter - наслідується від Person
    Person *person = new Vakhter(20, "Max", 'm', 1);
    person->print();

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

int main() {

    lr5();

}