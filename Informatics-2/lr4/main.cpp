#include <iostream>
#include <string>
#include <vector>

const int K = 10;
const  int G = 3;

using namespace std;

namespace Pharmacy {

    class Worker{
        bool Working = false;
        bool Trainie = false;
        string phoneNum;
        string name;
        string position;


    public:
        Worker(){
            this->name = "No name";
            this->phoneNum = "No phone number";
        }

        Worker(string name, string phoneNum){
            this->name = name;
            this->phoneNum = phoneNum;
        }

        void joined(){
            if(this->Working){
                cout << "This worker is already working" << endl;
            }else{
                this->Working = true;
            }
        }

        void left(){
            if(!this->Working){
                cout << "This worker is not working" << endl;
            }else{
                this->Working = false;
            }
        }

        void trainie(){
            if(this->Trainie){
                cout << "This worker is already trainie" << endl;
            }else{
                this->Trainie = true;
            }
        }

        void untrainie(){
            if(!this->Trainie){
                cout << "This worker is not trainie" << endl;
            }else{
                this->Trainie = false;
            }
        }

        bool isWorking(){
            return this->Working;
        }

        bool isTrainie(){
            return this->Trainie;
        }

        string getPhoneNum(){
            return this->phoneNum;
        }

        string getName(){
            return this->name;
        }

        string getPosition(){
            return this->position;
        }

        void setPositon(string position){
            this->position = position;
        }

        void setPhoneNum(string phoneNum){
            this->phoneNum = phoneNum;
        }

        void setName(string name){
            this->name = name;
        }


        void setTrainie(bool b) {
            this->Trainie = b;
        }
    };

    class Trainie : public Worker{
        public:
        Trainie(string name, string phoneNum) : Worker(name, phoneNum){
            this->trainie();
            this->setPositon("Trainie");
        }
    };

    class Owner : public Worker{
        public:
        Owner(string name, string phoneNum) : Worker(name, phoneNum){
            this->joined();
            this->setPositon("Owner");
        }
    };

    class Seller : public Worker{
        public:
        Seller(string name, string phoneNum) : Worker(name, phoneNum){
            this->joined();
            this->setPositon("Seller");
        }
    };

    class Security : public Worker{
        public:
        Security(string name, string phoneNum) : Worker(name, phoneNum){
            this->joined();
            this->setPositon("Security");
        }
    };

    class Cleaner : public Worker{
        public:
        Cleaner(string name, string phoneNum) : Worker(name, phoneNum){
            this->joined();
            this->setPositon("Cleaner");
        }
    };

    class Admin : public Worker{
        public:
        Admin(string name, string phoneNum) : Worker(name, phoneNum){
            this->setPositon("Admin");
        }
    };

    class Storage{
        bool isWorking = false;
        long long Volume;
        long long UsedVolume;

        public:
        Storage(){
            this->Volume = 0;
            this->UsedVolume = 0;
        }
        Storage(long long Volume){
            this->Volume = Volume;
            this->UsedVolume = 0;
        }

        void setVolume(long long Volume){
            this->Volume = Volume;
        }

        void setUsedVolume(long long UsedVolume){
            this->UsedVolume = UsedVolume;
        }

        long long getVolume(){
            return this->Volume;
        }

        long long getUsedVolume(){
            return this->UsedVolume;
        }

        void addVolume(long long Volume){
            this->Volume += Volume;
        }

        void addUsedVolume(long long UsedVolume){
            this->UsedVolume += UsedVolume;
        }
    };

    class Casa{
        bool isWorking = false;
        long long Money;
        int uid;

        public:

        Casa(){
            this->Money = 0;
            this->uid = 0;
        }

        Casa(int id){
            this->Money = 0;
            this->uid = id;
        }

        void setMoney(long long Money){
            this->Money = Money;
        }

        void addMoney(long long Money){
            this->Money += Money;
        }

        long long getMoney(){
            return this->Money;
        }

        int getUid(){
            return this->uid;
        }

        void setUid(int uid){
            this->uid = uid;
        }

        void Open(){
            if(this->isWorking){
                cout << "This casa is already working" << endl;
            }else{
                this->isWorking = true;
            }
        }

        void Close(){
            if(!this->isWorking){
                cout << "This casa is not working" << endl;
            }else{
                this->isWorking = false;
            }
        }
    };

    class Building{
        string adress;
        int volume;
        int floors;

        public:
        Building(){
            this->adress = "No adress";
            this->volume = 0;
            this->floors = 0;
        }

        Building(string adress, int volume, int floors){
            this->adress = adress;
            this->volume = volume;
            this->floors = floors;
        }

        void setAdress(string adress){
            this->adress = adress;
        }

        void setVolume(int volume){
            this->volume = volume;
        }

        void setFloors(int floors){
            this->floors = floors;
        }

        string getAdress(){
            return this->adress;
        }

        int getVolume(){
            return this->volume;
        }

        int getFloors(){
            return this->floors;
        }
    };

};

int main() {

    vector<Pharmacy::Worker> workers;
    vector<Pharmacy::Building> buildings;
    vector<Pharmacy::Casa> casas;
    vector<Pharmacy::Storage> storages;


    cout << "Welcome to the Pharmacy" << endl;
    cout << "1. Create new Pharmacy" << endl;
    cout << "2. Exit" << endl;
    int choice;
    cin >> choice;
    if(choice != 1)
        exit(0);

    menu:
    cout << "1. Create..." << endl;
    cout << "2. Edit..." << endl;
    cout << "3. Exit" << endl;
    cin >> choice;
    if(choice == 3)
        exit(0);
    if(choice == 1)
        goto create;
    else if(choice == 2)
        goto edit;
    else if (choice == 3)
        goto exit;
    else
        goto menu;

    edit:
    cout << "1. Edit Worker" << endl;
    cout << "2. Edit Building" << endl;
    cout << "3. Edit Casa" << endl;
    cout << "4. Edit Storage" << endl;
    cout << "5. Exit" << endl;
    cin >> choice;
    if(choice == 1) {
        cout << "We have: " << workers.size() << " workers" << endl;
        if(workers.size() < 1){
            cout << "You have no workers" << endl;
            goto edit;
        }
        cout << "Enter phone number of worker: ";
        string phoneNum;
        cin >> phoneNum;
        for(int i = 0; i < workers.size(); i++){
            if(workers[i].getPhoneNum() == phoneNum){
                cout << "1. Edit name" << endl;
                cout << "2. Edit phone number" << endl;
                cout << "3. Edit position" << endl;
                cout << "4. Edit status of Trainie" << endl;
                cout << "5. Fire" << endl;
                cout << "6. Exit" << endl;

                int choice2;
                cin >> choice2;
                if(choice2 == 1){
                    cout << "Enter new name: ";
                    string name;
                    cin >> name;
                    workers[i].setName(name);
                }
                else if(choice2 == 2){
                    cout << "Enter new phone number: ";
                    string phoneNum;
                    cin >> phoneNum;
                    workers[i].setPhoneNum(phoneNum);
                }
                else if(choice2 == 3){
                    cout << "Enter new position: ";
                    string position;
                    cin >> position;
                    workers[i].setPositon(position);
                }
                else if(choice2 == 4){
                    cout << "Enter new status of Trainie (1 or 0):";
                    bool status;
                    cin >> status;
                    workers[i].setTrainie(status);
                }
                else if(choice2 == 5){
                    workers.erase(workers.begin() + i);
                }
                else if(choice2 == 6){
                    goto edit;
                }
            }
        }
    }
    else if(choice == 2){
        cout << "We have: " << buildings.size() << " buildings" << endl;
        if(buildings.size() < 1){
            cout << "You have to create building first" << endl;
            goto edit;
        }

        cout << "Enter adress of building: ";
        string adress;
        cin >> adress;
        for(int i = 0; i < buildings.size(); i++){
            if(buildings[i].getAdress() == adress){
                cout << "1. Edit adress" << endl;
                cout << "2. Edit volume" << endl;
                cout << "3. Edit floors" << endl;
                cout << "4. Exit" << endl;
                int choice2;
                cin >> choice2;
                if(choice2 == 1){
                    cout << "Enter new adress: ";
                    string adress;
                    cin >> adress;
                    buildings[i].setAdress(adress);
                }
                else if(choice2 == 2){
                    cout << "Enter new volume: ";
                    int volume;
                    cin >> volume;
                    buildings[i].setVolume(volume);
                }
                else if(choice2 == 3){
                    cout << "Enter new floors: ";
                    int floors;
                    cin >> floors;
                    buildings[i].setFloors(floors);
                }
                else if(choice2 == 4){
                    goto edit;
                }
            }
        }
    }
    else if(choice == 3){
        cout << "We have: " << casas.size() << " casas" << endl;
        if(casas.size() < 1){
            cout << "You have to create casa first" << endl;
            goto edit;
        }

        cout << "Enter uid of casa: ";
        int uid;
        cin >> uid;
        for(int i = 0; i < casas.size(); i++) {
            if (casas[i].getUid() == uid) {
                cout << "1. Edit uid" << endl;
                cout << "2. Set money" << endl;
                cout << "3. Add money" << endl;
                cout << "5. Exit" << endl;

                int choice2;
                cin >> choice2;
                if(choice2 == 1){
                    cout << "Enter new uid: ";
                    int uid;
                    cin >> uid;
                    casas[i].setUid(uid);
                }
                else if(choice2 == 2){
                    cout << "Enter new money: ";
                    int money;
                    cin >> money;
                    casas[i].setMoney(money);
                }
                else if(choice2 == 3){
                    cout << "Enter money to add: ";
                    int money;
                    cin >> money;
                    casas[i].addMoney(money);
                }
                else if(choice2 == 4){
                    goto edit;
                }

            }
        }


    }
    else if(choice == 4){
        cout << "We have: " << storages.size() << " storages" << endl;
        if(storages.size() < 1){
            cout << "You have to create storage first" << endl;
            goto edit;
        }

        cout << "Enter storage size: ";
        int si;
        cin >> si;
        for(int i = 0; i < storages.size(); i++) {
            if (storages[i].getVolume() == si) {
                cout << "1. Set Volume" << endl;
                cout << "2. Set Used Volume" << endl;
                cout << "3. Exit" << endl;

                int choice2;
                cin >> choice2;
                if(choice2 == 1){
                    cout << "Enter new volume: ";
                    int volume;
                    cin >> volume;
                    storages[i].setVolume(volume);
                }
                else if(choice2 == 2){
                    cout << "Enter new used volume: ";
                    int usedVolume;
                    cin >> usedVolume;
                    storages[i].setUsedVolume(usedVolume);
                }
                else if(choice2 == 3){
                    goto edit;
                }

            }
        }

    }
    else if(choice == 5){
        goto menu;
    }


create:

    cout << "1. Create Worker" << endl;
    cout << "2. Create Building" << endl;
    cout << "3. Create Casa" << endl;
    cout << "4. Create Storage" << endl;
    cout << "5. Show me what do i have" << endl;
    cout << "6. Exit" << endl;
    cin >> choice;
    if(choice == 1) {
        string name, phoneNum;
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter phone number: ";
        cin >> phoneNum;
        cout << "Select type: \n";

        cout << "1. Create Owner" << endl;
        cout << "2. Create Seller" << endl;
        cout << "3. Create Security" << endl;
        cout << "4. Create Cleaner" << endl;
        cout << "5. Create Admin" << endl;
        int choice2;
        cin >> choice2;
        switch (choice2) {
            case 1: {
                Pharmacy::Owner owner(name, phoneNum);
                workers.push_back(owner);
                break;
            }
            case 2: {
                Pharmacy::Seller seller(name, phoneNum);
                workers.push_back(seller);
                break;
            }
            case 3: {
                Pharmacy::Security security(name, phoneNum);
                workers.push_back(security);
                break;
            }
            case 4: {
                Pharmacy::Cleaner cleaner(name, phoneNum);
                workers.push_back(cleaner);
                break;
            }
            case 5: {
                Pharmacy::Admin admin(name, phoneNum);
                workers.push_back(admin);
                break;
            }
            default:
                break;
        }
    } else if(choice == 2){
            string adress;
            int volume, floors;
            cout << "Enter adress: ";
            cin >> adress;
            cout << "Enter volume: ";
            cin >> volume;
            cout << "Enter floors: ";
            cin >> floors;
            Pharmacy::Building building(adress, volume, floors);
            buildings.push_back(building);
    } else if(choice == 3){
            int id;
            cout << "Enter id: ";
            cin >> id;
            Pharmacy::Casa casa(id);
            casas.push_back(casa);
    } else if(choice == 4){
            long long Volume;
            cout << "Enter volume: ";
            cin >> Volume;
            Pharmacy::Storage storage(Volume);
            storages.push_back(storage);
    } else if(choice == 5){
            cout << "Workers: " << endl;
            for(int i = 0; i < workers.size(); i++){
                cout << "Name: " << workers[i].getName() << endl;
                cout << "Phone number: " << workers[i].getPhoneNum() << endl;
                cout << "Position: " << workers[i].getPosition() << endl;
                cout << "Is working: " << workers[i].isWorking() << endl;
                cout << "Is trainie: " << workers[i].isTrainie() << endl;
                cout << "-----------------------" << endl;
            }
            cout << "Buildings: " << endl;
            for(int i = 0; i < buildings.size(); i++){
                cout << "Adress: " << buildings[i].getAdress() << endl;
                cout << "Volume: " << buildings[i].getVolume() << endl;
                cout << "Floors: " << buildings[i].getFloors() << endl;
                cout << "-----------------------" << endl;
            }
            cout << "Casas: " << endl;
            for(int i = 0; i < casas.size(); i++){
                cout << "Id: " << casas[i].getUid() << endl;
                cout << "Money: " << casas[i].getMoney() << endl;
                cout << "-----------------------" << endl;
            }
            cout << "Storages: " << endl;
            for(int i = 0; i < storages.size(); i++){
                cout << "Volume: " << storages[i].getVolume() << endl;
                cout << "Used volume: " << storages[i].getUsedVolume() << endl;
                cout << "-----------------------" << endl;
            }
    } else if(choice == 6){
        goto menu;
    }

    goto create;

    exit:
    return 0;

}