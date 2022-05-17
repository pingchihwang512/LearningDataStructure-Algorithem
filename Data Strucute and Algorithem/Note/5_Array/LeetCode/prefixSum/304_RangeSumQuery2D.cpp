/*
    Given a 2D matrix matrix, handle multiple queries of the following type:
        1. Calculate the sum of the elements of matrix inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).
    Implement the NumMatrix class:
        1. NumMatrix(int[][] matrix) Initializes the object with the integer matrix matrix.
        2. int sumRegion(int row1, int col1, int row2, int col2) 
        Returns the sum of the elements of matrix inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).

    Input
    ["NumMatrix", "sumRegion", "sumRegion", "sumRegion"]
    [[[[3, 0, 1, 4, 2], [5, 6, 3, 2, 1], [1, 2, 0, 1, 5], [4, 1, 0, 1, 7], [1, 0, 3, 0, 5]]], [2, 1, 4, 3], [1, 1, 2, 2], [1, 2, 2, 4]]
    Output
    [null, 8, 11, 12]

    Explanation
    NumMatrix numMatrix = new NumMatrix([[3, 0, 1, 4, 2], [5, 6, 3, 2, 1], [1, 2, 0, 1, 5], [4, 1, 0, 1, 7], [1, 0, 3, 0, 5]]);
    numMatrix.sumRegion(2, 1, 4, 3); // return 8 (i.e sum of the red rectangle)
    numMatrix.sumRegion(1, 1, 2, 2); // return 11 (i.e sum of the green rectangle)
    numMatrix.sumRegion(1, 2, 2, 4); // return 12 (i.e sum of the blue rectangle)

    Constraints:
        m == matrix.length
        n == matrix[i].length
        1 <= m, n <= 200
        -105 <= matrix[i][j] <= 105
        0 <= row1 <= row2 < m
        0 <= col1 <= col2 < n
        At most 104 calls will be made to sumRegion.

    Hint: Create a 2D accu array that store the sum using for loop first,later when we call sumRange function, it only do the algorithem logic
          Sum(ABCD)=Sum(OD)−Sum(OB)−Sum(OC)+Sum(OA)
*/
#include <vector>
using namespace std;

class NumMatrix {
private:
    vector<vector<int>> accu;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int ylen = matrix.size()+1, xlen = matrix[0].size()+1;
        accu = vector<vector<int>>(ylen,vector<int>(xlen,0));
        for(int i = 1; i <ylen;i++){
            for(int j = 1; j <xlen; j++){
                accu[i][j]=matrix[i-1][j-1]+ accu[i-1][j]+accu[i][j-1]-accu[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return (accu[row2+1][col2+1] - accu[row2+1][col1] - accu[row1][col2+1] + accu[row1][col1]);
    }
};