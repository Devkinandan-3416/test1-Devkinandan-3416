#include <bits/stdc++.h>
using namespace std;

string doReverse(string& s, int n) {
    if(n == 0) return "";
    return s[n-1] + doReverse(s, n - 1);
};

int main() {
    string str = "Hello";
    int n = str.size();
    cout<<doReverse(str, n)<<endl;
    return 0;
}