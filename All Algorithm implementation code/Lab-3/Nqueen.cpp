#include <bits/stdc++.h>
using namespace std;

// Function to heapify a subtree rooted with node i, which is an index in arr[]
void heapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

// Main function to perform heap sort
void heapSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {
    srand(time(0));
    int n = 4;
    int sizes[n] = {100, 1000,10000, 100000, 1000000};
    vector<int> arr;

    // Best case: Already sorted
    for (int i = 0; i < n; i++) {
        arr.clear();
        for (int j = 0; j < sizes[i]; j++)
            arr.push_back(j);

        clock_t start = clock();
        heapSort(arr);
        clock_t end = clock();

        cout << "Best time for " << sizes[i] << ": "
             << ((double)(end - start) / CLOCKS_PER_SEC) * 1000.0 << " ms\n";
    }
    cout << "\n";

    // Average case: Random order
    for (int i = 0; i < n; i++) {
        arr.clear();
        for (int j = 0; j < sizes[i]; j++)
            arr.push_back(rand() % sizes[i]);

        clock_t start = clock();
        heapSort(arr);
        clock_t end = clock();

        cout << "Average time for " << sizes[i] << ": "
             << ((double)(end - start) / CLOCKS_PER_SEC) * 1000.0 << " ms\n";
    }
    cout << "\n";

    // Worst case: Reverse sorted
    for (int i = 0; i < n; i++) {
        arr.clear();
        for (int j = sizes[i] - 1; j >= 0; j--)
            arr.push_back(j);

        clock_t start = clock();
        heapSort(arr);
        clock_t end = clock();

        cout << "Worst time for " << sizes[i] << ": "
             << ((double)(end - start) / CLOCKS_PER_SEC) * 1000.0 << " ms\n";
    }
return 0;
}


