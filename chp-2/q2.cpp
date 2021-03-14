#include<iostream>
#include<list>

using namespace std;

int kthElement(list<int> &linkedList,int k){
int size(0);
for(auto itr = linkedList.begin(); itr != linkedList.end();++itr){
    size++;
}

int counter(0);

for(auto itr = linkedList.begin(); itr != linkedList.end();++itr){
    counter++;
    if(size - counter ==k ){
        return *itr;
    }
}
return -1;
}

int recursiveKthElement(list<int> &linkedList,list<int>::iterator itr,int k,int&element){

    if(itr == linkedList.end())
        return 0;
    int height = recursiveKthElement(linkedList,next(itr),k,element);
    if( height == k )
    {   
        element = *itr;
    }
    return height + 1;

return -1;
}



int main(){
list<int>myList;
myList.push_back(1);
myList.push_back(2);
myList.push_back(3);
myList.push_back(4);
myList.push_back(5);
myList.push_back(6);
myList.push_back(7);
myList.push_back(8);
myList.push_back(9);
myList.push_back(10);
myList.push_back(11);

//int element = kthElement(myList,3);
int element = -1;
recursiveKthElement(myList,myList.begin(),1,element);

if(element == -1){
    cout<<"k é maior que a lista"<<endl;
}
else{
    cout<<element<<endl;
}


return 0;
}