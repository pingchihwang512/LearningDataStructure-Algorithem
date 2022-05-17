/*
    Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.

    Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

    Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

    Return the minimum integer k such that she can eat all the bananas within h hours.

    ex1.
        Input: piles = [3,6,7,11], h = 8
        Output: 4

    ex2.
        Input: piles = [30,11,23,4,20], h = 5
        Output: 30

    Constraints:
        1 <= piles.length <= 104
        piles.length <= h <= 109
        1 <= piles[i] <= 109

    Hint: 1. Understand the question, find k where k is between min(piles[]) max(piles[])
          2. double ceil (double x);

*/
#include <math.h>
#include <vector>
using namespace std;

// Koko like to eat slowly
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) {
        int low = 1, high = 1000000000, k = 0;
        while (low <= high) {
            k = low + ((high-low) / 2);
            int h = 0;
            for (int i = 0; i < piles.size(); i ++) 
                h += ceil(1.0 * piles[i] / k);
            
            // h > H means Koko did not finish before H, try eat faster (try bigger k)
            if (h > H)
                low = k + 1;

            // h <= H means koko finish before H hour and meet the requirement speed, try smaller k to find min speed.
            else
                high = k - 1;
        }
        return low;
    }
};