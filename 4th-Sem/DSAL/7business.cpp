#include <iostream>
using namespace std;

class Tree {
    int a[20][20], l, u, w, i, j, v, e, visited[20];

public:
    void input();
    void display();
    void minimum();
};

void Tree::input() {
    cout << "Enter the number of branches (vertices): ";
    cin >> v;

    // Initialize the adjacency matrix
    for (i = 0; i < v; i++) {
        visited[i] = 0; // Mark all vertices as unvisited
        for (j = 0; j < v; j++) {
            if (i == j) {
                a[i][j] = 0; // Cost to reach itself is 0
            } else {
                a[i][j] = 999; // Initialize with a large value (infinity)
            }
        }
    }

    cout << "\nEnter the number of connections (edges): ";
    cin >> e;

    for (i = 0; i < e; i++) {
        cout << "Enter the end branches of connections (1 to " << v << "): ";
        cin >> l >> u;
        cout << "Enter the phone company charges for this connection: ";
        cin >> w;
        a[l - 1][u - 1] = a[u - 1][l - 1] = w; // Undirected graph
    }
}

void Tree::display() {
    cout << "\nAdjacency matrix:\n";
    for (i = 0; i < v; i++) {
        for (j = 0; j < v; j++) {
            if (a[i][j] == 999) {
                cout << "INF\t"; // Display "INF" for no connection
            } else {
                cout << a[i][j] << "\t"; // Display the weight
            }
        }
        cout << endl;
    }
}

void Tree::minimum() {
    int p = 0, q = 0, total = 0, min;
    visited[0] = 1; // Start from the first vertex

    for (int count = 0; count < (v - 1); count++) {
        min = 999; // Reset min for each iteration
        for (i = 0; i < v; i++) {
            if (visited[i] == 1) { // If vertex i is visited
                for (j = 0; j < v; j++) {
                    if (visited[j] != 1) { // If vertex j is not visited
                        if (min > a[i][j]) { // Find the minimum edge
                            min = a[i][j];
                            p = i;
                            q = j;
                        }
                    }
                }
            }
        }
        visited[q] = 1; // Mark the new vertex as visited
        total += min; // Add the cost to the total
        cout << "Minimum cost connection is " << (p + 1) << " -> " << (q + 1) << " with charge: " << min << endl;
    }
    cout << "The minimum total cost of connections of all branches is: " << total << endl;
}

int main() {
    int ch;
    Tree t;
    do {
        cout << "==========PRIM'S ALGORITHM=================" << endl;
        cout << "\n1. INPUT\n2. DISPLAY\n3. MINIMUM\n4. EXIT" << endl;
        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                cout << "*******INPUT YOUR VALUES*******" << endl;
                t.input();
                break;

            case 2:
                cout << "*******DISPLAY THE CONTENTS********" << endl;
                t.display();
                break;

            case 3:
                cout << "*********MINIMUM************" << endl;
                t.minimum();
                break;

            case 4:
                cout << "Exiting..." << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (ch != 4);
    return 0;
}