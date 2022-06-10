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

class Solution {
    // Helper function which returns the number of hours required to consume the piles for given K
    int hoursRequired(const vector<int> &piles, int k)
    {
        int h = 0;
        if(k == 0) return INT_MAX;
        for(int i : piles)
        {
            if(i % k != 0)
            {
                h++;
            }
            h += (i / k);
        }
        return h;
    }
    
public:
    int minEatingSpeed(vector<int>& piles, int H) {
        long long sum = 0;
        int mx = 0;
        for(int i = 0; i < piles.size(); i++)
        {
            sum += piles[i];
            mx = max(mx, piles[i]);
        }
        int l = sum / H, r = mx, ans;
        while(l < r)
        {
            int mid = l + (r - l) / 2;
            int ans = hoursRequired(piles, mid);
			// If hours required is greater than our limit, ignore mid
            if(ans > H)
            {
                l = mid + 1;
            }
            else
            {
                r = mid;
            }
        }
        return r;
    }
};