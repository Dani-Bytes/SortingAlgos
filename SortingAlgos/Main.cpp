#include "BinaryTree.h"

void displaySystemInfo();
void bubbleSort(vector<int>& arr);
void selectionSort(vector<int>& arr);
void binaryTreeSort(vector<int>& arr);
void printTableHeader();
void measureSortTime(void (*sortFunc)(vector<int>&), vector<int>& arr, const string& algoName);


// Main function to run tests and display results
int main() {
    srand(time(0));

    displaySystemInfo();
    // Ask the user for the array size
    int arraySize;
    cout << "Enter the array size: ";
    cin >> arraySize;

    // Validate the input (ensure it's a positive integer)
    if (arraySize <= 0) {
        cout << "Invalid input. Array size must be a positive integer.\n";
        return 1;  // Exit the program if the input is invalid
    }

    vector<int> arr(arraySize);
    for (int i = 0; i < arraySize; i++) {
        arr[i] = rand() % 10000;  // Random numbers between 0 and 9999
    }

    // Print the table header
    printTableHeader();

    // Bubble Sort Time
    vector<int> arrBubble = arr;
    auto start = high_resolution_clock::now();
    bubbleSort(arrBubble);
    auto stop = high_resolution_clock::now();
    auto durationBubble = duration_cast<nanoseconds>(stop - start);

    // Selection Sort Time
    vector<int> arrSelection = arr;
    start = high_resolution_clock::now();
    selectionSort(arrSelection);
    stop = high_resolution_clock::now();
    auto durationSelection = duration_cast<nanoseconds>(stop - start);

    // Binary Tree Sort Time
    vector<int> arrTree = arr;
    start = high_resolution_clock::now();
    binaryTreeSort(arrTree);
    stop = high_resolution_clock::now();
    auto durationTree = duration_cast<nanoseconds>(stop - start);

    // Output the results in table format
    cout << arraySize << "        | "
        << durationBubble.count() << " ns        | "
        << durationSelection.count() << " ns         | "
        << durationTree.count() << " ns\n";

    return 0;
}


// Function to display system specifications
void displaySystemInfo() {
    cout << "System Specifications:" << endl;
    cout << "-----------------------" << endl;
    cout << "Processor: Intel Core i5 (10th Gen)" << endl;
    cout << "Cores: 4 cores" << endl;
    cout << "Logical Processors: 8" << endl;
    cout << "RAM: 8GB" << endl;
    cout << "Storage: 256GB SSD" << endl;
    cout << "Operating System: Windows 11 Home" << endl;
    cout << "Laptop Model: HP" << endl;
    cout << "-----------------------" << endl;
    cout << endl;
}

// Bubble Sort Algorithm
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Selection Sort Algorithm
void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

// Binary Tree Sort Algorithm
void binaryTreeSort(vector<int>& arr) {
    BinaryTree tree;
    for (int num : arr) {
        tree.insert(num);
    }

    // In-order traversal to retrieve sorted array
    arr.clear();
    tree.inorderTraversal(arr);
}

// Function to print the table header
void printTableHeader() {
    cout << "Array Size | Bubble Sort (ns) | Selection Sort (ns) | Binary Tree Sort (ns)\n";
    cout << "-------------------------------------------------------------\n";
}

// Function to measure sorting time and print results
void measureSortTime(void (*sortFunc)(vector<int>&), vector<int>& arr, const string& algoName) {
    auto start = high_resolution_clock::now();
    sortFunc(arr);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);
    cout << algoName << " took " << duration.count() << " nanoseconds.\n";
}