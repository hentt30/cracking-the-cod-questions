#include<iostream>
#include<list>
#include<map>

using namespace std;

void removeEqualElementsExtraMemory(list<int> &unsortedList){
    // O(n) algorithm
    map<int,int> elements;

    for(auto itr = unsortedList.begin();itr!=unsortedList.end();++itr){
        int value = *itr;

        if(elements.find(value) == elements.end()){
            elements.insert(pair<int,int>(value,true));
        }
        else{
            
            itr = unsortedList.erase(itr);
        }
    }
}

void removeEqualElementsWithoutExtraMemory(list<int> &unsortedList){
    
    for(auto itr = unsortedList.begin(); itr != unsortedList.end(); ++itr){
        for(auto itr2 = next(itr); itr2 != unsortedList.end(); ++itr2){

            if(*itr2 == *itr){
                //cout<<*itr<<endl;
                itr2 = unsortedList.erase(itr2);
            }
        }
    }
    
}



int main(){

list<int> unsortedList;
unsortedList.push_back(1);
unsortedList.push_back(2);
unsortedList.push_back(3);
unsortedList.push_back(4);
unsortedList.push_back(5);
unsortedList.push_back(5);
unsortedList.push_back(7);
unsortedList.push_back(6);


//removeEqualElementsExtraMemory(unsortedList);
removeEqualElementsWithoutExtraMemory(unsortedList);

for (auto itr = unsortedList.begin(); itr != unsortedList.end();++itr){
    cout<<*itr<<" ";

}
cout<<endl;

return 0 ;

}