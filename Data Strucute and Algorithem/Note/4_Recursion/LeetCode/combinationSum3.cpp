/*
    (Class source code belong to youngyangyang04)
    
    Find all valid combinations of k numbers that sum up to n such that the following conditions are true:
        Only numbers 1 through 9 are used.
        Each number is used at most once.
    Return a list of all possible valid combinations. The list must not contain the same combination twice, and the combinations may be returned in any order.

    ex1.
        Input: k = 3, n = 7
        Output: [[1,2,4]]
        Explanation:
        1 + 2 + 4 = 7
        There are no other valid combinations.

    ex2.
        Input: k = 3, n = 9
        Output: [[1,2,6],[1,3,5],[2,3,4]]
        Explanation:
        1 + 2 + 6 = 9
        1 + 3 + 5 = 9
        2 + 3 + 4 = 9
        There are no other valid combinations.

    constraints: 
        2 <= k <= 9
        1 <= n <= 60
*/

#include<vector>
#include<iostream>
using namespace std;

class Solution1{
    private:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(int n, int k, int sum, int startIndex){
        if(path.size()==k)
            if(sum==n){
                result.push_back(path);
                return;
            }  

        for(int i = startIndex; i<=9;i++){
            sum += i;
            path.push_back(i);
            backtracking(n,k,sum,i+1);
            sum -= i;
            path.pop_back();
        }
    }

    public:
    vector<vector<int>> combinationSum3(int k, int n){
        backtracking(n, k, 0, 1);
        return result;
    }
};

class Solution2 {
private:
    vector<vector<int>> result; // 存放结果集
    vector<int> path; // 符合条件的结果
    void backtracking(int targetSum, int k, int sum, int startIndex) {
        if (sum > targetSum) { // 剪枝操作
            return; // 如果path.size() == k 但sum != targetSum 直接返回
        }
        if (path.size() == k) {
            if (sum == targetSum) result.push_back(path);
            return;
        }
        for (int i = startIndex; i <= 9 - (k - path.size()) + 1; i++) { // 剪枝
            sum += i; // 处理
            path.push_back(i); // 处理
            backtracking(targetSum, k, sum, i + 1); // 注意i+1调整startIndex
            sum -= i; // 回溯
            path.pop_back(); // 回溯
        }
    }

public:
    vector<vector<int>> combinationSum3(int k, int n) {
        result.clear(); // 可以不加
        path.clear();   // 可以不加
        backtracking(n, k, 0, 1);
        return result;
    }
};

int main(){
    Solution1 s1;
    vector<vector<int>> result1;
    result1 = s1.combinationSum3(3,7);
    
    //Print 2D vector
    for(int i = 0 ; i <result1.size(); i++)
    {
        for (int j = 0; j < result1.at(i).size(); j++)
        {
           cout << result1[i][j] << ",";
        }
        cout << endl;
    }
}