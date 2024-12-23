#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    int n=nums.size();
    int j=0;
    for(int i=1; i<n && j<n; ) {
        if(nums[i]!=nums[j]) {
            nums[++j] = nums[i];
        } else {
            i++;
        }
    }
    return j+1;
}

int main() {
    vector<int> v = {0,0,1,1,1,2,2,3,3,4};
    int n = v.size();
    removeDuplicates(v);
    for(int i=0; i<n; i++) {
        cout<<v[i]<<" ";
    }
    return 0;
}