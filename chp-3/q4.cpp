#include<iostream>
#include<stack>
using namespace std;

class MyQueue{

    public:
        stack<int> s1,s2;
        void push(int element);
        void pop();
        void print();

};

void MyQueue::push(int element){
    s1.push(element);
}

void MyQueue::pop(){
    if(s1.empty()){
        cout<<"empty queue"<<endl;
        return;
    }
    while(!s1.empty()){
        int element = s1.top();
        s1.pop();
        s2.push(element);
    }
    s2.pop();
    while(!s2.empty()){
        int element = s2.top();
        s2.pop();
        s1.push(element);
    }
}

void MyQueue::print(){
     while(!s1.empty()){
        int element = s1.top();
        s1.pop();
        s2.push(element);
        cout<<element<<" ";
    }
    cout<<endl;
    //s2.pop();
    while(!s2.empty()){
        int element = s2.top();
        s2.pop();
        s1.push(element);
    }
}

int main(){

    MyQueue a;
    a.push(1);
    a.push(2);
    a.push(3);
    a.push(4);
    a.pop();
    a.print();
    a.pop();
    a.print();
    a.pop();
    a.print();
    a.pop();
    a.print();
    a.pop();

    return 0;

}