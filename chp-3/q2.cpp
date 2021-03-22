#include<bits/stdc++.h>

using namespace std;
#define MAX 1000

class Stack{
    int top = -1;
    int minPointer=0;
    public:
        int arr[MAX];
        int minArray[MAX];
        
        Stack(){top=-1;minArray[0]=9999999;};
        bool push(int x);
        int pop();
        int peek();
        bool isEmpty();
        int min();
};

bool Stack::push(int element){
    if(top >= MAX -1 ){
        cout<<"Stack Overflow"<<endl;
        return false;
    }
    else{
        if(element < minArray[minPointer])
        {
            minArray[++minPointer]=element;
        }
        arr[++top] = element;
        return true;
    }
}

int Stack::pop(){
    if(top < 0){
        cout<<"Empty List";
        return false;
    }
    else{
        if(arr[top]==minArray[minPointer]){
            minArray[minPointer--]=0;
        }
        int aux =arr[top];
        arr[top--]=0;
        return aux;
    }
}

int Stack::peek(){
    if(top < 0){
        cout<<"Empty List";
        return false;
    }
    else{
        return arr[top];
    }
}

bool Stack::isEmpty(){ 
    return (top<0);
}

int Stack::min(){
    if(minPointer == 0){
        cout<<"Empty stack";
        return -1;
    }
    return minArray[minPointer];

}

int main(){
Stack a;
a.push(1);
cout<<a.min()<<" "<<endl;
a.pop();
a.push(-1);
cout<<a.min()<<" "<<endl;
a.pop();
a.push(31);
cout<<a.min()<<" "<<endl;
a.push(2);
cout<<a.min()<<" "<<endl;
return 0;
}
