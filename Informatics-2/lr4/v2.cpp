#include <iostream>
#include <vector>

using namespace std;

class Person {
protected:
    string name;
    string surname;
    int age;

    public:
    Person(string name, string surname, int age){
        this->name = name;
        this->surname = surname;
        this->age = age;
    }

    Person(){
        this->name = "Ivan";
        this->surname = "Ivanov";
        this->age = 24;
    }

    void set_name(string name){
        this->name = name;
    }

    void set_surname(string surname){
        this->surname = surname;
    }

    void set_age(int age){
        this->age = age;
    }

    string get_name(){
        return this->name;
    }

    string get_surname(){
        return this->surname;
    }

    int get_age(){
        return this->age;
    }

};

class Doctor : public Person{
    string specialization;
    int experience;

    public:
    Doctor(string name, string surname, int age, string specialization, int experience) : Person(name, surname, age){
        this->specialization = specialization;
        this->experience = experience;
    }

    Doctor() : Person(){
        this->specialization = "surgeon";
        this->experience = 5;
    }

    void set_specialization(string specialization){
        this->specialization = specialization;
    }

    void set_experience(int experience){
        this->experience = experience;
    }

    string get_specialization(){
        return this->specialization;
    }

    int get_experience(){
        return this->experience;
    }

    void sayHi(){
        cout << "Hi, I'm doctor " << this->name << " " << this->surname << endl;
    }

    void work(){
        cout << "I'm working" << endl;
    }

    void do_surgery(){
        cout << "I'm doing surgery" << endl;
    }

    void write_recipe(){
        cout << "I'm writing recipe" << endl;
    }

    void check_patient(){
        cout << "I'm checking patient" << endl;
    }
};

class Patient : public Person{
    string disease;
    string doctor;

    public:
    Patient(string name, string surname, int age, string disease, string doctor) : Person(name, surname, age){
        this->disease = disease;
        this->doctor = doctor;
    }

    Patient() : Person(){
        this->disease = "flu";
        this->doctor = "Ivan Ivanov";
    }

    void set_disease(string disease){
        this->disease = disease;
    }

    void set_doctor(string doctor){
        this->doctor = doctor;
    }

    string get_disease(){
        return this->disease;
    }

    string get_doctor(){
        return this->doctor;
    }

    void sayHi(){
        cout << "Hi, I'm patient " << this->name << " " << this->surname << endl;
    }

    void work(){
        cout << "I'm working" << endl;
    }

    void take_pills(){
        cout << "I'm taking pills" << endl;
    }

    void do_injections(){
        cout << "I'm doing injections" << endl;
    }

    void do_tests(){
        cout << "I'm doing tests" << endl;
    }
};

class Nurse : public Person{
    string specialization;
    int experience;

    public:
    Nurse(string name, string surname, int age, string specialization, int experience) : Person(name, surname, age){
        this->specialization = specialization;
        this->experience = experience;
    }

    Nurse() : Person(){
        this->specialization = "surgeon";
        this->experience = 5;
    }

    void set_specialization(string specialization){
        this->specialization = specialization;
    }

    void set_experience(int experience){
        this->experience = experience;
    }

    string get_specialization(){
        return this->specialization;
    }

    int get_experience(){
        return this->experience;
    }

    void sayHi(){
        cout << "Hi, I'm nurse " << this->name << " " << this->surname << endl;
    }

    void work(){
        cout << "I'm working" << endl;
    }

    void take_pills(){
        cout << "I'm taking pills" << endl;
    }

    void do_injections(){
        cout << "I'm doing injections" << endl;
    }

    void do_tests(){
        cout << "I'm doing tests" << endl;
    }
};

class Building {
protected:
    string address;
    int floors;
    int capacity;

    public:
    Building(string address, int floors, int capacity){
        this->address = address;
        this->floors = floors;
        this->capacity = capacity;
    }

    Building(){
        this->address = "Kiev, Khreshchatyk";
        this->floors = 5;
        this->capacity = 100;
    }

    void set_address(string address){
        this->address = address;
    }

    void set_floors(int floors){
        this->floors = floors;
    }

    void set_capacity(int capacity){
        this->capacity = capacity;
    }

    string get_address(){
        return this->address;
    }

    int get_floors(){
        return this->floors;
    }

    int get_capacity(){
        return this->capacity;
    }
};

class Hospital : public Building{
    string specialization;
    int doctors;
    int nurses;

    public:
    Hospital(string address, int floors, int capacity, string specialization, int doctors, int nurses) : Building(address, floors, capacity){
        this->specialization = specialization;
        this->doctors = doctors;
        this->nurses = nurses;
    }

    Hospital() : Building(){
        this->specialization = "surgeon";
        this->doctors = 5;
        this->nurses = 10;
    }

    void set_specialization(string specialization){
        this->specialization = specialization;
    }

    void set_doctors(int doctors){
        this->doctors = doctors;
    }

    void set_nurses(int nurses){
        this->nurses = nurses;
    }

    string get_specialization(){
        return this->specialization;
    }

    int get_doctors(){
        return this->doctors;
    }

    int get_nurses(){
        return this->nurses;
    }
};

class Ambulance : public Building{
    string specialization;
    int doctors;
    int nurses;

    public:
    Ambulance(string address, int floors, int capacity, string specialization, int doctors, int nurses) : Building(address, floors, capacity){
        this->specialization = specialization;
        this->doctors = doctors;
        this->nurses = nurses;
    }

    Ambulance() : Building(){
        this->specialization = "surgeon";
        this->doctors = 5;
        this->nurses = 10;
    }

    void set_specialization(string specialization){
        this->specialization = specialization;
    }

    void set_doctors(int doctors){
        this->doctors = doctors;
    }

    void set_nurses(int nurses){
        this->nurses = nurses;
    }

    string get_specialization(){
        return this->specialization;
    }

    int get_doctors(){
        return this->doctors;
    }

    int get_nurses(){
        return this->nurses;
    }
};

class Syringe{
protected:
    string type;
    int volume;
    bool used;

    public:
    Syringe(string type, int volume, bool used){
        this->type = type;
        this->volume = volume;
        this->used = used;
    }

    Syringe(){
        this->type = "insulin";
        this->volume = 10;
        this->used = false;
    }

    void set_type(string type){
        this->type = type;
    }

    void set_volume(int volume){
        this->volume = volume;
    }

    void set_used(bool used){
        this->used = used;
    }

    string get_type(){
        return this->type;
    }

    int get_volume(){
        return this->volume;
    }

    bool get_used(){
        return this->used;
    }

    void inject(){
        cout << "I'm injecting" << endl;
    }
};

int main(){
    vector<Person> persons;
    vector<Building> buildings;
    vector<Syringe> syringes;

    back:

    cout << "Interactive menu:" << endl;
    cout << "1. Create" << endl;
    cout << "2. Show" << endl;
    cout << "3. Exit" << endl;

    int choice;
    cin >> choice;

    if(choice == 1){
        cout << "1. Create person" << endl;
        cout << "2. Create building" << endl;
        cout << "3. Create syringe" << endl;

        int choice2;
        cin >> choice2;

        if(choice2 == 1){
            cout << "1. Create patient" << endl;
            cout << "2. Create doctor" << endl;
            cout << "3. Create nurse" << endl;

            int choice3;
            cin >> choice3;

            if(choice3 == 1){
                cout << "Enter name, surname, age, disease, doctor's name, doctor's surname, doctor's age" << endl;
                string name, surname, disease, doctor_name;
                int age;
                cin >> name >> surname >> age >> disease >> doctor_name;
                Patient patient(name, surname, age, disease, doctor_name);
                persons.push_back(patient);
            }else if(choice3 == 2){
                cout << "Enter name, surname, age, specialization, experience" << endl;
                string name, surname, specialization;
                int age, experience;
                cin >> name >> surname >> age >> specialization >> experience;
                Doctor doctor(name, surname, age, specialization, experience);
                persons.push_back(doctor);
            }else if(choice3 == 3){
                cout << "Enter name, surname, age, specialization, experience" << endl;
                string name, surname, specialization;
                int age, experience;
                cin >> name >> surname >> age >> specialization >> experience;
                Nurse nurse(name, surname, age, specialization, experience);
                persons.push_back(nurse);
            }else{
                cout << "Wrong input" << endl;
            }
        }
        else if(choice2 == 2){
            cout << "1. Create hospital" << endl;
            cout << "2. Create ambulance" << endl;

            int choice3;
            cin >> choice3;

            if(choice3 == 1){
                cout << "Enter address, floors, capacity, specialization, doctors, nurses" << endl;
                string address, specialization;
                int floors, capacity, doctors, nurses;
                cin >> address >> floors >> capacity >> specialization >> doctors >> nurses;
                Hospital hospital(address, floors, capacity, specialization, doctors, nurses);
                buildings.push_back(hospital);
            }else if(choice3 == 2){
                cout << "Enter address, floors, capacity, specialization, doctors, nurses" << endl;
                string address, specialization;
                int floors, capacity, doctors, nurses;
                cin >> address >> floors >> capacity >> specialization >> doctors >> nurses;
                Ambulance ambulance(address, floors, capacity, specialization, doctors, nurses);
                buildings.push_back(ambulance);
            }else{
                cout << "Wrong input" << endl;
            }
        }
        else if(choice2 == 3){
            cout << "Enter type, volume, used" << endl;
            string type;
            int volume;
            bool used;
            cin >> type >> volume >> used;
            Syringe syringe(type, volume, used);
            syringes.push_back(syringe);
        }
        else{
            cout << "Wrong input" << endl;
        }
    }
    else if(choice == 2){
        cout << "1. Show persons" << endl;
        cout << "2. Show buildings" << endl;
        cout << "3. Show syringes" << endl;

        int choice2;
        cin >> choice2;

        if(choice2 == 1){
            for(int i = 0; i < persons.size(); i++){
                cout << persons[i].get_name() << " " << persons[i].get_surname() << " " << persons[i].get_age() << endl;
            }
        }
        else if(choice2 == 2){
            for(int i = 0; i < buildings.size(); i++){
                cout << buildings[i].get_address() << " " << buildings[i].get_floors() << " " << buildings[i].get_capacity() << endl;
            }
        }
        else if(choice2 == 3){
            for(int i = 0; i < syringes.size(); i++){
                cout << syringes[i].get_type() << " " << syringes[i].get_volume() << " " << syringes[i].get_used() << endl;
            }
        }
        else{
            cout << "Wrong input" << endl;
        }
    }
    else if(choice == 3){
        cout << "Exiting..." << endl;
    }

    goto back;

}