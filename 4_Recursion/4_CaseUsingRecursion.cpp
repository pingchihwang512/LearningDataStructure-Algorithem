/*
    Apr 30
    - This program shows the use case of recursion
    1. Sum of Natural Number using recursion
    2. Factorial using recursion
    3. Power using recursion
    4. Taylor Series using recursion
    5. Taylor Series using Horner's Rule
    6. Taylor Series iterative
    7. Fibonacci Series using iterative
    8. Fibonacci Series using recursion
    9. Fibonacci Series using Memorization
    10. nCr using recursion
    11. Tower of Hanoi
*/

#include<stdio.h>

//This is example of Sum of Natural Number using recursion
int sum(int n){
    if(n==0)
        return 0;
    return sum(n-1)+n;
}

//This is an example of Factorial using recursion, Factorial example is n! = n*(n-1)*(n-2)...*2*1
int fact(int n){
    if(n==0)
        return 1;
    else
        return fact(n-1)*n;
}

//This is an example of Power using Recursion, m^n
int powerRecursion(int m, int n){
    if(n==0)
        return 1;
    return powerRecursion(m,n-1)*m;
}

//This is an example of Power using Recursion, (m*m)^n/2
int powerRecursion1(int m, int n){
    if(n==0)
        return 1;
    if(n%2==0)
        return powerRecursion1(m*m, n/2);
    return m * powerRecursion1(m*m, (n-1)/2);
}

//This is an example of Taylor Series using Recursion, e^x
double e(int x, int n){
    static double p=1,f=1;
    double r;

    if(n==0)
        return 1;
    r = e(x,n-1);
    p = p * x;
    f = f * n;
    return r+p/f;
}

//This is an example of Taylor Series using Horner's Rule
double eHonerRule(int x, int n){
    static double s;
    if(n==0)
        return s;
    s = 1 + x*s/n;
    return eHonerRule(x,n-1);
}

//This is an example of Taylor Series using Iterative
double eIterative(int x, int n){
    double s=1;
    int i;
    double num = 1;
    double den = 1;

    for(i = 1; i<=n; i++){
        num*=x;
        den*=i;
        s+=num/den;
    }
    return s;
}

//This is an example of Fibonacci Series using Iterative
int fibIterative(int n){
    int t0=0, t1=1, s=0, i;
    if(n<=1)    
        return n;
    for(i=2;i<=n;i++){
        s=t0+t1;
        t0=t1;
        t1=s;
    }
    return s;
}

//This is an example of Fibonacci Series using Recursion
int fibRecursion(int n){
    if(n<=1) return n;
    return fibRecursion(n-2)+fibRecursion(n-1);
}

//This is an example of Fibonacci Series using Memorization
int F[10];
int fibMemorization(int n){
    if(n<=1){
        F[n]=n;
        return n;
    }else{
        if(F[n-2] == -1)
            F[n-2] = fibMemorization(n-2);
        if(F[n-1] == -1)
            F[n-1] = fibMemorization(n-1);
        F[n] = F[n-2] + F[n-1];
        return F[n-2] + F[n-1];
    }
}

//This is an example of nCr (combination formula) using recursion
int NCR(int n, int r){
    if(n==r || r==0)
        return 1;
    return NCR(n-1,r-1)+NCR(n-1,r);
}

//This is an example of Tower of Hanoi using recursion
void TOH(int n, int A, int B, int C){
    if(n>0){
        TOH(n-1,A,C,B);
        printf("(%d,%d)\n" , A, C);
        TOH(n-1,B,A,C);
    }
}

int main(){
    int r;

    r = sum(5);
    printf("%d \n", r);
    
    r = fact(5);
    printf("%d \n", r);

    r = powerRecursion(9,3);
    printf("%d \n", r);

    r = powerRecursion1(9,3);
    printf("%d \n", r);

    printf("%lf \n", e(2,10));

    printf("%lf \n", eHonerRule(2,10));

    printf("%lf \n", eIterative(2,10));

    printf("%d \n", fibIterative(6));

    printf("%d \n", fibRecursion(6));

    int i;
    for(i = 0; i < 10; i++)
        F[i] = -1;
    printf("%d \n", fibMemorization(6));

    printf("%d \n", NCR(5,2));

    TOH(3,1,2,3);
    return 0;
}