/*
    A conveyor belt has packages that must be shipped from one port to another within days days.

    The ith package on the conveyor belt has a weight of weights[i]. Each day, 
    we load the ship with packages on the conveyor belt (in the order given by weights). 
    We may not load more weight than the maximum weight capacity of the ship.

    Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within days days.

    ex1.
        Input: weights = [1,2,3,4,5,6,7,8,9,10], days = 5
        Output: 15
        Explanation: A ship capacity of 15 is the minimum to ship all the packages in 5 days like this:
        1st day: 1, 2, 3, 4, 5
        2nd day: 6, 7
        3rd day: 8
        4th day: 9
        5th day: 10

        Note that the cargo must be shipped in the order given, so using a ship of capacity 14 and splitting the packages into parts 
        like (2, 3, 4, 5), (1, 6, 7), (8), (9), (10) is not allowed.
    
    Constratins:
        1 <= days <= weights.length <= 5 * 104
        1 <= weights[i] <= 500
    
    Hints:
        The left bound is max(A),
        The right bound is sum(A).
*/
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        int left = 0, right = 0;
        for (int w: weights){
            left = max(left, w);
            right += w;
        }
        while (left < right) {
            int mid = left+(right-left)/ 2, need = 1, cur = 0;
            for (int w: weights){
                //Meet today's capacity, do the job tomorrow 
                if(cur+w>mid){
                    need += 1;
                    cur = 0;
                }
                cur += w;   
            }
            // (need > D) means the ship takes too many days to finish shipping, increase the ship capacity)( move right)
            if(need>D) left = mid +1;
            
            // (need <= D) means ship finished the job in the requirement time, however we are not sure it is the least wieght capacity. 
            //             decrease the ship capacity to check (move left) 
            else right = mid;
        }
        return left;
    }
};