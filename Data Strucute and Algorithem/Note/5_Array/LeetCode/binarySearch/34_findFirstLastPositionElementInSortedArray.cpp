/*
    Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

    If target is not found in the array, return [-1, -1].

    You must write an algorithm with O(log n) runtime complexity.

    ex1.
        Input: nums = [5,7,7,8,8,10], target = 8
        Output: [3,4]
    
    Constraints:
        0 <= nums.length <= 105
        -109 <= nums[i] <= 109
        nums is a non-decreasing array.
        -109 <= target <= 109
    
    Hint: Case when [5,8,8,8,8,8,10] using binary search to search mid to left and mid to right
*/
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& a, int target) {
        int left = 0, right = a.size()-1;
        vector<int> ans(2, -1);

        // Bineary Search from middle to left and find the left boundary
        while(left <= right){
            int mid = left + (right-left)/2;
            if(a[mid] < target)
                left = mid+1;
            else if(a[mid] > target)
                right = mid-1;
            else{
                if(mid == left || a[mid] != a[mid-1]){
                    ans[0] = mid;
                    break;
                }
                else{
                    right = mid-1;
                    ans[0] = mid-1;
                }
            }
        }

        // Bineary Search from middle to right and find the right boundary
        left = 0, right = a.size()-1;
        while(left <= right){
            int mid = left + (right-left)/2;
            if(a[mid] < target)
                left = mid+1;
            else if(a[mid] > target)
                right = mid-1;
            else{
                if(mid == right || a[mid] != a[mid+1]){
                    ans[1] = mid;
                    break;
                }
                else{
                    left = mid+1;
                    ans[1] = mid+1;
                }
            }
        }
        return ans; 
    }
};