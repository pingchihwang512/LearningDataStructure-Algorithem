/*
    Given an array nums which consists of non-negative integers and an integer m, you can split the array into m non-empty continuous subarrays.

    Write an algorithm to minimize the largest sum among these m subarrays.

    ex1.
        Input: nums = [7,2,5,10,8], m = 2
        Output: 18
        Explanation:
        There are four ways to split nums into two subarrays.
        The best way is to split it into [7,2,5] and [10,8],
        where the largest sum among the two subarrays is only 18.

    Constraints:
        1 <= nums.length <= 1000
        0 <= nums[i] <= 106
        1 <= m <= min(50, nums.length)
*/
#include<vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int splitArray(vector<int>& nums, int m) {
        int l=0,r=0,n=nums.size();
        for(int i=0;i<n;i++) l=max(l,nums[i]), r+=nums[i];
        
        int mid=0,ans=0;
        while(l<=r){
            mid=l+(r-l)/2;
            int count=0,tempsum=0;
            for(int i=0;i<n;i++){
                if(tempsum+nums[i]<=mid) tempsum+=nums[i];
                else count++,tempsum=nums[i];
            }
            count++; 
            
            if(count<=m) r=mid-1, ans=mid;
            else l=mid+1;
        }  
        return ans;
    }
};