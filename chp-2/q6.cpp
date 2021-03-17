#include<iostream>

using namespace std;

class Node{
    public:
        char data;
        Node * next;
};
// Head without dummy node

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
void reverseList(Node * head, Node* reverseList1){
    if(head == NULL){
        return;
    }
    if(head != NULL)
        reverseList(head->next,reverseList1);
    
    pushBack(reverseList1,head->data);
}

void printAllElements(Node *head){
    Node * aux = head;
    while(aux!=NULL){
        cout<<aux->data<<" ";
        aux=aux->next;
    }
    cout<<endl;
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

bool isPalindrome(Node*list1,Node*list2){
int size = sizeList(list1->next);
Node* aux1 = list1->next;
Node* aux2 = list2->next;

size = size/2;

while(size--){
    if (aux1->data != aux2->data){
        return false;
    }
    aux1=aux1->next;
    aux2=aux2->next;
}
return true;

}


int main(){
Node * list1 = new Node();
list1->data = 0;
list1->next = NULL;
pushBack(list1,'m');
pushBack(list1,'i');
pushBack(list1,'s');
pushBack(list1,'s');
pushBack(list1,'i');
pushBack(list1,'n');

Node * reverseList1 = new Node();
reverseList1->data=0;
reverseList1->next = NULL;
reverseList(list1->next,reverseList1);

bool result = isPalindrome(list1,reverseList1);

if(result)
    cout<<"is palindrome"<<endl;
else
    cout<<"it is not a palindrome"<<endl;




return 0;

}