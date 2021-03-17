#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node * next;
};

Node * intersect(Node* head1, Node*head2){
    Node * aux1 = head1;
    while(aux1!=NULL){
        Node*aux2 = head2;
        while(aux2!=NULL){
            if(aux1 == aux2){
                return aux1;
            }
            aux2 = aux2->next;
        }
        aux1 = aux1->next;
    }
    return NULL;
}

void pushBack(Node * head, char element){
        if(head == NULL){
            return;
        }
        Node * node = new Node;
        node ->data = element;
        node ->next = NULL;
        Node * aux = head;
        while(aux->next != NULL){
            aux = aux->next;
        }
        aux->next = node;
}

int main(){

Node * list1 = new Node();
list1->data = 0;
list1->next = NULL;
pushBack(list1,1);
pushBack(list1,2);
pushBack(list1,3);
pushBack(list1,4);
pushBack(list1,5);
pushBack(list1,6);


Node * list2 = new Node();
list2->data = 0;
list2->next = NULL;
pushBack(list2,1);
pushBack(list2,2);
pushBack(list2,3);
pushBack(list2,4);
pushBack(list2,5);
pushBack(list2,6);
pushBack(list2,7);
Node *aux1 = list1;
while(aux1->next!=NULL){
    aux1=aux1->next;
}
aux1->next = list2;


Node * result = intersect(list1,list2);

if(result == NULL){
cout<<"do not intersect"<<endl;
}else{
    cout<<"intersect";
}

return 0;

}