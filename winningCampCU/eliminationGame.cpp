#include <bits/stdc++.h>
using namespace std;

int lastRemaining(vector<int>& arr, int n) {
    bool flag = true;
    while (arr.size() > 1) {
        n = arr.size();
        if (flag) {
            for (int i = 0; i < n; i++) {
                arr.erase(arr.begin() + i);
                n--;
            }
        } else {
            for (int i = n - 1; i >= 0; i -= 2) {
                arr.erase(arr.begin() + i);
            }
        }
        flag = !flag;
    }
    return arr[0];
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = arr.size();
    cout << lastRemaining(arr, n);
    return 0;
}