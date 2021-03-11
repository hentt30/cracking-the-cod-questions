#include <iostream>
#include <string>
#include <bitset>
using namespace std;

bool is_palindrome_permutation(string text){
    bitset<26> letters;
    for(int i = 0 ; i < (int)text.size(); i++){
        if(text[i]==' '){
            continue;    
        }
        int index = (int) text[i]-'a';
        letters[index] = ~letters[index];
    }

    int number_of_ones = 0;

    for(int i = 0 ; i < 26;i++){
        if(letters[i]&1){
            number_of_ones ++;
        }
        if(number_of_ones > 1){
            return false;
        }
    }
    return true;
}



int main(){
    string text;
    getline(cin, text);
    for (int i = 0 ; i < (int)text.size();++i){
        text[i] = tolower(text[i]);
    }
    bool is_palindrome = is_palindrome_permutation(text);

    if(is_palindrome){
        cout<<"Is an palindrome permutation"<<endl;
    }
    else{
        cout<<"It is not a palindrome permutation"<<endl;
    }

    return 0 ;
} 