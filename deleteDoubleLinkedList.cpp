#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *prevs;
    Node *next;
    Node(int value){
        data = value;
        prevs = NULL;
        next = NULL;;
    }
};
class DoubleLinkedListDelete{
    private:
    Node* head;
    Node *tail;
    public:
    DoubleLinkedListDelete(){
        head = NULL;
        tail = NULL;
    }

    void display(){
        Node *temp = head;
        while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
    }

    void insliziation(int n){
    
        for(int i=0;i<n;i++){
            int value;
            cin>>value;
            Node *newNode = new Node(value);

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

    void deleteFirstNode(){
        Node *temp = head;
       
       head = head->next;
        if(head!=NULL){
            head->prevs=NULL;
        }else{
            tail = NULL;
        }
         delete(temp);
    }

    void lastdeleteNode(){
        Node *temp = tail;
        tail=tail->prevs;
        if(tail!=NULL){
         tail->next=NULL;
        }else{
            head = NULL;
        }

        delete(temp);

    }

    void indexDelete(int index){
        Node *temp = head;
        for(int i=0;i<index && temp!=NULL;i++){
            temp = temp->next;
        }

        if(temp->prevs!=NULL){
            temp->prevs->next = temp->next;
        }else{
            head = temp->next;
        }

        if(temp->next!=NULL){
            temp->next->prevs = temp->prevs;
        }else{
            tail=temp->prevs;
        }
        delete temp;
    }

    void deleteByValue(int value){
        Node *temp = head;

          while (temp != nullptr && temp->data != value) {
            temp = temp->next;
        }

         if(temp->prevs!=NULL){
            temp->prevs->next = temp->next;
        }else{
            head = temp->next;
        }

        if(temp->next!=NULL){
            temp->next->prevs = temp->prevs;
        }else{
            tail=temp->prevs;
        }
        delete temp;
    }

};
int main(){
    int n;
    cin>>n;
     
     DoubleLinkedListDelete print;

   
     print.insliziation(n);
       print.display();

    //    print.deleteFirstNode();

    // print.lastdeleteNode();

    // print.indexDelete(3);
    print.deleteByValue(3);
       print.display();

}