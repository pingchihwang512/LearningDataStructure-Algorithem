/*
    Apr 30
    - Type and pattern of Recursion
    1. Tail Recursion : occurs when function does not perform anything in returning time (Linear Recursion)
    2. Head Recursion : occurs when function does not perform anything in calling time   (Linear Recursion)
    3. Tree Recursion : occurs when function make a recursive call more than once in its recursive case. Time complexity O(2^n) , Space complexity O(n)
    4. Indirect Recursion : occurs when function is called not by itself but by another function that it called, A call B, B then call A
    5. Nested Recursion : occurs when function will pass the parameter as a recursive call
*/

#include<iostream>
using namespace std;

//Example of Tail Recursion
void tailRecursion(int n){
    if(n>0){
        printf("%d",n);
        tailRecursion(n-1); // It is not a tail recursion if tailRecursion(n-1) + n;
    }
}

//Example of Head Recursion
void headRecursion(int n){
    if(n>0){
        headRecursion(n-1);
        printf("%d",n);
    }
}

//Example of Tree Recursion
void treeRecursion(int n){
    if(n>0){
        printf("%d",n);
        treeRecursion(n-1);
        treeRecursion(n-1);
    }
}

//Example of Indirect Recursion
void indirectRecursionB(int n); //funb prototype syntax, otherwise error

void indirectRecursionA(int n){
    if(n>0){
        printf("%d", n);
        indirectRecursionB(n-1);
    }
}

void indirectRecursionB(int n){
    if(n>1){
        printf("%d", n);
        indirectRecursionA(n/2);
    }
}

//Example of Nested Recursion
int nestedRecursion(int n){
    if(n>100){
        //printf("%d ,", n);
        return (n-10);
    }
    return nestedRecursion(nestedRecursion(n+11));
}

int main(){
    tailRecursion(3);
    cout << "\n";
    headRecursion(3);
    cout << "\n";
    treeRecursion(3);
    cout << "\n";
    indirectRecursionA(3);
    cout << "\n";
    int temp = nestedRecursion(3);
    cout << temp << "\n";
}

