#include <iostream>
using namespace std;

class Solution {
public:
    char kthCharacter(int k) {
        string word = "a";
        int len = word.length();
        
        while (len < k) {
            int currentLen = word.length();
            for (int i = 0; i < currentLen; i++) {
                word += (word[i] == 'z') ? 'a' : word[i] + 1;
            }
            len = word.length();
        }
        
        return word[k - 1];
    }
};

int main() {
    Solution solution;
    
    int k;
    cin >> k;
    
    cout << solution.kthCharacter(k) << endl;
    
    return 0;
}