/*
    Given an array nums of n integers where nums[i] is in the range [1, n],
    return an array of all the integers in the range [1, n] that do not appear in nums.

    ex1. 
        Input: nums = [4,3,2,7,8,2,3,1]
        Output: [5,6]
    
    Constraints:
        n == nums.length
        1 <= n <= 105
        1 <= nums[i] <= n


    Hint: 1. "Mark as positive and negative" 
          2. Knowing that "Given an array nums of n integers where nums[i] is in the range [1, n] "
            -> Knowing that element value will be positive, we create another array that store negative value as exsit element value  
*/
#include <vector>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        
        for (int i = 0; i < nums.size(); i++) {
            int indexOfElem = abs(nums[i]) - 1;
            nums[indexOfElem] = -abs(nums[indexOfElem]);
        }
        
        vector<int> res;
        for (int i = 0; i < nums.size(); i++)
            if (nums[i] > 0) res.push_back(i+1);
        
        return res;
    }
};