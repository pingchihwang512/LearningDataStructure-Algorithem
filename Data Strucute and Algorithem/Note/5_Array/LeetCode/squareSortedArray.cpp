/*
    Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.

    ex1.
        Input: nums = [-4,-1,0,3,10]
        Output: [0,1,9,16,100]
        Explanation: After squaring, the array becomes [16,1,0,9,100].
        After sorting, it becomes [0,1,9,16,100].

    Constraints:
        1 <= nums.length <= 104
        -104 <= nums[i] <= 104
        nums is sorted in non-decreasing order.

    Hint: 
        For the "sorted array" with elements can be integer, 
        we know that the max number of square elements will be either the most left index or the most right index.
        Two pointer  
*/
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> result(nums.size(), 0);;
        int left = 0;
        int right = nums.size()-1;
        for(int i = nums.size()-1; i >= 0; i--){
            if(nums[left]*nums[left]<nums[right]*nums[right]){
                result[i] = nums[right]*nums[right];
                right--;
            }else{
                result[i] = nums[left]*nums[left];
                left++;
            }
        }
        return result;
    }
};