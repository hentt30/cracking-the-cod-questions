#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

bool has_rep_char(string text){
    if(text.size() > 128){
        // Number of codes in ASCII characters
        return true;
    }
    vector<bool> codes(128,false);

    for (int i =0 ; i< text.size();++i){

        int index = (int) text[i];
      
        if (codes[index]){
            return true;
        }
        else{
            codes[index]=true;
        }

    }
    return false;

}


int main(){
    string text;
    cin>>text;
    bool is_rep = has_rep_char(text);
    if (is_rep){
        cout<<"has repeated characteres"<<endl;
    }
    else{
        cout<<"it hasnt repeated characteres"<<endl;
    }
    return 0;
}