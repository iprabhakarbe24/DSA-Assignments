#include <bits/stdc++.h>
using namespace std;

int main() {\
    int n;
    cout<<"enter size of array";
    cin>>n;
    cout<<"enter elemets";
    int arr[n];
    for (int i = 0; i <n; i++)
    {   
        cin>>arr[i];
    }
    // // //selection sort
    int min=0;
    for (int i = 0; i < n; i++)
    {
        min=i;
        for (int j = i+1; j < n; j++)
        {
         if(arr[j]<arr[min]){
            min=j;
         }
        }
        swap(arr[min],arr[i]);
    }
   
    

    cout<<"sorted";
    for (int i = 0; i <n; i++)
    {
        cout<<arr[i]<<endl;
    }
    
    
    return 0;
}
