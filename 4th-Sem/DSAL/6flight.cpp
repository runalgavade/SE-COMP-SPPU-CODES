#include <iostream>
#include <queue>
#define n 10 // Maximum size for adjacency matrix

using namespace std;

int adj_m[n][n]; // Adjacency matrix declaration

// Function to perform depth-first traversal
void traverse(int u, int x, bool visited[]) {
    visited[u] = true; // Mark vertex as visited
    for (int v = 0; v < x; v++) {
        if (adj_m[u][v] != 0) { // Check if there is a connection
            // Check if visited; if not visited, traverse again
            if (!visited[v]) {
                traverse(v, x, visited);
            }
        }
    }
}

// Function to check if the graph is connected
bool isConnected(int x) {
    bool *vis = new bool[n]; // Dynamic allocation for visited array
    for (int u = 0; u < x; u++) {
        // Initialize as no node is visited
        for (int i = 0; i < x; i++)
            vis[i] = false;

        traverse(u, x, vis); // Call the function to update the visited array

        // Check if all nodes are visited
        for (int i = 0; i < x; i++) {
            if (!vis[i]) {
                // If there is a node not visited, the graph is not connected
                delete[] vis; // Free allocated memory
                return false;
            }
        }
    }
    delete[] vis; // Free allocated memory
    return true;
}

int main() {
    int x; // Number of cities
    cout << "Enter number of cities: ";
    cin >> x;

    // Input cities
    char arr[n][20]; // Array to store city names
    for (int i = 0; i < x; i++) {
        cout << "Enter " << i + 1 << " city name: ";
        cin >> arr[i];
    }

    // Initialize adjacency matrix to 0
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            adj_m[i][j] = 0;
        }
    }

    // Input connections and fuel costs
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < x; j++) {
            if (i != j) { // No self-loops
                cout << "\nIs city " << arr[i] << " connected to city " << arr[j] << "? (y/n): ";
                char ch;
                cin >> ch;
                if (ch == 'y' || ch == 'Y') {
                    int fuel;
                    cout << "Enter fuel required to go from " << arr[i] << " to " << arr[j] << ": ";
                    cin >> fuel;
                    adj_m[i][j] = fuel; // Set the fuel cost in the adjacency matrix
                }
            }
        }
        cout << "\n-------------------------------\n";
    }

    // Printing adjacency matrix
    cout << "ADJACENCY MATRIX:\n";
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < x; j++) {
            cout << adj_m[i][j] << "\t";
        }
        cout << "\n";
    }
    cout << "\n-------------------------------\n";

    // Check if the graph is connected
    if (isConnected(x))
        cout << "The Graph is connected." << endl;
    else
        cout << "The Graph is not connected." << endl;

    return 0;
}
