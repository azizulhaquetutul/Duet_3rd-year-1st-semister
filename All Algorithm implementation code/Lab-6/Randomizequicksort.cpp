#include <iostream>
#include <vector>
#include <chrono>
#include <ctime>
#include <algorithm> // For sorting in increasing and decreasing order
using namespace std;

void Interchange(vector<int>& a, int i, int j) {
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

int Partition(vector<int>& a, int m, int p) {
    int v = a[m];
    int i = m;
    int j = p;
    while (i < j) {
        while (i < p && a[i] <= v) {
            i++;
        }
        while (j > m && a[j] > v) {
            j--;
        }
        if (i < j) {
            Interchange(a, i, j);
        }
    }
    a[m] = a[j];
    a[j] = v;
    return j;
}

void RQuickSort(vector<int>& a, int p, int q) {
    if (p < q) {
        // Randomize pivot by swapping with a random element
        if ((q - p) > 5) {
            Interchange(a, rand() % (q - p + 1) + p, p);
        }
        int j = Partition(a, p, q);
        RQuickSort(a, p, j - 1);
        RQuickSort(a, j + 1, q);
    }
}

int main() {
    int n = 1000;  // Set n to 100

    // Random Elements
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = rand() % n + 1;  // Fill the vector with random numbers
    }
    auto start = chrono::high_resolution_clock::now();
    RQuickSort(a, 0, n - 1);  // Call Randomized QuickSort
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;
    cout << "For random elements = " << n << " Time required: " << duration.count() * 1000 << " ms" << endl;

    //  Increasing Order
    sort(a.begin(), a.end());
    start = chrono::high_resolution_clock::now();
    RQuickSort(a, 0, n - 1);
    end = chrono::high_resolution_clock::now();
    duration = end - start;
    cout << " \n Increasing order  = " << n << endl;
    cout<<" Time required: " << duration.count() * 1000 << " ms" << endl;

    //  Decreasing Order
    sort(a.begin(), a.end(), greater<int>());
    start = chrono::high_resolution_clock::now();
    RQuickSort(a, 0, n - 1);
    end = chrono::high_resolution_clock::now();
    duration = end - start;
    cout << "\n Decreasing order  = " << n << endl;
    cout<<" Time required: " << duration.count() * 1000 << " ms" << endl;

    //Uniformly Ordered Elements
    fill(a.begin(), a.end(), 5);
    start = chrono::high_resolution_clock::now();
    RQuickSort(a, 0, n - 1);
    end = chrono::high_resolution_clock::now();
    duration = end - start;
    cout << "\n Uniformly ordered elements = " << n << endl;
    cout<<" Time required: " << duration.count() * 1000 << " ms" << endl;

    return 0;
}

