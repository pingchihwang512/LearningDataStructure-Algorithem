/* 
    (All class source code belong to youngyangyang04)

    Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums. If target exists, then return its index. Otherwise, return -1.

    You must write an algorithm with O(log n) runtime complexity.

    ex1.
        Input: nums = [-1,0,3,5,9,12], target = 9
        Output: 4
        Explanation: 9 exists in nums and its index is 4
    
    Constraints:
        1 <= nums.length <= 10^4
        -10^4 < nums[i], target < 10^4
        All the integers in nums are unique.
        nums is sorted in ascending order.
*/

#include <vector>
using namespace std;

class Solution{
    public:
    int search(vector<int>& nums, int target){
        int min, max;
        min = 0;
        max = nums.size()-1;
        while(min<=max){
            int mid = min + ((max - min) / 2);

            if (nums[mid] > target) {
                max = mid - 1; 
            } else if (nums[mid] < target) {
                min = mid + 1; 
            } else { 
                return mid; 
            }
        }
        return -1;
    }
};