#include<iostream>
#include<vector>
#define MAX 3
using namespace std;

class Stack{
    int top=-1;
    int level=0;
    public:
        vector<vector<int>> arr;
        Stack(){arr.resize(1);level=0;}
        bool isEmpty();
        int pop();
        void push(int element);
        void print();
        int popAt(int index);
};

void Stack::push(int element){
    if(arr[level].size() >= MAX){
        int size = arr.size();
        arr.resize(++size);
        level++;
        arr[level].push_back(element);
    }
    else{
        arr[level].push_back(element);
    }
    return;
}

int Stack::pop(){
    if(0 == (int)arr[level].size()){
       if(level == 0){
           cout<<"Empty"<<endl;
           return -1;
       } 
       arr.pop_back();
       level--;
       int aux = arr[level].back();
       arr[level].pop_back();
       return aux;
    }
    else{
        int aux = arr[level].back();
        arr[level].pop_back();
        return aux;
    }
}

bool Stack::isEmpty(){
    return (level==0 && 0==(int)arr[level].size() );
}

void Stack::print(){
    for(int i = 0 ; i < (int)arr.size();++i){
        for(int j=0; j <(int)arr[i].size();++j)
            cout<<arr[i][j]<<" ";
        cout<<endl;        
    }
}

int Stack::popAt(int index){
    if(index < (int)arr.size() && 0< (int)arr[index].size()){
        int aux = arr[index].back();
        arr[index].pop_back();
        return aux;
    }else{
        arr.erase(arr.begin() + index);
        level--;
        cout<<"empty plile or inacessible stack"<<endl;
        return -1;

    }
}

int main(){
Stack a;
a.push(1);
a.push(1);
a.push(1);
a.push(1);
a.push(1);
a.push(1);
a.pop();
a.pop();
a.pop();
a.pop();
a.pop();
a.pop();
a.pop();
a.pop();
a.pop();
a.pop();
a.pop();
a.pop();
a.pop();
a.pop();
a.pop();
a.push(1);
a.push(1);
a.push(1);
a.push(1);
a.push(1);
a.push(1);
a.push(1);
a.push(1);
a.push(1);
a.push(1);
a.push(1);
a.push(1);
a.push(1);
a.push(1);
a.push(1);
a.push(1);
a.push(1);
a.push(1);
a.popAt(1);
a.popAt(1);
a.popAt(1);
a.popAt(1);
a.pop();
a.pop();
a.pop();
a.pop();
a.pop();
a.pop();
a.pop();
a.pop();
a.pop();
a.pop();
a.pop();
a.pop();
a.pop();
a.pop();
a.print();

return 0;

}



