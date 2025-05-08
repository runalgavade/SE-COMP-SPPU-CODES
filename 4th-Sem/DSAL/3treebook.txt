#include <iostream>
#include <cstring> // For using strcpy
using namespace std;

struct node {
    char label[50]; // Label for the node (book, chapter, section)
    int ch_count;   // Number of chapters or sections
    int sub_count;  // Number of subsections
    struct node *child[10]; // Array of pointers to child nodes
};

class Tree {
public:
    node *root; // Root of the tree

    Tree() {
        root = NULL; // Initialize root to NULL
    }

    void create_tree();  
    void display(node *r1, const string &prefix = "");
};

void Tree::create_tree() {
    int tchapters, i, j;

    root = new node; // Create root node
    cout << "Enter Name of Book: ";
    cin >> root->label;

    cout << "Enter number of Chapters in Book: ";
    cin >> tchapters; 
    root->ch_count = tchapters;

    for (i = 0; i < tchapters; i++) {
        root->child[i] = new node; // Create chapter node
        cout << "Enter Chapter " << i + 1 << " Name: ";
        cin >> root->child[i]->label;   
        
        cout << "Enter number of Sections in Chapter " << root->child[i]->label << ": ";
        cin >> root->child[i]->ch_count;

        for (j = 0; j < root->child[i]->ch_count; j++) {
            root->child[i]->child[j] = new node; // Create section node
            cout << "Enter Section " << j + 1 << " Name: ";
            cin >> root->child[i]->child[j]->label;   
            
            cout << "Enter number of Subsections in " << root->child[i]->child[j]->label << ": ";
            cin >> root->child[i]->child[j]->sub_count;

            // Create subsections
            for (int k = 0; k < root->child[i]->child[j]->sub_count; k++) {
                root->child[i]->child[j]->child[k] = new node; // Create subsection node
                cout << "Enter Subsection " << k + 1 << " Name: ";
                cin >> root->child[i]->child[j]->child[k]->label;
            }
        }
    }
}

void Tree::display(node *r1, const string &prefix) {
    if (r1 != NULL) {
        cout << "\n\nBook Hierarchy Tree\n\n";
        cout << "Book Title: " << r1->label;
        int tchapters = r1->ch_count;
        cout << "\nChapters:";
        
        for (int i = 0; i < tchapters; i++) {
            cout << "\n" << prefix << (i + 1) << ". " << r1->child[i]->label;   
            cout << "\nSections:";
            
            for (int j = 0; j < r1->child[i]->ch_count; j++) {
                cout << "\n  " << prefix << (i + 1) << "." << (j + 1) << " " << r1->child[i]->child[j]->label;
                cout << "\n  Subsections:";
                
                for (int k = 0; k < r1->child[i]->child[j]->sub_count; k++) {
                    cout << "\n    " << prefix << (i + 1) << "." << (j + 1) << "." << (k + 1) << " " << r1->child[i]->child[j]->child[k]->label;
                }
            }
        }
    }
}

int main() {
    int ch;
    Tree t1;
    while (true) {
        cout << "\nPlease Enter Your Choice:\n1. New Entry\t2. Display\n3. Quit ";
        cin >> ch;
        switch (ch) {
            case 1:
                t1.create_tree();
                break;
            case 2:
                t1.display(t1.root);
                break;
            case 3:
                exit(0);
            default:
                cout << "Invalid Choice" << endl;
        }
    }
}