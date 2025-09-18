#include <bits/stdc++.h>
using namespace std;
void merge(vector<int> &arr, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int leftArr[n1], rightArr[n2];

    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        rightArr[j] = arr[mid + 1 + j];

    int i = 0;
    int j = 0;
    int k = left;

    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}
void mergeSort(vector<int> &arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {

    string filename="Mergesort.txt";
    random_device rd;
    mt19937 gen(rd());
    int lower_bound = 1;
    int upper_bound = 7500000;
    uniform_int_distribution<> distr(lower_bound,upper_bound);
    ofstream outfile(filename);
    if (!outfile)
    {return 0;}
    cout<<"saving random numbers to "<<filename<<endl;
    for(int i=0;i<upper_bound;i++)
    {
        int random_number=distr(gen);
        outfile<<random_number<<endl;
    }
    outfile.close();
    ifstream infile(filename);
    if(!infile)
    {
        return 0;
    }
   vector<int>arr;
   int number;
   while(infile>>number)
       arr.push_back(number);

   infile.close();

   int n=arr.size();
   mergeSort(arr,0,n-1);
   return 0;
}

