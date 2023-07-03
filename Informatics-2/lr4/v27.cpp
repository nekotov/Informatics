#include <iostream>
#include <vector>

using namespace std;


class Person{
    protected:
        string name;
        double hours;
        int pc_num;
    public:

    Person(){
        name = "NoName";
        hours = 0;
        pc_num = 0;
    }

    Person(string name, double hours, int pc_num){
        this->name = name;
        this->hours = hours;
        this->pc_num = pc_num;
    }

    ~Person(){
        cout << "Person " << name << " deleted" << endl;
    }

    void print(){
        cout << "Name: " << name << endl;
        cout << "Hours: " << hours << endl;
        cout << "PC number: " << pc_num << endl;
    }

    void set_name(string name){
        this->name = name;
    }

    void set_hours(double hours){
        this->hours = hours;
    }

    void set_pc_num(int pc_num){
        this->pc_num = pc_num;
    }

    string get_name(){
        return name;
    }

    double get_hours(){
        return hours;
    }

    int get_pc_num(){
        return pc_num;
    }

};

class Worker : public Person{
protected:
    double salary;
    float working_hours;
    int id;

public:

    Worker(){
        salary = 0;
        working_hours = 0;
        id = 0;
    }

    Worker(string name, double hours, int pc_num, double salary, float working_hours, int id) : Person(name, hours, pc_num){
        this->salary = salary;
        this->working_hours = working_hours;
        this->id = id;
    }

    ~Worker(){
        cout << "Worker " << name << " deleted" << endl;
    }

    void print(){
        Person::print();
        cout << "Salary: " << salary << endl;
        cout << "Working hours: " << working_hours << endl;
        cout << "ID: " << id << endl;
    }

    void set_salary(double salary){
        this->salary = salary;
    }

    void set_working_hours(float working_hours){
        this->working_hours = working_hours;
    }

    void set_id(int id){
        this->id = id;
    }

    double get_salary(){
        return salary;
    }

    float get_working_hours(){
        return working_hours;
    }

    int get_id(){
        return id;
    }

};

class User : public Person{
protected:
    string login;
    string password;
    int id;

public:

    User(){
        login = "NoLogin";
        password = "NoPassword";
        id = 0;
    }

    User(string name, double hours, int pc_num, string login, string password, int id) : Person(name, hours, pc_num){
        this->login = login;
        this->password = password;
        this->id = id;
    }

    ~User(){
        cout << "User " << name << " deleted" << endl;
    }

    void print(){
        Person::print();
        cout << "Login: " << login << endl;
        cout << "Password: " << password << endl;
        cout << "ID: " << id << endl;
    }

    void set_login(string login){
        this->login = login;
    }

    void set_password(string password){
        this->password = password;
    }

    void set_id(int id){
        this->id = id;
    }

    string get_login(){
        return login;
    }

    string get_password(){
        return password;
    }

    int get_id(){
        return id;
    }
};

class Building{
protected:
    string address;
    int floors;
    int rooms;

public:

    Building(){
        address = "NoAddress";
        floors = 0;
        rooms = 0;
    }

    Building(string address, int floors, int rooms){
        this->address = address;
        this->floors = floors;
        this->rooms = rooms;
    }

    ~Building(){
        cout << "Building " << address << " deleted" << endl;
    }

    void print(){
        cout << "Address: " << address << endl;
        cout << "Floors: " << floors << endl;
        cout << "Rooms: " << rooms << endl;
    }

    void set_address(string address){
        this->address = address;
    }

    void set_floors(int floors){
        this->floors = floors;
    }

    void set_rooms(int rooms){
        this->rooms = rooms;
    }

    string get_address(){
        return address;
    }

    int get_floors(){
        return floors;
    }

    int get_rooms(){
        return rooms;
    }
};

class Advertisement{
protected:
    string name;
    string text;
    int id;

public:

    Advertisement(){
        name = "NoName";
        text = "NoText";
        id = 0;
    }

    Advertisement(string name, string text, int id){
        this->name = name;
        this->text = text;
        this->id = id;
    }

    ~Advertisement(){
        cout << "Advertisement " << name << " deleted" << endl;
    }

    void print(){
        cout << "Name: " << name << endl;
        cout << "Text: " << text << endl;
        cout << "ID: " << id << endl;
    }

    void set_name(string name){
        this->name = name;
    }

    void set_text(string text){
        this->text = text;
    }

    void set_id(int id){
        this->id = id;
    }

    string get_name(){
        return name;
    }

    string get_text(){
        return text;
    }

    int get_id(){
        return id;
    }
};


int main(){
    vector<Person*> persons;
    vector<Worker*> workers;
    vector<User*> users;
    vector<Building*> buildings;
    vector<Advertisement*> advertisements;

    cout << "Welcome to Computer Club" << endl;
    menu:
    cout << "1. Create" << endl;
    cout << "2. Show" << endl;
    cout << "3. Exit" << endl;

    int choice;
    cin >> choice;

    if(choice==1){
        cout << "What do you want to create?" << endl;
        cout << "1. Person" << endl;
        cout << "2. Worker" << endl;
        cout << "3. User" << endl;
        cout << "4. Building" << endl;
        cout << "5. Advertisement" << endl;

        int choice2;
        cin >> choice2;

        if(choice2==1){
            cout << "Enter name: ";
            string name;
            cin >> name;
            cout << "Enter hours: ";
            double hours;
            cin >> hours;
            cout << "Enter pc number: ";
            int pc_num;
            cin >> pc_num;

            Person* person = new Person(name, hours, pc_num);
            persons.push_back(person);
        }
        else if(choice2==2){
            cout << "Enter name: ";
            string name;
            cin >> name;
            cout << "Enter hours: ";
            double hours;
            cin >> hours;
            cout << "Enter pc number: ";
            int pc_num;
            cin >> pc_num;
            cout << "Enter salary: ";
            double salary;
            cin >> salary;
            cout << "Enter working hours: ";
            float working_hours;
            cin >> working_hours;
            cout << "Enter id: ";
            int id;
            cin >> id;

            Worker* worker = new Worker(name, hours, pc_num, salary, working_hours, id);
            workers.push_back(worker);
        }
        else if(choice2==3){
            cout << "Enter name: ";
            string name;
            cin >> name;
            cout << "Enter hours: ";
            double hours;
            cin >> hours;
            cout << "Enter pc number: ";
            int pc_num;
            cin >> pc_num;
            cout << "Enter login: ";
            string login;
            cin >> login;
            cout << "Enter password: ";
            string password;
            cin >> password;
            cout << "Enter id: ";
            int id;
            cin >> id;

            User* user = new User(name, hours, pc_num, login, password, id);
            users.push_back(user);
        }
        else if(choice2==4) {
            cout << "Enter address: ";
            string address;
            cin >> address;
            cout << "Enter floors: ";
            int floors;
            cin >> floors;
            cout << "Enter rooms: ";
            int rooms;
            cin >> rooms;

            Building *building = new Building(address, floors, rooms);
            buildings.push_back(building);
        }
        else if(choice2==5) {
            cout << "Enter name: ";
            string name;
            cin >> name;
            cout << "Enter text: ";
            string text;
            cin >> text;
            cout << "Enter id: ";
            int id;
            cin >> id;

            Advertisement *advertisement = new Advertisement(name, text, id);
            advertisements.push_back(advertisement);
        }

    }
    else if(choice==2){
cout << "What do you want to show?" << endl;
        cout << "0. Show all" << endl;
        cout << "1. Person" << endl;
        cout << "2. Worker" << endl;
        cout << "3. User" << endl;
        cout << "4. Building" << endl;
        cout << "5. Advertisement" << endl;

        int choice2;
        cin >> choice2;

        if(choice2==1){
            for(int i=0; i<persons.size(); i++){
                persons[i]->print();
            }
        }
        else if(choice2==2){
            for(int i=0; i<workers.size(); i++){
                workers[i]->print();
            }
        }
        else if(choice2==3){
            for(int i=0; i<users.size(); i++){
                users[i]->print();
            }
        }
        else if(choice2==4){
            for(int i=0; i<buildings.size(); i++){
                buildings[i]->print();
            }
        }
        else if(choice2==5){
            for(int i=0; i<advertisements.size(); i++){
                advertisements[i]->print();
            }
        }
        else if(choice2==0){
            for(int i=0; i<persons.size(); i++){
                persons[i]->print();
            }
            for(int i=0; i<workers.size(); i++){
                workers[i]->print();
            }
            for(int i=0; i<users.size(); i++){
                users[i]->print();
            }
            for(int i=0; i<buildings.size(); i++){
                buildings[i]->print();
            }
            for(int i=0; i<advertisements.size(); i++){
                advertisements[i]->print();
            }
        }
    }
    else if(choice==3){
        cout << "Goodbye" << endl;
        exit(0);
    }

    goto menu;

    return 0;
}