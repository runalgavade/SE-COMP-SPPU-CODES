#include <iostream>
using namespace std;

// Function to perform partitioning
int partition(float arr[], int p, int r) {
    float x = arr[r]; // Pivot
    int i = p - 1; 

    for (int j = p; j < r; j++) {
        if (arr[j] <= x) {
            i++;
            // Manually swap arr[i] and arr[j]
            float temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    // Manually swap arr[i + 1] and arr[r]
    float temp = arr[i + 1];
    arr[i + 1] = arr[r];
    arr[r] = temp;

    return i + 1;
}

// Function to perform Quick Sort
void quicksort(float arr[], int p, int r) {
    if (p < r) {
        int q = partition(arr, p, r);
        quicksort(arr, p, q - 1);
        quicksort(arr, q + 1, r);
    }
}

// Function to display top 5 scores 
void display_top_five(float arr[], int size) {
    if (size < 5) {
        cout << "Not enough scores to display top 5." << endl;
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    } else {
        cout << "Top Five Percentages are (in descending order): " << endl;
        for (int i = size - 1; i >= size - 5; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    const int SIZE = 8; // Define the size of the array
    float arr[SIZE]; // Change to float for percentages
    
    cout << "Enter first year percentage of students: \n";
    for (int i = 0; i < SIZE; i++) {
        cin >> arr[i];
    }

    cout << "\nFirst year percentage of students is: \n";
    for (int i = 0; i < SIZE; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    quicksort(arr, 0, SIZE - 1); // Sort the array

    cout << "Sorted array elements are:\n";
    for (int i = 0; i < SIZE; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    display_top_five(arr, SIZE); // Display the top five scores

    return 0;
}
