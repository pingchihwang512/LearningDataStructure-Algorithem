/*
    Introduction to array
    - Declaration and initialization
    - Basic output
    - Static vs Dynamic Array  
        - Declaration and initialization
        - Free space for Dynamic Array
        - Change size of Dynamic Array (Static array size is fixed once declare)
        - Notice that we cannot accessed the size of dynamic array compare to Static array, so if you need to know a dynamic array's length, you have to store it separately
*/

#include <stdio.h>
#include <stdlib.h> //Defined in header<stdlib.h> for malloc

int main(){
    int A[5];                   // {0,0,0,0,-272632584} all garbage cause no initialize
    int B[5]={1,2,3,4,5};       // {1,2,3,4,5}
    int C[10]={2,4,6};          // {2,4,6,0,0,0,0,0,0,0,0,0,0}
    int D[5]={0};               // {0,0,0,0,0}
    int E[]={1,2,3,4,5,6};      // {1,2,3,4,5,6}

    for(int i = 0;i<5;i++)
        printf("%u \n", &B[i]); // Output of address of array B[index]  

    //How to create an array using heap memory?
    int *dynamicArrayInCPP, *dynamicArrayInC;
    dynamicArrayInCPP = new int[5];                    // Create a pointer point to an array in heap memory using c++
    dynamicArrayInC = (int*)malloc(5*sizeof(int));     // Create a pointer point to an array in heap memory using c

    //Example of initializing dynamic array and output its element
    for(int i = 0;i<5;i++){
        dynamicArrayInCPP[i] = i+1;
        printf("%u \n", dynamicArrayInCPP[i]); 
    }

    //Let's say I want to move an array size of 5 to array size of 10
    //I can change the pointer of array size of 5 to array size of 10

    int *dynamicArrayInCPP1 = new int[10];
    for(int i=0;i<5;i++){
        dynamicArrayInCPP1[i] = dynamicArrayInCPP[i];
    }

    //Remember we need to treat heap memory like resource, so everytime we use it, we need to manually free its space
    delete[]dynamicArrayInCPP;                          // Syntax to free space of array using c++
    dynamicArrayInCPP=NULL;                            // Set unused pointer to null
    free(dynamicArrayInC);                             // Syntax to free space of array using c
}