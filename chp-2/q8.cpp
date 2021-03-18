#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node *next;
};

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

void findLoop1(Node* list1){
    //Find the last element
    map<Node *,bool> myMap;
    Node* aux1 = list1->next;
    while(aux1!=NULL){
        if(myMap.find(aux1) != myMap.end()){
            cout<<"The end of the circular list is "<<aux1->data<<endl;
            break;
        }else{
            myMap[aux1]=true;
        }
        aux1 = aux1->next;
    }
    return;
}

void findLoop2(Node *list1){
    Node * speed = list1->next;
    Node * slow  = list1->next;

    while(speed != NULL && slow !=NULL){
        speed = speed->next->next;
        slow = slow->next;
        if(speed == slow){
            break;
        }
    }
    speed = list1->next;
    while(true){
        if(speed == slow){
            cout<<"The end of the circular list is "<<speed->data<<endl;
            break;
        }
        speed = speed->next;
        slow = slow->next;
    }
    return;
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
pushBack(list1,7);
pushBack(list1,8);
Node * makeCircular = list1;
while(makeCircular->next != NULL){
    makeCircular = makeCircular->next;
}
makeCircular->next = list1->next->next->next->next;

findLoop2(list1);



return 0;

}