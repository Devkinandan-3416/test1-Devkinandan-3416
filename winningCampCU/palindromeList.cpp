#include <bits/stdc++.h>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* temp = head;
        ListNode* forward = nullptr;

        while (temp) {
            forward = temp->next;
            temp->next = prev;
            prev = temp;
            temp = forward;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;

        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* prev = reverse(slow);
        ListNode* temp = head;
        while (prev) {
            if (prev->val != temp->val) return false;
            prev = prev->next;
            temp = temp->next;
        }
        reverse(slow);
        return true;
    }
};

void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

ListNode* createList(const vector<int>& values) {
    ListNode* head = nullptr;
    ListNode* temp = nullptr;

    for (int val : values) {
        ListNode* newNode = new ListNode(val);
        if (!head) {
            head = newNode;
        } else {
            temp->next = newNode;
        }
        temp = newNode;
    }
    return head;
}

int main() {
    Solution solution;

    vector<int> values = {1, 2, 3, 2, 1};
    ListNode* head = createList(values);

    cout << "Original List: ";
    printList(head);

    if (solution.isPalindrome(head)) {
        cout << "The list is a palindrome." << endl;
    } else {
        cout << "The list is not a palindrome." << endl;
    }

    return 0;
}