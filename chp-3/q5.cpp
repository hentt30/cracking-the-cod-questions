#include<iostream>
#include<stack>

using namespace std;

void sortStack(stack<int> &s1){
    stack<int> s2;
    
    while(!s1.empty()){

        int element = s1.top();
        s1.pop();
        while(!s2.empty() &&  element < s2.top()){
            
            s1.push(s2.top());
            s2.pop();
        }
        s2.push(element);
    }

    while(!s2.empty()){
        //cout<<s2.top()<<endl;
        s1.push(s2.top());
        s2.pop();
    }
}

int main(){
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(5);
   
    sortStack(s);
    while(!s.empty()){
        int element = s.top();
        cout<<element<<endl;
        s.pop();
    }
    return 0 ;
}