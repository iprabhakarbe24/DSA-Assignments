#include <iostream>
using namespace std;
void heapifyMax(int a[], int n, int i){
    int largest = i;
    int l = 2*i+1;
    int r = 2*i+2;

    if(l<n && a[l]>a[largest]) largest = l;
    if(r<n && a[r]>a[largest]) largest = r;

    if(largest!=i){
        swap(a[i], a[largest]);
        heapifyMax(a, n, largest);
    }
}
void heapSortInc(int a[], int n){
    for(int i=n/2-1;i>=0;i--) heapifyMax(a, n, i);
    for(int i=n-1;i>=0;i--){
        swap(a[0],a[i]);
        heapifyMax(a, i, 0);
    }
}
void heapifyMin(int a[],int n,int i){
    int smallest = i;
    int l= 2*i+1;
    int r= 2*i+2;

    if(l<n && a[l]<a[smallest]) smallest = l;
    if(r<n && a[r]<a[smallest]) smallest = r;

    if(smallest!=i){
        swap(a[i], a[smallest]);
        heapifyMin(a, n, smallest);
    }
}

void heapSortDec(int a[], int n){
    for(int i=n/2-1; i>=0; i--) heapifyMin(a, n, i);
    for(int i=n-1; i>=0; i--){
        swap(a[0], a[i]);
        heapifyMin(a, i, 0);
    }
}

int main(){
    int a[] = {10,3,5,2,8};
    int n=5;

    heapSortInc(a,n);
    cout << "Increasing: ";
    for(int x:a) cout<<x<<" "; cout<<"\n";

    int b[] = {10,3,5,2,8};
    heapSortDec(b, n);
    cout<<"Decreasing: ";
    for(int x:b) cout<<x<<" ";
}
