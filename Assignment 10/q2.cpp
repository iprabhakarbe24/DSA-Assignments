#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    int A[] = {1,2,3,4};
    int B[] = {3,4,5,6};

    unordered_set<int> s(A, A+4);

    for(int x : B){
        if(s.count(x))
            cout << x << " ";
    }
}
