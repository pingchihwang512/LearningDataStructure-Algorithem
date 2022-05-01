/*
    Apr  30
    -Static variable and Recursion
    Treat Static variable like global variable that was in the code section
    however, if
*/
#include <stdio.h>

int fun (int n){
    static int x =0;
    if(n>0){
        x++;
        printf("%d\n",x);
        return fun(n-1)+x;
    }
    printf("%d\n",x);
    return 0;
}

int main(){
    int r;
    r = fun(5);
    printf("%d\n", r);

    r = fun(5);
    printf("%d", r);
    return 0;
}