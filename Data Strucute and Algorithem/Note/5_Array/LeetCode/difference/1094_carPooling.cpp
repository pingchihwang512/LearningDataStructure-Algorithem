/*
    There is a car with capacity empty seats. The vehicle only drives east (i.e., it cannot turn around and drive west).

    You are given the integer capacity and an array trips where trips[i] = [numPassengersi, fromi, toi] 
    indicates that the ith trip has numPassengersi passengers and the locations to pick them up and drop them off are fromi and toi respectively. 
    The locations are given as the number of kilometers due east from the car's initial location.

    Return true if it is possible to pick up and drop off all passengers for all the given trips, or false otherwise.

    ex1.
        Input: trips = [[2,1,5],[3,3,7]], capacity = 4
        Output: false
    ex2.
        Input: trips = [[2,1,5],[3,3,7]], capacity = 5
        Output: true
    
    Constraints:
        1 <= trips.length <= 1000
        trips[i].length == 3
        1 <= numPassengersi <= 100
        0 <= fromi < toi <= 1000
        1 <= capacity <= 105
    
    Hint : for loop read the row of matrix and result[i] += result [i-1]
*/
#include<vector>
using namespace std;

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> temp = vector<int>(1000,0);
        bool ans = true;
        
        for(auto v: trips){
            int value = v[0];
            int start = v[1];
            int end = v[2];
            
            temp[start] += value;
            
            if(end+1<1000){
                temp[end] -= value;
            }
        }
        
        for(int i = 0; i < temp.size()-1;i++){
            if(i>0){
                temp[i] = temp[i] + temp[i-1];  
            }
            
            if(temp[i]>capacity){
                ans = false;
                return ans;
            } 
        }
        return ans;
    }
};