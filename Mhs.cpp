#include <iostream>
using namespace std;

struct student {
    string nim;
    string name;
    float presentaseKehadiran;
    student* next;
};

student* createStudent(string nim, string name, float presentaseKehadiran) {
    student* newstudent = new student;
    newstudent->nim = nim;
    newstudent->name = name;
    newstudent->presentaseKehadiran = presentaseKehadiran;
    newstudent->next = nullptr;
    return newstudent;
}

void insertFirst(student* &first, student* newstudent) {
    newstudent->next = first;
    first = newstudent;
}

void insertLast(student* &first, student* newstudent) {
    if (first == nullptr) {
        first = newstudent;
    } else {
        student* current = first;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newstudent;
    }
}

void deleteFirst(student* &first) {
    if (first == nullptr) { 
        cout << "List is empty" << endl; 
        return;
    }  
    student* current = first;
    first = current->next;
    delete current;
}

void deleteLast(student* &first) {
    if (first == nullptr){
        cout << "List is empty" << endl;
        return;
    }
    if (first->next == nullptr) {
        delete first;
    }
    student* current = first;
    while (current->next->next != nullptr) {
        current = current-> next;
    }
    delete current->next;
    current->next = nullptr;
}

void printList(student* &first) {
    if (first == nullptr) {
        cout << "List is empty." << endl;
        return;
    }

    student* current = first;
    while (current != nullptr) {
        cout << "NIM      : "           << current->nim << endl;
        cout << "Name     : "            << current->name << endl;
        cout << "presentaseKehadiran : " << current->presentaseKehadiran << endl;
        current = current->next;
    }
}

void menu(student* &first) {
    string nim, name; 
    float presentaseKehadiran;
    while (true) {
        system("cls");
        printList(first);
        cout << "Menu:" << endl;
        cout << "1. Insert First" << endl;
        cout << "2. Insert Last" << endl;
        cout << "3. Delete First" << endl;
        cout << "4. Delete Last" << endl;
        cout << "5. Exit" << endl;
        cout << "Choose an option: ";
        int choice;
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                cout << "Enter Name: ";
                getline(cin, name);
                cout << "Enter NIM: ";
                cin >> nim;
                cout << "Enter presentaseKehadiran: ";
                cin >> presentaseKehadiran;
                insertFirst(first, createStudent(nim, name, presentaseKehadiran));
                break;
            case 2:
                cout << "Enter Name: ";
                getline(cin, name);
                cout << "Enter NIM: ";
                cin >> nim;
                cout << "Enter presentaseKehadiran: ";
                cin >> presentaseKehadiran;
                insertLast(first, createStudent(nim, name, presentaseKehadiran));
                break;
            case 3:
                deleteFirst(first);
                break;
            case 4:
                deleteLast(first);
                break;
            case 5:
                return;
            default:
                cout << "Invalid option. Please try again." << endl;
        }
    }
}

int main() {
    student* first = nullptr;

    insertLast(first, createStudent("103032500005", "Fadhil Asyam Damanik", 1.0));
    insertLast(first, createStudent("103032500041", "Rahsya Iman Dehavilland", 1.0));
    insertLast(first, createStudent("103032500146", "Mahesa Putra Mulyawan", 1.0));
    insertLast(first, createStudent("103032500149", "Gyio Rangga Satria Putra", 1.0));
    insertLast(first, createStudent("103032500150", "Naufal Nafiz Faturrahman", 1.0));
    insertLast(first, createStudent("103032500153", "Fazli Baktiadi", 1.0));
    insertLast(first, createStudent("103032500159", "Matthew Glen Abram Pakpahan", 1.0));
    insertLast(first, createStudent("103032500176", "Vendra Fausta Andrean", 1.0));
    insertLast(first, createStudent("103032500180", "Dzaky Allam Shidiq", 1.0));
    insertLast(first, createStudent("103032500191", "Nayla Novtiera Anjani", 1.0));
    insertLast(first, createStudent("103032540001", "Fathin Arib Nurhumam", 1.0));
    insertLast(first, createStudent("103032540002", "Ida Bagus Harell", 1.0));
    insertLast(first, createStudent("103032540003", "Nigel William Pieters", 1.0));
    insertLast(first, createStudent("103032540004", "Aqila Fathatulayya", 1.0));
    insertLast(first, createStudent("103032540005", "Badriah Nuraini Rahayu", 1.0));

    menu(first);

    return 0;
}