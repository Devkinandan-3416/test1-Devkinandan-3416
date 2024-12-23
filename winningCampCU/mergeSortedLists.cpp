#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        int val;
        Node* next;
        Node(int val) {
            this->val = val;
            this->next = nullptr;
        }
        Node* mergeTwoLists(Node* list1, Node* list2) {
            Node* t1 = list1;
            Node* t2 = list2;

            Node* dummy = new Node(0);
            Node* temp = dummy;

            while(t1 && t2) {
                if(t1->val <= t2->val) {
                    temp->next = t1;
                    temp = t1;
                    t1 = t1->next;
                } else {
                    temp->next = t2;
                    temp = t2;
                    t2 = t2->next;
                }
            }
            if(t1) temp->next = t1;
            else temp->next = t2;

            Node* toDelete = dummy;
            Node* head = dummy->next;
            delete dummy;
            
            return head;
        }
};

int main() {
    Node* list1 = new Node(1);
    list1->next = new Node(2);
    list1->next->next = new Node(4);

    Node* list2 = new Node(1);
    list2->next = new Node(3);
    list2->next->next = new Node(4);

    Node* mergedList = list1->mergeTwoLists(list1, list2);

    while(mergedList) {
        cout << mergedList->val << " ";
        mergedList = mergedList->next;
    }
    return 0;
}