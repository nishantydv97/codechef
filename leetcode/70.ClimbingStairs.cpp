/*

You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Example 1:

Input: 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
Example 2:

Input: 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step



*/

class Solution {
public:
    int climbStairs(int n) {
        vector<int> v;
        v.push_back(1);
        v.push_back(2);
        for(int i=2;i<n;i++){
            v.push_back(v[i-1]+v[i-2]);
        }
        return v[n-1];
        //if(n<=1)
        //    return 1;
        //return climbStairs(n-1) + climbStairs(n-2);
    }
};
