#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

string urlify(string text){
    string aux = text;

    int iterator = 0;
    for(int i =0; i < text.size();++i){
        if(text[i]==' '){
            aux[iterator]='%';
            aux[iterator+1]='2';
            aux[iterator+2]='0';
            iterator += 2;
        }
        else{
            aux[iterator]=text[i];
        }
        iterator++;
        if(iterator >= text.size()){
            break;
        }
    }
    return aux;


}


int main(){
    string text("Sr martin Lutero    ");
    //cin>>text;
    //cout<<text.size()<<endl;
    
    string textUrlyfied = urlify(text);
    cout << textUrlyfied<<endl;
    return 0;
}