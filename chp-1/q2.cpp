#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

bool is_permutation(string source, string target){
   vector<int> sourceLetters(128,0);
   vector<int> targetLetters(128,0);

   for (int i = 0; i < (int) source.size(); ++i){
       int index = (int)source[i];
       sourceLetters[index]++;
   }

   for (int i = 0; i < (int) target.size(); ++i){
       int index = (int)target[i];
       targetLetters[index]++;
   }

   for(int i = 0 ; i < 128; ++i){
       if(sourceLetters[i]!= targetLetters[i]){
           return false;
       }
   }
   return true;


}


int main(){
    string source,target;
    cin>>source>>target;
    for(int i = 0; i < (int)source.size();++i){
        source[i] = tolower(source[i]);
    }
    
    for(int i = 0; i < (int)target.size();++i){
        target[i] = tolower(source[i]);
    }
    
    bool is_permut = is_permutation(source,target);
    if (is_permut){
        cout<<"is permutation"<<endl;
    }
    else{
        cout<<"isnt permutation"<<endl;
    }
    return 0;
}