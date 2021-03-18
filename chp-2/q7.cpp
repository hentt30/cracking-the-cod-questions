#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node * next;
};

Node * intersect(Node* head1, Node*head2){
    Node * aux1 = head1;
    Node * aux2 = head2;
    while(aux1->next != NULL){
        aux1 = aux1->next;
    }
    while(aux2->next != NULL){
        aux2 = aux2->next;
    }
    if(aux1 == aux2)
        return aux1;
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

int sizeList(Node *head){
    Node * aux = head;
    int size = 0;
    while(aux!=NULL){
        size ++;
        aux = aux->next;
    }
    return size;
}

Node * findIntersect(Node* head1, Node * head2)
{
    Node * aux1 = head1->next;
    Node * aux2 = head2->next;

    int size1 =  sizeList(head1);
    int size2 =  sizeList(head2);

    if(size1 > size2){
        int diff = size1 - size2;
        while(diff--){
            aux1 = aux1->next;
        }
    }else if(size2>size1){
        int diff = size2 - size1;
        while(diff--){
            aux2 = aux2->next;
        }
    }

    while(aux1!=NULL && aux2 !=NULL){
        if(aux1 == aux2){
            return aux1;
        }
        aux1 = aux1->next;
        aux2 = aux2->next;
    }
    return NULL;

    
}


int main(){

Node * list1 = new Node();
list1->data = 0;
list1->next = NULL;
pushBack(list1,1);
pushBack(list1,2);
pushBack(list1,3);



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
aux1->next = list2->next->next->next->next;


Node * result = intersect(list1,list2);

if(result == NULL){
cout<<"do not intersect"<<endl;
}else{
    Node * intersect_in = findIntersect(list1,list2);
    cout<<"intersect in "<<intersect_in->data<<endl;
}

return 0;

}