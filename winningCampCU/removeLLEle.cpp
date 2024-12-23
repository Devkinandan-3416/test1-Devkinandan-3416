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

        Node* removeElements(Node* head, int val) {
            while(head && head->val == val) {
                Node* toDelete = head;
                head = head->next;
                delete toDelete;
            }
            if(!head) return nullptr;

            Node* prev = nullptr;
            Node* temp = head;
            while(temp) {
                if(temp->val == val) {
                    if(prev) prev->next = temp->next;
                    Node *delNode = temp;
                    temp = temp->next;
                    delete delNode;
                } else {
                    prev = temp;
                    temp = temp->next;
                }
            }
            return head;
        }
};

int main() {
    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;

    Node* head = nullptr;
    Node* temp = nullptr;

    for (int i = 0; i < n; i++) {
        int value;
        cout << "Enter value for node " << i + 1 << ": ";
        cin >> value;
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
        } else {
            temp->next = newNode;
        }
        temp = newNode;
    }

    int valToRemove;
    cout << "Enter value to remove: ";
    cin >> valToRemove;

    head = head->removeElements(head, valToRemove);

    temp = head;
    cout << "Updated List: ";
    while(temp) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    return 0;
}