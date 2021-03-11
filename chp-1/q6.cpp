#include<iostream>

using namespace std;

string compress(string source){
    string aux;
    char letter = source[0];
    int count_letter=0;
    for(int i = 0 ; i < (int) source.size();++i){
        count_letter++;
        if((i+1 < (int)source.size() && source[i]!=source[i+1])|| i+1 == (int) source.size()){
            aux.push_back(letter);
            aux+=to_string(count_letter);
            letter= source[i+1];
            count_letter=0;
        }
        
    }
    if (aux.size()>source.size())
        return source;
    return aux;
}

int main(){

    string source;
    getline(cin,source);
    string aux = compress(source);
    cout<<aux<<endl;
    return 0;
}