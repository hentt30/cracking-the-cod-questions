#include <bits/stdc++.h>
using namespace std;

class Node { 
public: 
    int data; 
    Node* next; 
}; 
 
void addNode(Node * head, int value){

    Node * aux = head;
    while(aux->next != NULL){
        aux = aux->next;
    }
    aux->next =  new Node();
    aux = aux->next;
    aux->data=value;
    aux->next=NULL;
}

void printAllElements(Node *head){
    Node * aux = head;
    while(aux!=NULL){
        cout<<aux->data<<" ";
        aux=aux->next;
    }
    cout<<endl;
}




int main(){

Node * head = new Node();
head->next=NULL;
addNode(head,3);
addNode(head,5);
addNode(head,8);
addNode(head,5);
addNode(head,10);
addNode(head,2);
addNode(head,1);

int partition = 5;
// Code to make partition
Node * beforePartition = new Node();
beforePartition->next=NULL;

Node *afterPartition = new Node();
afterPartition->next=NULL;

// split
Node *aux = head->next;
while(aux != NULL){
    if (aux->data < partition){
        addNode(beforePartition,aux->data);
    }
    else{
        addNode(afterPartition,aux->data);
    }
    aux = aux->next;
}

//Merge the lists
Node *aux2 = beforePartition;
while(aux2->next != NULL){
    aux2 = aux2->next;
}
aux2->next = afterPartition->next;

printAllElements(beforePartition->next);
return 0 ;
}