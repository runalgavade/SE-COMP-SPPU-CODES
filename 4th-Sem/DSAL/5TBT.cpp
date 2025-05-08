#include <iostream>
using namespace std;

struct Node {
    int value;
    Node *left, *right;
    bool rightThread; // Indicates if the right pointer is a thread
};

// Function to create a new node
Node *newNode(int value) {
    Node *temp = new Node;
    temp->left = temp->right = NULL;
    temp->value = value;
    temp->rightThread = false; // Initialize as not a thread
    return temp;
}

// Function to convert a binary tree to a threaded binary tree
Node *convert(Node *root) {
    if (root == NULL) {
        return NULL;
    }

    // Convert left subtree
    if (root->left != NULL) {
        Node *leftSubtree = convert(root->left);
        // Find the rightmost node of the left subtree
        while (leftSubtree->right != NULL) {
            leftSubtree = leftSubtree->right;
        }
        // Make the rightmost node's right pointer point to the root
        leftSubtree->right = root;
        leftSubtree->rightThread = true; // Mark as a thread
    }

    // Convert right subtree
    if (root->right != NULL) {
        convert(root->right);
    }

    return root;
}

// Function to find the leftmost node
Node *leftmost(Node *root) {
    while (root != NULL && root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Function for in-order traversal of the threaded binary tree
void inorder(Node *root) {
    if (root == NULL) {
        return;
    }
    Node *current = leftmost(root);
    while (current != NULL) {
        cout << current->value << " ";
        // If the current node has a thread, follow the thread
        if (current->rightThread) {
            current = current->right;
        } else {
            current = leftmost(current->right);
        }
    }
}

int main() {
    int rt, l1, l2, l3, r1, r2, r3;
    cout << "\nEnter First Node: ";
    cin >> rt;
    Node* root = newNode(rt);
    
    cout << "\nEnter Left Child of " << rt << ": ";
    cin >> l1;
    root->left = newNode(l1);
    
    cout << "\nEnter Right Child of " << rt << ": ";
    cin >> r1;
    root->right = newNode(r1);
    
    cout << "\nEnter Left Child of " << l1 << ": ";
    cin >> l2;
    root->left->left = newNode(l2);
    
    cout << "\nEnter Right Child of " << r1 << ": ";
    cin >> r2;
    root->left->right = newNode(r2);
    
    cout << "\nEnter Left Child of " << l2 << ": ";
    cin >> l3;
    root->left->left->left = newNode(l3);
    
    cout << "\nEnter Right Child of " << r2 << ": ";
    cin >> r3;
    root->right->right = newNode(r3);
    
    // Convert the binary tree to a threaded binary tree
    convert(root);
    
    cout << "InOrder Traversal of Created Threaded Binary Tree is:\n";
    inorder(root);
    cout << endl;
    
    return 0;
}