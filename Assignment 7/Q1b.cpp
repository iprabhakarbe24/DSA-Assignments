#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout<<"enter size of array";
    cin>>n;
    cout<<"enter elemets";
    int arr[n];
    for (int i = 0; i <n; i++)
    {   
        cin>>arr[i];
    }
    //insertion sort
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
     cout<<"sorted";
    for (int i = 0; i <n; i++)
    {
        cout<<arr[i]<<endl;
    }
    
    return 0;
}