/*
    There are n flights that are labeled from 1 to n.

    You are given an array of flight bookings bookings, 
    where bookings[i] = [firsti, lasti, seatsi] represents a booking for 
    flights firsti through lasti (inclusive) with seatsi seats reserved for each flight in the range.

    Return an array answer of length n, where answer[i] is the total number of seats reserved for flight i.

    ex1.
        Input: bookings = [[1,2,10],[2,3,20],[2,5,25]], n = 5
        Output: [10,55,45,25,25]
        Explanation:
        Flight labels:        1   2   3   4   5
        Booking 1 reserved:  10  10
        Booking 2 reserved:      20  20
        Booking 3 reserved:      25  25  25  25
        Total seats:         10  55  45  25  25
        Hence, answer = [10,55,45,25,25]
    
    constraints:
        1 <= n <= 2 * 104
        1 <= bookings.length <= 2 * 104
        bookings[i].length == 3
        1 <= firsti <= lasti <= n
        1 <= seatsi <= 104
    
    Hint : for loop read the row of matrix and result[i] += result [i-1]
*/
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> result = vector<int>(n,0);
        
        for(auto v : bookings){
            int begin = v[0];
            int end = v[1];
            int value = v[2];
            result[begin-1] += value;
            
            if(end<n){
                result[end]-=value;
            }
        }
        
        for(int i =1; i<result.size();i++){
            result[i] = result[i] + result[i-1];
        }
        return result;
    }
};