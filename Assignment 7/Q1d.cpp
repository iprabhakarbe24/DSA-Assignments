#include <iostream>
#include<vector>
using namespace std;

void merge(vector<int> &arr, int l, int m, int r) {
    vector<int>temp;
    int left=l;
    int right=m+1;
    while(left<=m && right <=r){
        if(arr[left]<=arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            right++;
        }
    }
    while(left<=m){
         temp.push_back(arr[left]);
            left++;
    }
    while(right<=r){
         temp.push_back(arr[right]);
            right++;
    }
    for (int i = l; i <= r; i++)
    {
    arr[i]=temp[i-l];
    }
    

}

void mergeSort(vector<int> &arr, int l, int r) {
    if (l >=r) {return ;}
    else {
        int m = (l + r)/ 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
  vector<int>arr(n);
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) cin >> arr[i];

    mergeSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    return 0;
}