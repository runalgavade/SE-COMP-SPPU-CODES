#include <iostream>
#include <string>

using namespace std;

class bstnode {
public:
    string keyword;
    string meaning;
    bstnode *left, *right;

    bstnode() : left(nullptr), right(nullptr) {}
    bstnode(string k, string m) : keyword(k), meaning(m), left(nullptr), right(nullptr) {}
};

class dictionary {
public:
    bstnode *root;

    dictionary() : root(nullptr) {}

    void accept();
    void insert(string key, string mean);
    void inorder(bstnode *root);
    void descending(bstnode *root);
    void search(string key);
    void update(string oldkey, string newmean);
    bstnode* deleteKey(bstnode *root, string key);
    bstnode* minValueNode(bstnode* node);
    int maxComparisons(bstnode *node, int depth);
};

void dictionary::accept() {
    string key, mean;
    cout << "Enter keyword: ";
    cin >> key;
    cin.ignore();  // This is important to ignore the newline character left by cin >> key
    cout << "Enter meaning: ";
    getline(cin, mean);  // Now this will allow multi-word input for meaning
    insert(key, mean);
}

void dictionary::insert(string key, string mean) {
    if (!root) {
        root = new bstnode(key, mean);
        cout << "Keyword '" << key << "' inserted as root." << endl;
        return;
    }

    bstnode *current = root;
    while (true) {
        if (key < current->keyword) {
            if (!current->left) {
                current->left = new bstnode(key, mean);
                cout << "Keyword '" << key << "' inserted to the left of '" << current->keyword << "'." << endl;
                break;
            }
            current = current->left;
        } else if (key > current->keyword) {
            if (!current->right) {
                current->right = new bstnode(key, mean);
                cout << "Keyword '" << key << "' inserted to the right of '" << current->keyword << "'." << endl;
                break;
            }
            current = current->right;
        } else {
            cout << "Keyword '" << key << "' already exists." << endl;
            break;
        }
    }
}

void dictionary::inorder(bstnode *root) {
    if (root) {
        inorder(root->left);
        cout << root->keyword << " : " << root->meaning << endl;
        inorder(root->right);
    }
}

void dictionary::descending(bstnode *root) {
    if (root) {
        descending(root->right);
        cout << root->keyword << " : " << root->meaning << endl;
        descending(root->left);
    }
}

void dictionary::search(string key) {
    bstnode *current = root;
    int comparisons = 0;
    while (current) {
        comparisons++;
        if (key < current->keyword) {
            current = current->left;
        } else if (key > current->keyword) {
            current = current->right;
        } else {
            cout << "Keyword found: " << current->meaning << " (Comparisons: " << comparisons << ")" << endl;
            return;
        }
    }
    cout << "Keyword not found (Comparisons: " << comparisons << ")." << endl;
}

void dictionary::update(string oldkey, string newmean) {
    bstnode *current = root;
    while (current) {
        if (oldkey < current->keyword) {
            current = current->left;
        } else if (oldkey > current->keyword) {
            current = current->right;
        } else {
            current->meaning = newmean;
            cout << "Update successful for keyword '" << oldkey << "'." << endl;
            return;
        }
    }
    cout << "Keyword '" << oldkey << "' not found for update." << endl;
}

bstnode* dictionary::minValueNode(bstnode* node) {
    bstnode* current = node;
    while (current && current->left != nullptr)
        current = current->left;
    return current;
}

bstnode* dictionary::deleteKey(bstnode *root, string key) {
    if (!root) return root;

    if (key < root->keyword)
        root->left = deleteKey(root->left, key);
    else if (key > root->keyword)
        root->right = deleteKey(root->right, key);
    else {
        if (!root->left) {
            bstnode *temp = root->right;
            delete root;
            return temp;
        } else if (!root->right) {
            bstnode *temp = root->left;
            delete root;
            return temp;
        }

        bstnode* temp = minValueNode(root->right);
        root->keyword = temp->keyword;
        root->meaning = temp->meaning;
        root->right = deleteKey(root->right, temp->keyword);
    }
    return root;
}

int dictionary::maxComparisons(bstnode *node, int depth) {
    if (!node) return depth;
    return max(maxComparisons(node->left, depth + 1), maxComparisons(node->right, depth + 1));
}

int main() {
    dictionary dict;
    int choice;
    while (true) {
        cout << "1. Insert\n2. Update\n3. Ascending\n4. Descending\n5. Display\n6. Search\n7. Delete\n8. Max Comparisons\n9. Quit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                dict.accept();
                break;
            case 2: {
                string oldkey, newmean;
                cout << "Enter key whose meaning to update: ";
                cin >> oldkey;
                cout << "Enter new meaning: ";
                cin >> newmean;
                dict.update(oldkey, newmean);
                break;
            }
            case 3:
                dict.inorder(dict.root); // Ascending order
                break;
            case 4:
                dict.descending(dict.root); // Descending order
                break;
            case 5:
                // Avoid calling inorder here if it's already called in case 3
                cout << "Displaying dictionary in ascending order:\n";
                dict.inorder(dict.root);
                break;
            case 6: {
                string key;
                cout << "Enter keyword to search: ";
                cin >> key;
                dict.search(key);
                break;
            }
            case 7: {
                string key;
                cout << "Enter keyword to delete: ";
                cin >> key;
                dict.root = dict.deleteKey(dict.root, key);
                break;
            }
            case 8:
                cout << "Maximum comparisons required: " << dict.maxComparisons(dict.root, 0) << endl;
                break;
            case 9:
                cout << "Thank you for using the dictionary!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
    return 0;
}