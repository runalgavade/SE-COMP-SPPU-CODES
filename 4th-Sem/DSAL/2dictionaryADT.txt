#include<iostream>
using namespace std;

// Node structure for linked list
struct Node {
    int key;
    int value;
    Node* next;
};

// Hash Table class
class HashTable {
    Node* table[10]; // Array of pointers to Node (Linked Lists)

public:
    HashTable();
    void insert(int key, int value);
    void display();
    Node* find(int key);
    void Delete(int key);
};

// Constructor to initialize all heads to NULL
HashTable::HashTable() {
    for (int i = 0; i < 10; i++) {
        table[i] = NULL;
    }
}

// Insert function
void HashTable::insert(int key, int value) {
    int index = key % 10; // hash function
    Node* newNode = new Node{key, value, NULL};

    if (table[index] == NULL) {
        table[index] = newNode;
    } else {
        newNode->next = table[index];
        table[index] = newNode;
    }
    cout << "\n\tKey " << key << " inserted at index " << index;
}

// Display function
void HashTable::display() {
    cout << "\n\tHash Table:";
    for (int i = 0; i < 10; i++) {
        cout << "\n\t[" << i << "]";
        Node* temp = table[i];
        while (temp != NULL) {
            cout << " -> (Key: " << temp->key << ", Value: " << temp->value << ")";
            temp = temp->next;
        }
    }
}

// Find function
Node* HashTable::find(int key) {
    int index = key % 10;
    Node* temp = table[index];
    while (temp != NULL) {
        if (temp->key == key)
            return temp;
        temp = temp->next;
    }
    return NULL; // Not found
}

// Delete function
void HashTable::Delete(int key) {
    int index = key % 10;
    Node* temp = table[index];
    Node* prev = NULL;

    while (temp != NULL) {
        if (temp->key == key) {
            if (prev == NULL) {
                table[index] = temp->next; // first node
            } else {
                prev->next = temp->next;
            }
            delete temp;
            cout << "\n\tKey " << key << " Deleted";
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    cout << "\n\tKey Not Found";
}

// Main function
int main() {
    HashTable ht;
    int ch, key, value;
    char ans;

    do {
        cout << "\n\n\t***** Dictionary (ADT) with Chaining *****";
        cout << "\n\t1. Insert\n\t2. Display\n\t3. Find\n\t4. Delete\n\t5. Exit";
        cout << "\n\t..... Enter Your Choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                cout << "\n\tEnter Key: ";
                cin >> key;
                cout << "\n\tEnter Value: ";
                cin >> value;
                ht.insert(key, value);
                break;
            case 2:
                ht.display();
                break;
            case 3:
                cout << "\n\tEnter Key to Find: ";
                cin >> key;
                {
                    Node* found = ht.find(key);
                    if (found != NULL)
                        cout << "\n\tKey " << key << " Found with Value: " << found->value;
                    else
                        cout << "\n\tKey Not Found";
                }
                break;
            case 4:
                cout << "\n\tEnter Key to Delete: ";
                cin >> key;
                ht.Delete(key);
                break;
            case 5:
                cout << "\n\tExiting...";
                break;
            default:
                cout << "\n\tInvalid Choice!";
        }

        if (ch != 5) {
            cout << "\n\t..... Do You Want to Continue (y/n)? ";
            cin >> ans;
        } else {
            break;
        }

    } while (ans == 'y' || ans == 'Y');

    return 0;
}

