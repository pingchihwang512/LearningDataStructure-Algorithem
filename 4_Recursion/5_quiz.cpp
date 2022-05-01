/*
   Q1: What is the return value of f(p, p), if the value of p is initialised to 5 before the call? 
   Note that the first parameter is passed by reference, whereas the second parameter is passed by value.  

    int f (int &x, int c){
        c = c — 1; 

        if (c = = 0) return 1; 

        x = x + 1; 

        return f(x,c) * x;
    }

    Hint: Understand the difference between passed by reference, whereas the second parameter is passed by value
          1.What is pointer?                    Create a pointer point to the variable address
          2.What is the passed by reference?    A method of passing the address of an argument " in the calling function" to a corresponding parameter in the called function
*/

#include <stdio.h>
int q1(int &x, int c){
    c = c - 1; 

    if (c == 0) return 1; 

    x = x + 1; 

    return q1(x,c) * x;
}

int main (){
    int p =5;
    printf("%d", q1(p,p));
    return 0;
}