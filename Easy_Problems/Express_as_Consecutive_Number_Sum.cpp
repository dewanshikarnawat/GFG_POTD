//Problem: Express as Consecutive Number Sum
//Topic: Mathematics / Number Theory
//Pattern: Easy

class Solution {
  public:
    bool isSumOfConsecutive(int n) {
        return (n & (n - 1)) != 0;
        
    }
};
