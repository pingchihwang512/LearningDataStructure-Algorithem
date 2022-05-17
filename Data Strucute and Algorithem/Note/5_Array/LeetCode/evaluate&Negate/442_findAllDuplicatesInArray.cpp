/*
    Given an integer array nums of length n where all the integers of nums are in the range [1, n] and each integer appears once or twice, 
    return an array of all the integers that appears twice.

    You must write an algorithm that runs in O(n) time and uses only constant extra space.

    ex1.
        Input: nums = [4,3,2,7,8,2,3,1]
        Output: [2,3]

    Constraints:
        n == nums.length
        1 <= n <= 105
        1 <= nums[i] <= n
        Each element in nums appears once or twice.
    
    Hint: 1. "Mark as positive and negative" 
          2. Knowing that "Given an array nums of n integers where nums[i] is in the range [1, n] "
            -> if this element is positive means double negation had happened
*/
#include<vector>
#include<stdlib.h>
using namespace std;

class Solution {
   
public:

    vector<int> findDuplicates(vector<int>& n)
    {
        vector<int> duplicates;
        
        for(int i=0;i<n.size();i++)
        { 
            // evaluate index of selected element if array would have been sorted..
            int indexOfElem = abs(n[i]) - 1;
            
            // negate the element
            n[indexOfElem] = - n[indexOfElem];
            
            // if this element is positive means double negation had happened which 
            // means we editied this element twice.
            if(n[indexOfElem]>0)
                duplicates.push_back(indexOfElem+1);           
        }
        return duplicates;
    }
};