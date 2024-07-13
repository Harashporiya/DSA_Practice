#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int value) {
        data = value;
        next = NULL;
    }
};

void printLinkedList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node* reverseLinkedList(int left, int right, Node* head) {
    if (left == right) return head;

    Node* dummy = new Node(0); 
    dummy->next = head;
    Node* prev = dummy;

   
    for (int i = 0; i < left - 1; ++i) {
        prev = prev->next;
    }

    Node* current = prev->next;
    Node* next = current->next;

   
    for (int i = 0; i < right - left; ++i) {
        current->next = next->next;
        next->next = prev->next;
        prev->next = next;
        next = current->next;
    }

    return dummy->next;
}

int main() {
    int n;
    cin >> n;

    Node* head = NULL;
    Node* temp = NULL;

    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        Node* newNode = new Node(value);
        if (head == NULL) {
            head = newNode;
        } else {
            temp->next = newNode;
        }
        temp = newNode;
    }

    printLinkedList(head);
    int left, right;
    cin >> left >> right;
    head = reverseLinkedList(left, right, head);
    printLinkedList(head);


    return 0;
}
