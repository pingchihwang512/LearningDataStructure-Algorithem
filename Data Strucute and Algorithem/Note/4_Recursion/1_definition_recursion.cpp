/* 
    April_29

    -Using Bash to call cpp file
        Compile         - g++ <name of file>.cpp -o <name of file>
        Run             - ./<name of file>

    -Introduction to resursion
    A function is called recursion function if it calls itself
    It contains (in stack)
        calling phase   - ascendency
        returning phase - descendency 
    
    Output should be a3a2a1ab1b2b3b
    
    Space Complexity O(n)
    Time Complexity O(n)

    Most important part of recursion is think mathematically  
*/

#include <iostream>
using namespace std;

void func1(int n){
    cout << "a";
    if(n>0){
        cout << n;  
        func1(n-1);
        cout << n;  
    }
    cout << "b";
}

int main(){
    int n = 3;
    func1(n);
}