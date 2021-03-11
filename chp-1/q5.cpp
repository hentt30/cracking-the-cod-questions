#include<iostream>
#include<string>

using namespace std;

bool is_one_edit_away(string source,string target){

    int source_size = source.size();
    int target_size = target.size();
    if( 1<(int)abs(source_size-target_size) )
        return false;
    if(source_size == target_size){
        int differences = 0;

        for(int i = 0 ; i < (int) source_size;++i){
            if(source[i]!=target[i]){
                differences++;
            }
        }
        if(differences>1)
            return false;
     
    }
    else{
        int iSource = 0;
        int iTarget = 0;
        while(iSource <source_size && iTarget < target_size){

            if(source[iSource]==target[iTarget]){
                iSource++;
                iTarget++;
            }
            else if(source_size>target_size){
                iSource++;
            }else{
                iTarget++;
            }

        }
        if(iSource == iTarget){
            return true;
        }
        if(iSource!=(int)source_size|| iTarget!=(int)target_size){
            return false;
        }
    }

    return true;

}


int main(){
    string source,target;
    getline(cin,source);
    getline(cin,target);
    bool is_one_edit = is_one_edit_away(source,target);
    if(is_one_edit){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
    return 0 ;
}