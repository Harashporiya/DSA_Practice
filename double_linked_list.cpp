#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* prevs;
    Node* next;
    Node(int value){
        data = value;
        prevs = NULL;
        next = NULL;
    }
};
class DoublyLinkedList{
    private:
    Node* head;
    Node* tail;
    public:
    DoublyLinkedList(){
        head = NULL;
        tail = NULL;
    }

    void display(){
       Node* temp = head;
       while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
       }
       cout<<endl;
    }


    void initilizeList(int n){

        for(int i=0;i<n;i++){
            int value;
            cin>>value;
            Node* newNode = new Node(value);
            if(head == NULL){
                head = newNode;
                tail = newNode;

            }else{
                tail->next = newNode;
                newNode->prevs = tail;
                tail = newNode;
            }
        }
    }

    void inserationAtBeginnig(int value){
        Node* ptr = new Node(value);

        if(head == NULL){
            head = ptr;
            tail = ptr;
        }else{
            ptr->next=head;
            head->prevs=ptr;
            head=ptr;
        }
    }

    void inserationAtTail(int value){
        Node * p = new Node(value);
        if(head == NULL){
            head = p;
            tail = p;
        }else{
          tail->next = p;
          p->prevs = tail;
         tail = p;
        }

    }


};
int main(){
    int n;
    cin>>n;

    DoublyLinkedList print;

    print.initilizeList(n);
      print.display();

      int value;
      cin>>value;
    //   print.inserationAtBeginnig(value);
    //   print.display();

    print.inserationAtTail(value);
    print.display();
}