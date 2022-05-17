/*
    Given an unsorted integer array nums, return the smallest missing positive integer.

    You must implement an algorithm that runs in O(n) time and uses constant extra space.

    ex1.
        Input: nums = [1,2,0]
        Output: 3
    
    ex2.
        Input: nums = [3,4,-1,1]
        Output: 2
    
    constraints:
        1 <= nums.length <= 5 * 105
        -2^31 <= nums[i] <= 2^31 - 1
    
    Hint: 1. Treat original array as a boolean array that tells whether the ans index exist or not
          2. Knowing that we are trying to find the smallest missing "Positive integer"
          3. Treat each element's value as possible array index, if possible, set it to negative.
*/

#include <stdlib.h>

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        
        // Avoid element with negative value or 0
        for (int i = 0; i < n; i++) 
            if (nums[i] <= 0) 
                nums[i] = n + 1;
        
        // Main Logic: Treat each element's value as possible array index, if possible, set it to negative 
        for (int i = 0; i < n; i++) 
            if (abs(nums[i]) <= n && nums[abs(nums[i]) - 1] > 0) 
                nums[abs(nums[i]) - 1] *= -1;
        
        // loop through all the integer and find positive value, it tells us the missing positive index, return index +1 
        for (int i = 0; i < n; i++) 
            if (nums[i] > 0) 
                return i + 1;
        
        // Loop didn't find positive means all integer are not missing
        return n + 1;
    }
};