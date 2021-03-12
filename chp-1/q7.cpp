#include<iostream>
#include<vector>
using namespace std;

int visited[4][4];

template <typename TwoD>
void rotateMatrix(TwoD &matrix, int size,int line_ini, int col_ini){
    if (visited[line_ini][col_ini]){
        return;
    }
    int number_elements=size*size;
    int line = line_ini;
    int column= col_ini;
    int new_column;
    int new_line;
    int element=matrix[line][column];
    int new_element = 0;
    while(number_elements--){
        new_column = size - 1 -line;
        new_line = column;
        new_element = matrix[new_line][new_column];
        matrix[new_line][new_column] = element;
        visited[new_line][new_column] = 1;
      //Update
       //cout<<new_element<<" "<<new_line<<" "<<new_column<<" "<<endl;
        element = new_element;
        column = new_column;
        line = new_line;
        if(line_ini==line && col_ini==column){
            break;
        }
    }


}


int main(){

int size = 4;
int matrix[4][4];
matrix[0][0]=1;
matrix[0][1]=2;
matrix[0][2]=3;
matrix[0][3]=4;
matrix[1][0]=5;
matrix[1][1]=6;
matrix[1][2]=7;
matrix[1][3]=8;
matrix[2][0]=9;
matrix[2][1]=10;
matrix[2][2]=11;
matrix[2][3]=12;
matrix[3][0]=13;
matrix[3][1]=14;
matrix[3][2]=15;
matrix[3][3]=16;
int a = size/2 +1;
for(int i=0 ; i < size;++i){ 
    for(int j = 0; j<size;++j){
        rotateMatrix(matrix,size,i,j);
    }
    //cout<<endl;
    }

//for(int i=0;i<a;++i)
    
//cout<<"acabou"<<endl;
for(int i=0 ; i < size;++i){ 
    for(int j = 0; j<size;++j){
        cout<<matrix[i][j]<<" ";
    }
    cout<<endl;
    }

}