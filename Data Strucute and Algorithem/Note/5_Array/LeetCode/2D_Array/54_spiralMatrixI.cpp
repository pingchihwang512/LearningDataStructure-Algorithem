/*
    Given an m x n matrix, return all elements of the matrix in spiral order.

    ex1. 
        Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
        Output: [1,2,3,6,9,8,7,4,5]

    Constraints:
        m == matrix.length
        n == matrix[i].length
        1 <= m, n <= 10
        -100 <= matrix[i][j] <= 100

    Hint: 2D array element with four corner and one direction
*/

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int left=0,right=m-1,bottom=n-1,top=0;
        int direction=1;
        vector<int> v;
        while(left<=right && top<=bottom)
        {
            // direction 1 is from top left to top right, remove top line 
            if(direction==1)
            {
                for(int j=left;j<=right;j++) v.push_back(matrix[top][j]);
                direction=2;
                top++;
            }
            
            // direction 2 is from top right to bottom right, remove right line
            else if(direction==2)
            {
                for(int i=top;i<=bottom;i++) v.push_back(matrix[i][right]);
                direction=3;
                right--;
            }
            
            // direction 3 is from bottom right to bottom left, remove bottom line
            else if(direction==3)
            {
                for(int j=right;j>=left;j--) v.push_back(matrix[bottom][j]);
                direction=4;
                bottom--;
            }
            
            // direction 4 is from bottom left to top left, remove left line
            else if(direction==4)
            {
                for(int i=bottom;i>=top;i--) v.push_back(matrix[i][left]);
                direction=1;
                left++;
            }
        }
        return v;
        
    }
};