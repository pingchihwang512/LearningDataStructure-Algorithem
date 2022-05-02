/*
    (Class source code belong to youngyangyang04)
    
    Given a string containing digits from 2-9 inclusive, 
    return all possible letter combinations that the number could represent. 
    Return the answer in any order.
    A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

    ex1.    Input: digits = "23"
            Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
    ex2.    Input: digits = ""
            Output: []
    ex3.    Input: digits = "2"
            Output: ["a","b","c"]

    Constraints:
        0 <= digits.length <= 4
        digits[i] is a digit in the range ['2', '9'].

    issue: 
        1. How does number and character reflect
        2. Number 1, *, # doesn't reflect
        3. cannot use basic for loop brute force
*/
#include<string>
#include<iostream>
#include<vector>
using namespace std;

class Solution{
    private:
        const string letterMap[10] = {
            "", // 0
            "", // 1
            "abc", // 2
            "def", // 3
            "ghi", // 4
            "jkl", // 5
            "mno", // 6
            "pqrs", // 7
            "tuv", // 8
            "wxyz", // 9
        };
    public:
    vector<string> result;
    string s;
    void backtracking(const string& digits, int index) {
        if (index == digits.size()) {
            result.push_back(s);
            return;
        }
        int digit = digits[index] - '0';        // 将index指向的数字转为int
        string letters = letterMap[digit];      // 取数字对应的字符集
        for (int i = 0; i < letters.size(); i++) {
            s.push_back(letters[i]);            // 处理
            backtracking(digits, index + 1);    // 递归，注意index+1，一下层要处理下一个数字了
            s.pop_back();                       // 回溯
        }
    }
    vector<string> letterCombinations(string digits) {
        s.clear();
        result.clear();
        if (digits.size() == 0) {
            return result;
        }
        backtracking(digits, 0);
        return result;
    }
};

int main(){
    Solution s1;
    vector<string> result1;
    result1 = s1.letterCombinations("23");
    
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
