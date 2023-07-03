#include <iostream>
#include <vector>
using namespace std;

class Person{
protected:
    string name;
    int age;
public:
    Person(string name, int age){
        this->name = name;
        this->age = age;
    }
    Person(){
        this->name = "Ivan";
        this->age = 20;
    }
    void set_name(string name){
        this->name = name;
    }
    void set_age(int age){
        this->age = age;
    }
    string get_name(){
        return this->name;
    }
    int get_age(){
        return this->age;
    }
};

class Artist : public Person{
protected:
    string genre;
    int salary;
public:
    Artist(string name, int age, string genre, int salary) : Person(name, age){
        this->genre = genre;
        this->salary = salary;
    }
    Artist() : Person(){
        this->genre = "clown";
        this->salary = 1000;
    }
    void set_genre(string genre){
        this->genre = genre;
    }
    void set_salary(int salary){
        this->salary = salary;
    }
    string get_genre(){
        return this->genre;
    }
    int get_salary(){
        return this->salary;
    }
    void sayHi(){
        cout << "Hi, I'm " << this->name << " and I'm " << this->age << " years old. I'm a " << this->genre << " and I earn " << this->salary << " dollars per month." << endl;
    }
};

class Viewer : public Person{
protected:
    int money;
    int place;
public:
    Viewer(string name, int age, int money, int place) : Person(name, age){
        this->money = money;
        this->place = place;
    }
    Viewer() : Person(){
        this->money = 100;
        this->place = 1;
    }
    void set_money(int money){
        this->money = money;
    }
    void set_place(int place){
        this->place = place;
    }
    int get_money(){
        return this->money;
    }
    int get_place(){
        return this->place;
    }
    void sayHi(){
        cout << "Hi, I'm " << this->name << " and I'm " << this->age << " years old. I have " << this->money << " dollars and I'm sitting on " << this->place << " place." << endl;
    }
};

class Animal{
protected:
    string name;
    string type;
public:
    Animal(string name, string type){
        this->name = name;
        this->type = type;
    }
    Animal(){
        this->name = "Lion";
        this->type = "predator";
    }
    void set_name(string name){
        this->name = name;
    }
    void set_type(string type){
        this->type = type;
    }
    string get_name(){
        return this->name;
    }
    string get_type(){
        return this->type;
    }
};

class Lion : public Animal{
protected:
    int age;
    int weight;
public:
    Lion(string name, string type, int age, int weight) : Animal(name, type){
        this->age = age;
        this->weight = weight;
    }
    Lion() : Animal(){
        this->age = 5;
        this->weight = 200;
    }
    void set_age(int age){
        this->age = age;
    }
    void set_weight(int weight){
        this->weight = weight;
    }
    int get_age(){
        return this->age;
    }
    int get_weight(){
        return this->weight;
    }
};

class Tiger : public Animal{
protected:
    int age;
    int weight;

public:
    Tiger(string name, string type, int age, int weight) : Animal(name, type){
        this->age = age;
        this->weight = weight;
    }
    Tiger() : Animal(){
        this->age = 3;
        this->weight = 150;
    }
    void set_age(int age){
        this->age = age;
    }
    void set_weight(int weight){
        this->weight = weight;
    }
    int get_age(){
        return this->age;
    }
    int get_weight(){
        return this->weight;
    }
};

int main(){
    vector<Artist> artists;
    vector<Viewer> viewers;
    vector<Lion> lions;
    vector<Tiger> tigers;

    menu:

    cout << "Interactive menu:" << endl;
    cout << "1. Create" << endl;
    cout << "2. Show" << endl;
    cout << "3. Exit" << endl;

    int choice;
    cin >> choice;

    if(choice==1){
        cout << "1. Artist" << endl;
        cout << "2. Viewer" << endl;
        cout << "3. Lion" << endl;
        cout << "4. Tiger" << endl;

        int choice2;
        cin >> choice2;

        if(choice2==1){
            cout << "Enter name, age, genre and salary" << endl;
            string name;
            int age;
            string genre;
            int salary;
            cin >> name >> age >> genre >> salary;
            Artist artist(name, age, genre, salary);
            artists.push_back(artist);
        }
        else if(choice2==2){
            cout << "Enter name, age, money and place" << endl;
            string name;
            int age;
            int money;
            int place;
            cin >> name >> age >> money >> place;
            Viewer viewer(name, age, money, place);
            viewers.push_back(viewer);
        }
        else if(choice2==3){
            cout << "Enter name, type, age and weight" << endl;
            string name;
            string type;
            int age;
            int weight;
            cin >> name >> type >> age >> weight;
            Lion lion(name, type, age, weight);
            lions.push_back(lion);
        }
        else if(choice2==4){
            cout << "Enter name, type, age and weight" << endl;
            string name;
            string type;
            int age;
            int weight;
            cin >> name >> type >> age >> weight;
            Tiger tiger(name, type, age, weight);
            tigers.push_back(tiger);
        }
    }
    else if(choice==2){
        cout << "Artists:" << endl;
        for(int i=0; i<artists.size(); i++){
            artists[i].sayHi();
        }

        cout << "Viewers:" << endl;
        for(int i=0; i<viewers.size(); i++){
            viewers[i].sayHi();
        }

        cout << "Lions:" << endl;
        for(int i=0; i<lions.size(); i++){
            cout << "-------------------" << endl;
            cout << "Name: " << lions[i].get_name() << endl;
            cout << "Type: " << lions[i].get_type() << endl;
            cout << "Age: " << lions[i].get_age() << endl;
            cout << "Weight: " << lions[i].get_weight() << endl;
            cout << "-------------------" << endl;
        }

        cout << "Tigers:" << endl;
        for(int i=0; i<tigers.size(); i++){
            cout << "-------------------" << endl;
            cout << "Name: " << tigers[i].get_name() << endl;
            cout << "Type: " << tigers[i].get_type() << endl;
            cout << "Age: " << tigers[i].get_age() << endl;
            cout << "Weight: " << tigers[i].get_weight() << endl;
            cout << "-------------------" << endl;
        }
    }
    else if(choice==3){
        return 0;
    }
    else{
        cout << "Wrong input" << endl;
    }

    goto menu;

}