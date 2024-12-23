#include <bits/stdc++.h>
using namespace std;

vector<int> generateArr(int numRows) {
    vector<int> v;
    v.push_back(1);
    long long ans = 1;
    for(int i=1; i<numRows; i++) {
        ans = ans*(numRows-i);
        ans = ans/(i);
        v.push_back(ans);
    }
    return v;
}
vector<vector<int>> generate(int numRows) {
    vector<vector<int>> res;
    for(int i=1; i<=numRows; i++) {
        res.push_back(generateArr(i));
    }
    return res;
}

int main() {
    vector<vector<int>> v;
    int numRows;
    cin>>numRows;
    v = generate(numRows);

    for(int i=0; i<numRows; i++) {
        for(int j=0; j<v[i].size(); j++) {
            cout<<v[i][j];
        }
        cout<<endl;
    }
    return 0;
}