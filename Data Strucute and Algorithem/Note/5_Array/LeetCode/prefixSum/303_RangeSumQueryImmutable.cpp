/*
    Given an integer array nums, handle multiple queries of the following type:

        1. Calculate the sum of the elements of nums between indices left and right inclusive where left <= right.
    
    Implement the NumArray class:
        1. NumArray(int[] nums) Initializes the object with the integer array nums.
        
        2. int sumRange(int left, int right) 
        Returns the sum of the elements of nums between indices left and right inclusive (i.e. nums[left] + nums[left + 1] + ... + nums[right]).
    
    ex1.
    Input
    ["NumArray", "sumRange", "sumRange", "sumRange"]
    [[[-2, 0, 3, -5, 2, -1]], [0, 2], [2, 5], [0, 5]]
    Output
    [null, 1, -1, -3]

    Explanation
    NumArray numArray = new NumArray([-2, 0, 3, -5, 2, -1]);
    numArray.sumRange(0, 2); // return (-2) + 0 + 3 = 1
    numArray.sumRange(2, 5); // return 3 + (-5) + 2 + (-1) = -1
    numArray.sumRange(0, 5); // return (-2) + 0 + 3 + (-5) + 2 + (-1) = -3

    Constraints:
        1 <= nums.length <= 104
        -105 <= nums[i] <= 105
        0 <= left <= right < nums.length
        At most 104 calls will be made to sumRange.

    Hint: Create a accu array that store the sum using for loop first,later when we call sumRange function, it only do the algorithem logic
*/
#include <vector>
using namespace std;

class NumArray {
private:
    vector<int>accu; 
public:
    NumArray(vector<int>& nums) {
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum = sum + nums[i];
            accu.push_back(sum);
        }
    }
    
    int sumRange(int left, int right) {
        int result = 0;
        if(left == 0 ){
            result = accu[right];
            return result;
        }else{
            result = accu[right] - accu [ left - 1];
            return result;
        }
    }
};