#include <bits/stdc++.h>
using namespace std;

int partition(int arr[],int low,int high){
    int pivot=low;
    int i=low;
    int j=high;
    while(i<j){
        while(arr[i]<=arr[pivot] && i<=high-1){
            i++;
        }
        while(arr[j]>arr[pivot] && j>=low+1){
            j--;
        }
        if(i<j){swap(arr[i],arr[j]);
        }
    }
    swap(arr[pivot],arr[j]);
    return j;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int n;
    cout << "enter size of array: ";
    cin >> n;

    int arr[n];
    cout << "enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    quickSort(arr, 0, n - 1);  

    cout << "sorted: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
