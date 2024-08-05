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

Node *removeDuplicates(Node* head){
    Node* ptr = head;
    while(ptr!=NULL && ptr->next!=NULL){
        Node* temp = ptr->next;
        if(ptr->data == temp->data){
             ptr->next = temp->next;
             delete temp;
            
        }else{
            ptr = ptr->next;
        }
    } return head;
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

    // printLinkedList(head);
    head = removeDuplicates(head);
    printLinkedList(head);
    return 0;
}
