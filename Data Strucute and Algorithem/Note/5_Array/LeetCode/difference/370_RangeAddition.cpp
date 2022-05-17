/*
    Assume you have an array of length n initialized with all 0's and are given k update operations.
    Each operation is represented as a triplet: [startIndex, endIndex, inc]
    which increments each element of subarray A[startIndex ... endIndex]
    (startIndex and endIndex inclusive) with inc.
    Return the modified array after all k operations were executed.

    Example: 
        Input: length = 5, updates = [[1,3,2],[2,4,3],[0,2,-2]]
        Output: [-2,0,3,5,3]
    
        Explanation:

        Initial state:
        [0,0,0,0,0]

        After applying operation [1,3,2]:
        [0,2,2,2,0]

        After applying operation [2,4,3]:
        [0,2,5,5,3]

        After applying operation [0,2,-2]:
        [-2,0,3,5,3]

    Hint: for loop read the row of matrix and result[i] += result [i-1]
*/
#include <vector>
using namespace std;

class Solution {
    public:
        vector <int> getArray(int length, vector<vector<int>>& updates){
            vector<int> result(length, 0);
            for(vector<int> update: updates){
                int start = update[0];
                int end = update[1];
                int value = update[2];

                result[start] += value;
                if(end+1 < length)
                    result[end+1] -= value;
            }

            for(int i=1; i < length; i++){
                result[i] += result[i-1];
            }

            return result;
        }      
};