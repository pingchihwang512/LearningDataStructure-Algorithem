/*
    (Class source code belong to youngyangyang04)
    
    Given two integers n and k, return all possible combinations of k numbers out of the range [1, n].
    You may return the answer in any order.

    constrains:
        1 <= n <=20
        1 <= k <= m

    ex1.
        Input: n = 4, k = 2
        Output:
        [
            [2,4],
            [3,4],
            [2,3],
            [1,2],
            [1,3],
            [1,4],
        ]

    ex2.
        Input: n = 1, k = 1
        Output: [[1]]


    Hint : 回溯法解决的问题都可以抽象为树形结构（N叉树）
    
*/
#include <vector>
#include <iostream>
using namespace std;

class Solution1 {
private:
    vector<vector<int>> result; // 存放符合条件结果的集合
    vector<int> path; // 用来存放符合条件结果
    void backtracking(int n, int k, int startIndex) {
        if (path.size() == k) {
            result.push_back(path);
            return;
        }
        for (int i = startIndex; i <= n; i++) {
            path.push_back(i); // 处理节点 
            backtracking(n, k, i + 1); // 递归
            path.pop_back(); // 回溯，撤销处理的节点
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        result.clear(); // 可以不写
        path.clear();   // 可以不写
        backtracking(n, k, 1);
        return result;
    }
};

// Solution that has better time complexity
class Solution2 {
private:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(int n, int k, int startIndex) {
        if (path.size() == k) {
            result.push_back(path);
            return;
        }
        for (int i = startIndex; i <= n - (k - path.size()) + 1; i++) { // 优化的地方
            path.push_back(i); // 处理节点
            backtracking(n, k, i + 1);
            path.pop_back(); // 回溯，撤销处理的节点
        }
    }
public:

    vector<vector<int>> combine(int n, int k) {
        backtracking(n, k, 1);
        return result;
    }
};

int main(){
    Solution1 s1;
    vector<vector<int>> result1;
    result1 = s1.combine(5,3);
    
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