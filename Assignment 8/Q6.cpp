#include<iostream>
using namespace std;

int h[100],s=0;

void insertPQ(int x){
    h[s]=x;int i=s;s++;
    while(i>0){
        int p=(i-1)/2;
        if(h[p]<h[i])swap(h[p],h[i]);
        else break;
        i=p;
    }
}

int deleteMax(){
    if(s==0)return -1;
    int m=h[0];h[0]=h[s-1];s--;
    int i=0;
    while(1){
        int l=2*i+1,r=2*i+2,b=i;
        if(l<s&&h[l]>h[b])b=l;
        if(r<s&&h[r]>h[b])b=r;
        if(b!=i){swap(h[i],h[b]);i=b;}
        else break;
    }
    return m;
}

void display(){
    for(int i=0;i<s;i++)cout<<h[i]<<" ";
    cout<<"\n";
}

int main(){
    insertPQ(30);
    insertPQ(10);
    insertPQ(50);
    insertPQ(40);
    display();
    cout<<deleteMax()<<"\n";
    display();
  return 0;
}
