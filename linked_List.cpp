#include<iostream>
#include<vector>
using namespace std;
class Node{
    public:
    int data;
    Node *next;

    Node(int val){
        data = val;
        next = NULL;
    }
};
void printlinkedlist(Node *head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}
Node* inserationfirst(Node *head, int data){
     Node *temp = new Node(data);
     temp->next = head;
     temp->data=data;
     return temp;
}
Node *lastinseration(Node *head, int data){
    Node *temp = new Node(data);
    Node *ptr = head;
    while(ptr->next!=NULL){
     ptr=ptr->next;
    }
    ptr->next = temp;
    return head;
}
Node *indexInseration(Node *head, int data, int index){
    Node *temp = new Node(data);
    Node *ptr = head;
    int i=0;
    while(i!=index-1){
        ptr = ptr->next;
        i++;
    }
    temp->next=ptr->next;
    ptr->next=temp;
    return head;
}
int main(){
    int n;
    cin>>n;

         Node *head = NULL;
         Node *temp = NULL;

     for(int i=0;i<n;i++){
        int value;
        cin>>value;
         Node *newNode = new Node(value);
         if(head == NULL){
           newNode=head;
         }else{
            temp->next = newNode;
         }
        temp = newNode;
     }
     int data = 0;
    // head =  inserationfirst(head,data);
    // head = lastinseration(head, data);
    head = indexInseration(head,data,2);
     printlinkedlist(head);
}