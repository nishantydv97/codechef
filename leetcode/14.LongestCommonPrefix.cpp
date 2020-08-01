/*

Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1:

Input: ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
Note:

All given inputs are in lowercase letters a-z.

*/


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0){
            return "";
        }
        if(strs.size()==1){
            return strs[0];
        }
        string s=strs[0];
        for(int i=1;i<strs.size();i++){
            string st="";
            for(int j=0;j<min(s.size(),strs[i].size());j++){
                if(s[j]==strs[i][j]){
                    st+=s[j];
                }else{
                    break;
                }
            }
            s=st;
        }
        return s;
    }
};
