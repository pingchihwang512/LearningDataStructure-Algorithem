/*
    Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.

    ex1.
        Input: n = 3
        Output: [[1,2,3],[8,9,4],[7,6,5]]
    
    ex2.
        Input: n = 1
        Output: [[1]]
    
    Constraints
        1 <= n <= 20

    Hint: 2D array element with four corner and one direction
*/

#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int t = 0, l = 0, b = n - 1, r = n - 1;
        int num = 1;
        vector<vector<int>> result (n, vector<int>(n));
        
        int direction = 1;
        
        while((t<=b)&&(l<=r)){
            // d1 : top left to top right, remove top line
            if(direction == 1){
                for(int j = l ; j <= r; j++){
                    result[t][j] = num++;
                }
                direction = 2;
                t++;
            }
            
            // d2 : top right to bottom right, remove right line
            else if(direction == 2){
                for(int i = t; i <= b; i++){
                    result[i][r] = num++;
                } 
                direction = 3;
                r--;
            }
            
            // d3 : bottom right to bottom left, remove bottom line
            else if(direction == 3){
                for(int j = r; j>=l;j--){
                    result[b][j] = num++;
                }
                direction = 4;
                b--;
            }
            
            // d4 : bottom left to top left, remove left line
            else if(direction == 4){
                for(int i = b ; i>=t; i--){
                    result[i][l] = num++;
                }
                direction = 1;
                l++;
            }
        }
        return result;
    }
};