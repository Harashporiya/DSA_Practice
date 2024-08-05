#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
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

Node* reverse(Node* head){
    Node* ptr = head;
    Node* p = NULL;
    while(ptr!=NULL ){
        Node* temp = ptr->next;
       ptr->next = p;
       p = ptr;
        ptr = temp;
    } return p;
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

    head = reverse(head);
    printLinkedList(head);
    return 0;
}
