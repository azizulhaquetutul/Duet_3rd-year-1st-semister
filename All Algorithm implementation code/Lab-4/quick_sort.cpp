
#include <iostream>
#include <fstream>
#include <vector>
#include <random>

using namespace std;

// Partition function to rearrange the array based on the pivot
int partitionArray(vector<int> &arr, int low, int high) {
    int pivot = arr[low];  // Choosing the first element as the pivot
    int left = low + 1;
    int right = high;

    while (left <= right) {
        // Move left pointer until an element larger than the pivot is found
        while (left <= right && arr[left] <= pivot)
            left++;

        // Move right pointer until an element smaller than the pivot is found
        while (left <= right && arr[right] > pivot)
            right--;

        // Swap elements if left is still less than right
        if (left < right) {
            swap(arr[left], arr[right]);
            left++;
            right--;
        }
    }

    // Place pivot element in the correct position
    swap(arr[low], arr[right]);
    return right;
}

// Quick sort function (recursive)
void quickSort(vector<int> &arr, int low, int high) {
    if (low < high) {
        int pivotIndex = partitionArray(arr, low, high);

        // Recursively sort elements before and after the pivot
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

int main() {
    string fileName = "QuickSortNumbers.txt";
    random_device rd;
    mt19937 generator(rd());
    uniform_int_distribution<int> distribution(1, 5000000);

    // Step 1: Generate random numbers and save them to a file
    ofstream outputFile(fileName);
    if (!outputFile) {
        cerr << "Error: Could not create file!" << endl;
        return 1;
    }

    cout << "Saving random numbers to " << fileName << endl;
    for (int i = 0; i < 5000000; i++) {
        outputFile << distribution(generator) << endl;
    }
    outputFile.close();

    // Step 2: Read the numbers from the file into a vector
    ifstream inputFile(fileName);
    if (!inputFile) {
        cerr << "Error: Could not open file!" << endl;
        return 1;
    }

    vector<int> numbers;
    int value;
    while (inputFile >> value) {
        numbers.push_back(value);
    }
    inputFile.close();

    // Step 3: Sort the numbers using quicksort
    cout << "Sorting the numbers using quicksort..." << endl;
    quickSort(numbers, 0, numbers.size() - 1);

    cout << "Sorting completed!" << endl;

    return 0;
}

