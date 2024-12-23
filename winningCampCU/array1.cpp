#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout<<"Enter no. of elements : ";
    cin>>n;
    map<int, int> mp;
    int arr[n];
    for(int i=0; i<n; i++) {
        cout<<"Enter element "<<i+1<<" : ";
        cin>>arr[i];
    }

    int mx = INT_MIN, mxE;
    for(int i=0; i<n; i++) {
        mp[arr[i]]++;
        if(mx < mp[arr[i]]) {
            mx = mp[arr[i]];
            mxE = arr[i];
        }
    }

    if(mx >= n / 2) {
        cout<<mxE<<"is the majority element."<<endl;
    } else {
        cout<<"No majority element found in the array."<<endl;
    }
}