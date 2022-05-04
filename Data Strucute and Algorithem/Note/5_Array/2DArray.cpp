/*
    Introduction to 2D Array    [row][column]

        - Create 2D Array in stack memory
            - Declare a 2D array in stack memory
        - Create 2D Array in heap memory
            - Create an array of pointers in stack memory and each of pointer points to a array in heap memory 
            - Create a pointer in stack memory points to a array in heap memory and each index of array stores an array
*/

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

class pratice2DArrayInCPP {
    private:
        int row = 0, col = 0;   //Set default 0 for using logic validation later
        int **array;     
        int *arry[];       
        
        void declarization1(){
            if((row == 0) && (col == 0)){
                cout << "Error!";
            }else{
                array = new int * [row]; 

                for(int i = 0; i < row; i++ ){
                    array[i] = new int[col]; 
                }
            }
        }

        void declarization2(){
            if((row == 0) && (col == 0)){
                cout << "Error!";
            }else{
                for(int i = 0; i < row; i++){
                    arry[i] = new int [col]; 
                }
            }
        }

    public:
        void promptSize(){
            cout << "Number of Rows:" << endl;
            cin >> row;
            cout << "Number of Columns:" << endl;
            cin >> col;
        }

        void display1(){
            cout << "Here is your 2D Array:" << endl;
            declarization1();
            for (int i = 0; i < row; i++) {
                for (int j = 0; j < col; j++) {
                cout << &array[i][j] << " , ";
                }
                cout << endl;
            }
        }

        void display2(){
            cout << "Here is your 2D Array:" << endl;
            declarization2();
            for (int i = 0; i < row; i++) {
                for (int j = 0; j < col; j++) {
                cout << &arry[i][j] << " , ";
                }
                cout << endl;
            }            
        }
};

int main(){
    int staticArray[3][4]={{1,2,3,4},{2,3,4,5},{3,4,5,6}};

    int *dynamicArray1[3];
    dynamicArray1[0]=(int *)malloc(4*sizeof(int));
    dynamicArray1[1]=(int *)malloc(4*sizeof(int));
    dynamicArray1[2]=(int *)malloc(4*sizeof(int));

    int **dynamicArray2;                        //Create a pointer to a pointer variable
    dynamicArray2=(int **)malloc(3*sizeof(int *));
    dynamicArray2[0] = (int *)malloc(4*sizeof(int));
    dynamicArray2[1] = (int *)malloc(4*sizeof(int));
    dynamicArray2[2] = (int *)malloc(4*sizeof(int));

    // Display element of 2 D Array using nested for loop
    for(int i = 0; i<3;i++){
        for(int j = 0; j<4;j++){
            printf("%d ", staticArray[i][j]);   // Change dynamicArray1[i][j] or dynamicArray2[i][j] if you want to check the elemtnets of it
        }
        printf("\n");
    }

    // Display 2D array element using C++
    pratice2DArrayInCPP a1;
    a1.promptSize();
    a1.display2();
}