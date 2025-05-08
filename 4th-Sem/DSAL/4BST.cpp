#include <iostream>
using namespace std;

// Structure to create a node
struct Node {
    int data;
    Node* right;
    Node* left;
};

// Function to create a node
Node* create(int data) {
    Node* temp = new Node();
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// Function to insert a node
void insert(Node*& root, int data) {
    if (root == NULL) {
        root = create(data); // Create root
    } else if (root->data > data) {
        insert(root->left, data); // Go to left side
    } else {
        insert(root->right, data); // Go to right side
    }
}

// Preorder
void displayPre(Node* root) {
    if (root != NULL) {
        cout << root->data << " "; // PARENT
        displayPre(root->left);     // LEFT
        displayPre(root->right);    // RIGHT
    }
}

// Inorder
void displayIn(Node* root) {
    if (root != NULL) {
        displayIn(root->left);      // LEFT
        cout << root->data << " ";  // PARENT
        displayIn(root->right);     // RIGHT
    }
}

// Postorder
void displayPost(Node* root) {
    if (root != NULL) {
        displayPost(root->left);     // LEFT
        displayPost(root->right);    // RIGHT
        cout << root->data << " ";   // PARENT
    }
}

// Function to calculate Height
int height(Node* root) {
    if (root == NULL) {
        return 0;
    } else {
        int l_h = height(root->left);
        int r_h = height(root->right);
        return max(l_h, r_h) + 1; // Return the height
    }
}

// Function to search for a value
bool search(Node* root, int value) {
    if (root != NULL) {
        if (root->data > value) {
            return search(root->left, value);
        } else if (root->data < value) {
            return search(root->right, value);
        } else {
            return true; // Element found
        }
    }
    return false; // Element not found
}

// Function to find the smallest element (extreme left)
void smallest(Node* root) {
    if (root == NULL) {
        cout << "Tree is empty." << endl;
        return;
    }
    while (root->left != NULL) {
        root = root->left;
    }
    cout << "Smallest :: " << root->data << endl;
}

// Function to find the largest element (extreme right)
void largest(Node* root) {
    if (root == NULL) {
        cout << "Tree is empty." << endl;
        return;
    }
    while (root->right != NULL) {
        root = root->right;
    }
    cout << "Largest :: " << root->data << endl;
}

// Function to mirror the tree
void mirror(Node* root) {
    if (root == NULL) {
        return;
    }
    mirror(root->left);
    mirror(root->right);
    swap(root->left, root->right);
}

// Function to find the minimum data value in the tree
int findMin(Node* root) {
    if (root == NULL) {
        return -1; // or some error value
    }
    while (root->left != NULL) {
        root = root->left;
    }
    return root->data;
}

int main() {
    bool loop = true;
    Node* root = NULL;
    int ch, n, num;

    while (loop) {
        // Menu
        cout << "\n-----MENU-----" << endl
             << "1. Create BST" << endl
             << "2. Preorder" << endl
             << "3. Inorder" << endl
             << "4. Postorder" << endl
             << "5. Height" << endl
             << "6. Search" << endl
             << "7. Smallest" << endl
             << "8. Largest" << endl
             << "9. Mirror" << endl
             << "10. Minimum Value" << endl
             << "11. Exit" << endl
             << "ENTER :: ";
        cin >> ch;

        switch (ch) {
            case 1: {
                cout << "\n Enter the number of elements :: ";
                cin >> n;

                cout << "Enter the numbers :: ";
                for (int i = 0; i < n; i++) {
                    cin >> num;
                    insert(root, num);
                }
                break;
            }
            case 2: {
                cout << "\nPRE ORDER : ";
                displayPre(root);
                break;
            }
            case 3: {
                cout << "\nIN ORDER : ";
                displayIn(root);
                break;
            }
            case 4: {
                cout << "\nPOST ORDER : ";
                displayPost(root);
                break;
            }
            case 5: {
                int h = height(root);
                cout << "\nHeight of BST :: " << h;
                break;
            }
            case 6: {
                int value;
                cout << "Enter the element to search :: ";
                cin >> value;
                if (search(root, value)) {
                    cout << "\nelement FOUND";
                } else {
                    cout << "\nelement NOT found";
                }
                break;
            }
            case 7: {
                smallest(root);
                break;
            }
            case 8: {
                largest(root);
                break;
            }
            case 9: {
                cout << "\nBEFORE MIRROR"
                     << "\nInorder :: ";
                displayIn(root);
                mirror(root);
                cout << "\nAFTER MIRROR"
                     << "\nInorder :: ";
                displayIn(root);
                break;
            }
            case 10: {
                int minValue = findMin(root);
                if (minValue != -1) {
                    cout << "Minimum Value :: " << minValue << endl;
                } else {
                    cout << "Tree is empty." << endl;
                }
                break;
            }
            case 11: {
                loop = false;
                break;
            }
            default: {
                cout << "Invalid option. Please try again." << endl;
                break;
            }
        }
    }
    return 0;
}