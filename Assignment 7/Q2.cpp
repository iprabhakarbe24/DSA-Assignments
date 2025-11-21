#include <bits/stdc++.h>
using namespace std;
void doubleSelectionSort(int arr[], int n) {
    int left = 0;           
    int right = n - 1;       

    while (left < right) {
        int minIndex = left;
        int maxIndex = right;

        if (arr[minIndex] > arr[maxIndex])
            swap(arr[minIndex], arr[maxIndex]);

        
        for (int i = left + 1; i <= right; i++) {
            if (arr[i] < arr[minIndex])
                minIndex = i;
            else if (arr[i] > arr[maxIndex])
                maxIndex = i;
        }

        swap(arr[left], arr[minIndex]);

        if (maxIndex == left)
            maxIndex = minIndex;

        swap(arr[right], arr[maxIndex]);

        left++;
        right--;
    }
}

int main() {
     int n;
     cout<<"enter size of array";
    cin >> n;

    int arr[n];
    cout<<"enter elements";
    for (int i = 0; i < n; i++) cin >> arr[i];

    doubleSelectionSort(arr, n);

    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    return 0;
}