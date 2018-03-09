//
// Created by bazylip on 09.03.18.
//

#include "Array2d.h"
#include "iostream"

using namespace std;

int main(void){
    int **array = Array2D(10, 10);
    for(int i = 0; i < 10; ++i){
        for(int j = 0; j < 10; ++j){
            cout<<array[i][j]<<" ";
        }
        cout<<endl;
    }

    DeleteArray2D(array, 10, 10);

    return 0;
}
