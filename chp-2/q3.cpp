#include<iostream>
#include<list>
#include<algorithm>
using namespace std;

void deleteMiddleElement(list<int> &myList, list<int>::iterator element){

    //auto itr= myList.begin();
    //auto itraux = next(itr);

    for(auto itr = myList.begin(); itr != myList.end(); ++itr){
        if (itr == element){
            //itraux->next = itr->next;
            //free(itr);
            //itr = itraux;
            itr = myList.erase(itr);
        }
        //++itraux;
    }


}


int main(){

list<int> myList;
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

auto itr = find(myList.begin(),myList.end(),6);
deleteMiddleElement(myList,itr);

for (auto itr = myList.begin(); itr != myList.end();++itr){
    cout<<*itr<<" ";

}
cout<<endl;


}