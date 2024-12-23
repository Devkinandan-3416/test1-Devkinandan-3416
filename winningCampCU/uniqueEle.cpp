#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[] = {2,3,3,5,5};
    int n = sizeof(arr) / sizeof(int);
    int mx = INT_MIN;
    int count[mx] = {0};

    int i=0;
    while(i<n) {
        count[arr[i]]++;
        i++;
    }

    i=0;
    while(i<n) {
        if(count[arr[i]] == 1) {
            break;
        }
    }

    cout<<arr[i];
    return 0;
}