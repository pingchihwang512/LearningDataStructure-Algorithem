/*
    1. Array in Compilers               Addr(A[i]) = L0 + ( i - 1 ) * w
    
    For int A[m][n]
    2. Row Formula for 2D array         Addr(A[i][j]) = L0 + [i * n + j] * w
    3. Column Formula for 2D array      Addr(A[i][j]) = L0 + [J * m + i] * w 
    
    For int A[L][m][n]
    4. Row Formula for 3D array         Addr(A[i][j][k]) = L0 + (i * m * n + j * n + k ) * w                            //From right to left
    5. Column Formula for 3D array      Addr(A[i][j][k]) = L0 + (k * L * m + j * L + i ) * w                            //From left to right
    
    6. Formula for nD array             Addr() = L0 + [i1*d2*d3*d4...*dn + i2*d2*d3*..dn + i(n-1)*dn + dn] * w

    quiz1.
    What is the output of the following C code? Assume that the address of x is 2000 (in decimal) and an integer requires four bytes of memory.

        int main( ){
            unsigned int x[4] [3] ={{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, (10, 11, 12}}; 

            printf("%u,%u, %u", x+3, *(x+3),*(x+2)+3);
        }

    Hint 1. x+a : address of move a row from origin
         2. *(x+a) : address of first element of move a row
         3. *(x+a)+b : address of first element of move a row, move move b column
         4. *(*(x+a)+b) : value of first element of move a row, move move b column
*/  
