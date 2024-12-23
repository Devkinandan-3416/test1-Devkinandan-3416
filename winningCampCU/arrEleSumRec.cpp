#include <bits/stdc++.h>
using namespace std;

int getSum(int arr[], int n) {
    if(n == 0) return 0;
    return arr[n-1] + getSum(arr, n-1);
};

int main() {
    int n;
    cout<<"Enter a no. : ";
    cin>>n;
    int arr[n];

    for(int i=0; i<n; i++) {
        cout<<"Enter element "<<i+1<<" : ";
        cin>>arr[i];
    }
    cout<<getSum(arr, n)<<endl;
    return 0;
}