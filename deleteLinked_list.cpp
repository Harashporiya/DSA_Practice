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

void printlinkedlist(Node *head) {
    while(head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
Node *deleteLinkedlistfirst(Node *head){
    Node *ptr = head;
    head = head->next;
    delete ptr;
    return head;
}
Node *deleteLinkedlistlast(Node *head){
    Node *ptr = head;
    Node *p = head->next;
    while(p->next!=NULL){
        ptr = ptr->next;
        p = p->next;
    }
    ptr->next=NULL;
    delete p;
    return head;
}
Node *IndexLinkedListDelete(Node *head, int index){
    Node* ptr = head;
    Node *temp = head->next;
    for(int i=0;i<index-1;i++){
        ptr = ptr->next;
        temp=temp->next;
    }
    ptr->next=temp->next;
    delete temp;
    return head;
}
Node* valuedeleteNode(Node *head, int value){
    Node* ptr=head;
    Node* p = head->next;
    while(p->data != value && ptr->next!=NULL){
        ptr=ptr->next;
        p=p->next;
    }
    if(p->data == value){
        ptr->next = p->next;
        delete p;
    }
    return head;
}
int main() {
    int n;
    cin >> n;
    Node *head = NULL;
    Node *temp = NULL;

    for(int i = 0; i < n; i++) {
        int value;
        cin >> value;
        Node *newNode = new Node(value);
        if(head == NULL) {
            head = newNode;
        } else {
            temp->next = newNode;
        }
        temp = newNode;
    }
    // head = deleteLinkedlistfirst(head);
    // head = deleteLinkedlistlast(head);
    // int index = 4;
    // head = IndexLinkedListDelete(head, index);
    // head = valuedeleteNode(head,index);
    // printlinkedlist(head);
    // return 0;
}
