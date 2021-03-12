#include<iostream>

using namespace std;


int main(){
    int nRows = 2;
    int nColumns = 3;
    int matrix[2][3];
    matrix[0][0]=1;
    matrix[0][1]=2;
    matrix[0][2]=3;
    matrix[1][0]=4;
    matrix[1][1]=0;
    matrix[1][2]=5;
    int rowHasZero=false;
    int columnHasZero=false;

    for(int i = 0 ; i < nRows;++i){
        if(matrix[i][0]==0)
            rowHasZero=true;
    }

    for(int i = 1; i < nColumns; ++i){
        if(matrix[0][i]==0)
            columnHasZero=true;
    }

    for(int i = 1; i < nRows;++i){
        for(int j = 1; j < nColumns;++j){
            if(matrix[i][j]==0){
                matrix[0][j]=0;
                matrix[i][0]=0;
            }
        }
    }

    // Columns to zero
    for(int i =1;i<nColumns;++i){
        if(matrix[0][i]==0){
            for(int j = 0; j < nRows;++j)
                matrix[j][i]=0;
        }
    }

    // Rows to zero
    for(int i =1;i<nRows;++i){
        if(matrix[i][0]==0){
            for(int j = 0; j < nColumns;++j)
                matrix[i][j]=0;
        }
    }

    // row 0  to zero
    if(rowHasZero){
        for(int i = 0; i < nColumns ; ++i)
            matrix[0][i] =0 ;

    }

    if(columnHasZero){
        for(int i = 0; i < nRows ; ++i)
            matrix[i][0] =0 ;
    }
//cout<<"acabou"<<endl;
for(int i=0 ; i < nRows;++i){ 
    for(int j = 0; j<nColumns;++j){
        cout<<matrix[i][j]<<" ";
    }
    cout<<endl;
    }
    return 0 ;

}