#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct rec {
    string name;
    string BirthDt;
    string phone;
} node;

vector<node> rec;

bool compare(const node &r1, const node &r2) {
    return r1.name < r2.name;
}

void Create() {
    int n;
    cout << "\nHow many elements do you want to insert? ";
    cin >> n;
    cin.ignore(); // To clear the input buffer
    
    cout << "\nEnter the elements in the database - " << endl;
    for (int i = 0; i < n; i++) {
        node temp;
        cout << "Name: ";
        getline(cin, temp.name); // Use getline for safer string input
        cout << "Birth Date: ";
        getline(cin, temp.BirthDt);
        cout << "Phone: ";
        getline(cin, temp.phone);
        rec.push_back(temp);
    }
}

void Display() {
    cout << "\nThe contents of the database are - " << endl;
    cout << "Name       Birth Date      Phone" << endl;
    for (const auto &item : rec) {
        cout << item.name << "       " << item.BirthDt << "       " << item.phone << endl;
    }
}

void Searching() {
    string key;
    cout << "\nEnter the name which you want to search: ";
    cin.ignore(); // To clear the input buffer
    getline(cin, key);
    
    bool found = false;
    for (const auto &item : rec) {
        if (item.name == key) {
            found = true;
            break;
        }
    }
    
    if (found)
        cout << "The desired element is present in the database" << endl;
    else
        cout << "The desired element is not present in the database" << endl;
}

void Sorting() {
    sort(rec.begin(), rec.end(), compare);
    cout << "\n\nRecord is sorted!" << endl;
}

int main() {
    char ans = 'y';
    int choice;
    
    cout << "Program for Searching & Sorting: " << endl;

    do {
        cout << "\nMain Menu - " << endl;
        cout << "1. Create a database\n2. Display a database\n3. Search for a particular element\n4. Sort the database (based on name)" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // To clear the input buffer

        switch (choice) {
            case 1:
                Create();
                break;
            case 2:
                Display();
                break;
            case 3:
                Searching();
                break;
            case 4:
                Sorting();
                break;
            default:
                cout << "\nInvalid choice!" << endl;
                break;
        }

        cout << "\nDo you want to go back to Main Menu? (y/n) ";
        cin >> ans;
    } while (ans == 'y');
    
    return 0;
}
