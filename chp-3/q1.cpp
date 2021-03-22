#include<iostream>

using namespace std;

int arr[10];

//Stack 1
int iniStack1=0;
int fimStack1= 10/3-1;
int pointer1=iniStack1;

//Stack 2
int iniStack2 = fimStack1 + 1;
int fimStack2 = iniStack2 + 10/3-1;
int pointer2=iniStack2;

//Stack3
int iniStack3 = fimStack2 + 1;
int fimStack3 = iniStack3 + 10/3 -1;
int pointer3=iniStack3;

void pushStack1(int element){
    if (pointer1 == fimStack1 +1)
    {
        cout<<"full stack"<<endl;
        return;
    }
    arr[pointer1] = element;
    ++pointer1;
    return;
}

void popStack1(){
    if (pointer1 == iniStack1)
    {
        cout<<"empty stack"<<endl;
        return;
    }
    --pointer1;
    arr[pointer1] = 0;
    return;
}

void pushStack2(int element){
    if (pointer2 == fimStack2 +1)
    {
        cout<<"full stack"<<endl;
        return;
    }
    arr[pointer2] = element;
    ++pointer2;
    return;
}

void popStack2(){
    if (pointer2 == iniStack2)
    {
        cout<<"empty stack"<<endl;
        return;
    }
    --pointer2;
    arr[pointer2] = 0;
    return;
}

void pushStack3(int element){
    if (pointer3 == fimStack3 +1)
    {
        cout<<"full stack"<<endl;
        return;
    }
    arr[pointer3] = element;
    ++pointer3;
    return;
}

void popStack3(){
    if (pointer3 == iniStack3)
    {
        cout<<"empty stack"<<endl;
        return;
    }
    --pointer3;
    arr[pointer3] = 0;
    return;
}

int main(){

pushStack1(1);
pushStack1(2);
pushStack1(3);
pushStack1(4);

pushStack2(5);
pushStack2(6);
pushStack2(7);
pushStack2(8);

pushStack3(9);
pushStack3(10);
pushStack3(11);
pushStack3(12);

popStack1();
popStack1();
popStack1();
popStack1();

popStack2();
popStack2();
popStack2();
popStack2();

popStack3();
popStack3();
popStack3();
popStack3();

for(int i = 0 ; i < 10; ++i)
    cout<<arr[i]<<" ";
cout<<endl;
return 0;

}