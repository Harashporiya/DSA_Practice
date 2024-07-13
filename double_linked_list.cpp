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

    void insertAtIndex(int value, int index){

        if(index == 0){
            inserationAtBeginnig(value);
            return;
        }
        Node *newNode = new Node(value);
        Node *temp = head;

        for(int i=0;i<index-1 && temp!=NULL;i++){
            temp = temp->next;
        }

        if(temp == NULL){
            inserationAtTail(value);
            return;
        }

        newNode->next = temp->next;
        newNode->prevs = temp;
        if(temp->next!=NULL){
            temp->next->prevs = newNode;
        }
        temp->next = newNode;
    }
       
       void insertAtValue(int value, int newvalue){
           
           Node *newNode = new Node(newvalue);
           Node *temp = head;

           while(temp!=NULL && temp->data!=value){
            temp = temp->next;
           }

           if(temp == head){
            inserationAtBeginnig(newvalue);
            return;
           }

           newNode->next = temp;
           newNode->prevs=temp->prevs;
           if(temp->prevs!=NULL){
            temp->prevs->next = newNode;
           }

           temp->prevs = newNode;

       }

};
int main(){
    int n;
    cin>>n;

    DoublyLinkedList print;

    print.initilizeList(n);
      print.display();

      int value,newvalue;
      cin>>value>>newvalue;
    //   print.inserationAtBeginnig(value);
    //   print.display();

    // print.inserationAtTail(value);

    // print.insertAtIndex(value,4);

    print.insertAtValue(value,newvalue);
    print.display();
}