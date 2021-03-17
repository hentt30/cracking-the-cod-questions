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

int sizeList(Node *head){
    Node * aux = head;
    int size = 0;
    while(aux!=NULL){
        size ++;
        aux = aux->next;
    }
    return size;
}

void addZeros(Node * head, int quant){
    while(quant--){
        Node * node = new Node();
        node ->data = 0;
        node ->next = head->next;
        head->next= node;
    }
    return;
}

void addBeginNode(Node* head, int element){
    Node * value = new Node();
    value->data = element;
    value->next = head ->next;
    head->next = value;
    return;
}

void sumReverse(Node * head1, Node * head2, int &rest , Node* sumList){
        if(head1 == NULL && head2 == NULL)
            return;
        
        if(head1!=NULL && head2!=NULL){
            sumReverse(head1->next,head2->next,rest,sumList);
        }

        int element = head1->data + head2->data + rest;
        if (element >= 10){
            rest = 1;
            element = element%10;
        }else{
            rest = 0;
        }
        addBeginNode(sumList,element);


}


int main(){

Node * list1 = new Node();
list1->next=NULL;
addNode(list1,6);
addNode(list1,1);
addNode(list1,7);

Node * list2 = new Node();
list2->next=NULL;
addNode(list2,2);
addNode(list2,9);
addNode(list2,5);

//Node * sumList = sumLists(list1,list2);
if(sizeList(list1) > sizeList(list2)){
    addZeros(list2,sizeList(list1) - sizeList(list2));
}else if (sizeList(list2) > sizeList(list1)){
    addZeros(list1,sizeList(list2) - sizeList(list1));
}
Node * sumList = new Node();
sumList->next=NULL;
int rest = 0;
sumReverse(list1->next,list2->next,rest,sumList);
printAllElements(sumList->next);
return 0 ;
}