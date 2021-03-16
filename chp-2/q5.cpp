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

Node * sumLists(Node * head1, Node* head2){
     Node *sumList = new Node();
     sumList->next=NULL;

     Node *aux1 = head1->next;
     Node *aux2 = head2->next;
    int rest = 0;
     while(aux1 != NULL && aux2 != NULL){
        int element = aux1->data + aux2->data + rest;
        if (element >= 10){
            rest = 1;
            element = element%10;
        }else{
            rest = 0;
        }
        addNode(sumList,element);
        aux1 = aux1->next;
        aux2 = aux2->next;
     }
     //cout<<aux1<<endl;
     
     while(aux1!=NULL){
         int element = aux1->data + rest;
         if (element >= 10){
            rest = 1;
            element = element%10;
        }else{
            rest = 0;
        }
        addNode(sumList,element);
        aux1 = aux1->next;
     }
     
     while(aux2!=NULL){
         int element = aux2->data + rest;
         if (element >= 10){
            rest = 1;
            element = element%10;
        }else{
            rest = 0;
        }
        addNode(sumList,element);
        aux2 = aux2->next;
     }

     if (rest == 1){
         addNode(sumList,1);
     }
     return sumList;
}


int main(){

Node * list1 = new Node();
list1->next=NULL;
addNode(list1,7);
addNode(list1,1);
addNode(list1,6);
addNode(list1,1);

Node * list2 = new Node();
list2->next=NULL;
addNode(list2,5);
addNode(list2,9);
addNode(list2,2);

Node * sumList = sumLists(list1,list2);
printAllElements(sumList->next);
return 0 ;
}